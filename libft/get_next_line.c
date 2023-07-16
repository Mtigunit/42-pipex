/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtigunit <mtigunit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:32:42 by mtigunit          #+#    #+#             */
/*   Updated: 2022/12/16 17:46:40 by mtigunit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

static char	*ft_strchr_gnl(const char *s, int c)
{
	int	i;
	int	j;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	j = 0;
	while (j <= i)
	{
		if (s[j] == (char)c)
			return (&((char *)s)[j]);
		j++;
	}
	return (0);
}

static char	*extract_line(char **saved)
{
	char	*line;
	char	*tmp;
	int		i;

	i = 0;
	tmp = *saved;
	while (tmp[i] != '\n')
		i++;
	line = ft_substr(*saved, 0, i + 1);
	if (!tmp[i + 1])
	{
		free(*saved);
		*saved = NULL;
		return (line);
	}
	*saved = ft_strdup(&tmp[i + 1]);
	free(tmp);
	return (line);
}

static char	*line_no_nl(char **saved)
{
	char		*line;

	line = *saved;
	*saved = NULL;
	return (line);
}

static int	read_and_read(int fd, char **saved, char *buff)
{
	char		*tmp;
	int			readed;

	readed = 1;
	while (!ft_strchr_gnl(*saved, '\n') && readed)
	{
		readed = read(fd, buff, BUFFER_SIZE);
		if ((readed <= 0))
			return (readed);
		buff[readed] = '\0';
		tmp = *saved;
		*saved = ft_strjoin(tmp, buff);
		free(tmp);
	}
	return (readed);
}

char	*get_next_line(int fd)
{
	char		buff[BUFFER_SIZE + 1];
	static char	*saved;
	int			readed;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, buff, 0) < 0)
		return (NULL);
	readed = read_and_read(fd, &saved, buff);
	if ((readed <= 0))
		return (line_no_nl(&saved));
	if (ft_strchr_gnl(saved, '\n'))
		return (extract_line(&saved));
	return (NULL);
}
