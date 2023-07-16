/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 09:28:51 by mtigunit          #+#    #+#             */
/*   Updated: 2023/01/01 17:03:53 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

char	*get_path(char **envt, char *cmd);
void	ft_free(char **str);
void	error(void);
void	execute_cmd(char *to_split, char **envt);

#endif