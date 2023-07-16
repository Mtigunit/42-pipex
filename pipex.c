/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:28:35 by mtigunit          #+#    #+#             */
/*   Updated: 2023/01/02 13:16:40 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(char **av, char **env, int *fd)
{
	int	infile;

	infile = open(av[1], O_RDONLY, 0777);
	if (infile == -1)
		error();
	dup2(infile, 0);
	close (infile);
	dup2(fd[1], 1);
	close (fd[0]);
	execute_cmd(av[2], env);
}

static void	parent_process(char **av, char **env, int *fd)
{
	int	outfile;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		error();
	dup2(outfile, 1);
	close (outfile);
	dup2(fd[0], 0);
	close (fd[1]);
	execute_cmd(av[3], env);
}

int	main(int ac, char **av, char *env[])
{
	int	fd[2];
	int	pid;

	if (!*env)
		return (ft_putstr_fd("Error: No Envirements!\n", 2), exit(1), 1);
	if (ac == 5)
	{
		if (pipe(fd) == -1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_process(av, env, fd);
		else if (pid != 0)
			parent_process(av, env, fd);
		wait(NULL);
	}
	else
		return (ft_putstr_fd("Error: Bad arguments!\n", 2), exit(1), 1);
	return (0);
}
