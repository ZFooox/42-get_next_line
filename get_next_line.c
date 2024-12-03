/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocroon <jocroon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:36:37 by jocroon           #+#    #+#             */
/*   Updated: 2024/11/25 17:13:04 by jocroon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_save(int fd, char *save)
{
	char	*buffer;
	size_t	bytes_read; //todo: check ssize_t

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (!ft_strchr(save, '\n') && bytes_read != 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		save = ft_strjoin(save, buffer);
		if (!save)
		{
			free (buffer);
			return (NULL);
		}
	}
	free(buffer);
	return (save);
}

char	*extract_line(char **save)
{
	char	*line;
	char	*temp;
	size_t	len;

	if (!*save)
		return (NULL);
	len = 0;
	while ((*save)[len] && (*save)[len] != '\n')
		len++;
	if ((*save)[len] == '\n')
		len++;
	line = ft_substr(*save, 0, len);
	if (!line)
		return (NULL);
	temp = ft_strdup(*save + len);
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	free (*save);
	*save = temp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = extract_line(&save);
	return (line);
}
