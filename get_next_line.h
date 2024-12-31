/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocroon <jocroon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:38:00 by jocroon           #+#    #+#             */
/*   Updated: 2024/12/31 15:34:38 by jocroon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# if BUFFER_SIZE > 8192
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 19
# endif

/*main function*/
char	*get_next_line(int fd);
char	*read_and_save(int fd, char *save);
char	*extract_line(char **save);
char	*join_and_free(char *save, char *buffer);
char	*save_free_null(char **save);

/*utils function*/
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strjoin(char *str1, char const *str2);
char	*ft_strdup(const char *src);
char	*ft_substr(char const *str, unsigned int start, size_t len);

#endif
