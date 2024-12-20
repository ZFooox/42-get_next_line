/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocroon <jocroon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:36:37 by jocroon           #+#    #+#             */
/*   Updated: 2024/12/20 11:15:12 by jocroon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_and_free(char *save, char *buffer)
{
	char	*temp;

	if (!buffer)
		return (save);
	if (!save)
		return (ft_strdup(buffer));
	temp = ft_strjoin(save, buffer);
	free(save);
	save = NULL;
	return (temp);
}

char	*save_free_null(char **save)
{
	free(*save);
	*save = NULL;
	return (NULL);
}

char	*read_and_save(int fd, char *save)
{
	char	*buffer;
	ssize_t	bytes_read;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		free (save);
		return (NULL);
	}
	bytes_read = 1;
	while (!ft_strchr(save, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free (save);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		save = join_and_free(save, buffer);
	}
	free(buffer);
	return (save);
}

char	*extract_line(char **save)
{
	char	*line;
	char	*temp;
	size_t	len;

	if (!*save || !**save)
		return (save_free_null(save));
	len = 0;
	while ((*save)[len] && (*save)[len] != '\n')
		len++;
	if ((*save)[len] == '\n')
		len++;
	line = ft_substr(*save, 0, len);
	if (!line)
		return (save_free_null(save));
	if ((*save)[len] != '\0')
		temp = ft_strdup(*save + len);
	else
		temp = NULL;
	free(*save);
	*save = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	save = read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = extract_line(&save);
	return (line);
}
