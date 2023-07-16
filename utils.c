/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 01:12:06 by mtigunit          #+#    #+#             */
/*   Updated: 2023/01/03 13:04:12 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute_cmd(char *to_split, char **envt)
{
	char	**sp;
	char	*path;

	sp = ft_split(to_split, ' ');
	path = get_path(envt, sp[0]);
	if (execve(path, sp, envt) == -1)
	{
		ft_free(sp);
		free(path);
		error();
	}
	free(path);
	ft_free(sp);
}

char	*get_path(char **envt, char *cmd)
{
	char	*path_cmd;
	char	**sp;
	char	*tmp;
	int		i;

	i = 0;
	while (envt[i])
		if (!ft_memcmp(envt[i++], "PATH", 4))
			break ;
	sp = ft_split(&envt[--i][5], ':');
	i = 0;
	while (sp[i])
	{
		tmp = ft_strjoin("/", cmd);
		path_cmd = ft_strjoin(sp[i], tmp);
		if (!access(path_cmd, F_OK))
			return (ft_free(sp), free(tmp), path_cmd);
		free (path_cmd);
		free (tmp);
		i++;
	}
	ft_free(sp);
	return (ft_putendl_fd("command not found", 2), exit(1), NULL);
}

void	error(void)
{
	perror("Error");
	exit(1);
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}
