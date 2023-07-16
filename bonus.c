/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 20:53:16 by mtigunit          #+#    #+#             */
/*   Updated: 2023/01/03 10:03:51 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_processes(char *av, char **env)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		execute_cmd(av, env);
		exit(0);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
}

static void	read_heredoc(char *limiter, int *fd)
{
	char	*line;

	limiter = ft_strjoin(limiter, "\n");
	line = get_next_line(0);
	while (line)
	{
		if (!ft_memcmp(line, limiter, ft_strlen(limiter)))
		{
			free(limiter);
			free(line);
			exit(0);
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(0);
	}
	free(line);
	free(limiter);
}

static void	here_doc(char *limiter, int *outfile, char *to_open)
{
	int	pid;
	int	fd[2];

	*outfile = open(to_open, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		read_heredoc(limiter, fd);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		wait(NULL);
	}
}

int	main(int ac, char *av[], char *env[])
{
	int	i;
	int	infile;
	int	outfile;

	if (ac < 5 || !*env)
		return (ft_putstr_fd("Error: Bad arguments or \
		No Envirements!\n", 2), exit(1), 1);
	if (!ft_memcmp(av[1], "here_doc", 8))
	{
		i = 3;
		here_doc(av[2], &outfile, av[ac - 1]);
	}
	else
	{
		i = 2;
		infile = open(av[1], O_RDONLY, 0777);
		outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2(infile, 0);
		close(infile);
	}
	while (i < ac - 2)
		child_processes(av[i++], env);
	dup2(outfile, 1);
	close(outfile);
	execute_cmd(av[ac - 2], env);
	return (0);
}
