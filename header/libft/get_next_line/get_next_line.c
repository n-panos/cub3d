/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nacho <nacho@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 09:57:27 by ipanos-o          #+#    #+#             */
/*   Updated: 2023/12/06 11:49:24 by nacho            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

static char	*gnl_str_cut(char *str)
{
	char	*new;
	size_t	i;
	size_t	len;

	i = 0;
	len = gnl_strlen(str);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (free(str), NULL);
	if (str == 0)
		return (NULL);
	while ((str[i]) && str[i] != '\n')
	{
		new[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
		new[i++] = '\n';
	new[i] = '\0';
	return (free(str), new);
}

static char	*read_to_stash(int fd, char *str)
{
	char	*buffer;
	int		cursor;

	cursor = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	while (!gnl_strchr(str, '\n') && cursor != 0)
	{
		cursor = read(fd, buffer, BUFFER_SIZE);
		if (cursor == -1)
			return (free(buffer), free(str), NULL);
		buffer[cursor] = 0;
		str = gnl_strjoin(str, buffer);
	}
	return (free(buffer), str);
}

static char	*stash_to_line(char *str)
{
	char	*line;
	size_t	len;

	len = gnl_strlen(str);
	line = gnl_calloc (sizeof(char), len + 1);
	if (!line)
		return (NULL);
	line = gnl_strjoin(line, str);
	if (line[0] == 0)
		return (free(line), NULL);
	return (gnl_str_cut(line));
}

static char	*update_stash(char *str)
{
	int		i;
	int		j;

	i = gnl_strchr(str, '\n');
	if (!gnl_strchr(str, '\n') && str[i] != '\n')
		return (free(str), NULL);
	j = 0;
	while (str[i + 1])
	{
		str[j++] = str[i + 1];
		i++;
	}
	while (str[j] != '\0')
	{
		str[j] = '\0';
		j++;
	}
	return (str);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if ((fd < 0) || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_to_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = stash_to_line(stash);
	stash = update_stash(stash);
	return (line);
}
