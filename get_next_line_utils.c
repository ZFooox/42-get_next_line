/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocroon <jocroon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:55:00 by jocroon           #+#    #+#             */
/*   Updated: 2024/11/25 14:41:16 by jocroon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
//give the len of a string
size_t	ft_strlen(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
//find a character in a string
char	*ft_strchr(const char *str, int c)
{
	size_t	i;
	char	d;

	if (!str)
		return (NULL);
	i = 0;
	d = (char)c;
	while (str[i])
	{
		if (str[i] == d)
			return ((char *) &str[i]);
		i++;
	}
	if (str[i] == d)
		return ((char *) &str[i]);
	return (NULL);
}
//concatenate two string
char	*ft_strjoin(char const *str1, char const *str2)
{
	int		i;
	int		j;
	char	*result;

	if (!str1 && !str2)
		return (NULL);
	if (!str1)
		return (ft_strdup((char *) str2));
	if (!str2)
		return (ft_strdup((char *) str1));
	result = (char *)malloc((ft_strlen(str1) + ft_strlen(str2) + 1)
			* sizeof(char));
	if (!result)
		return (NULL);
	j = 0;
	i = 0;
	while (str1[i])
		result[j++] = str1[i++];
	i = 0;
	while (str2[i])
		result[j++] = str2[i++];
	result[j] = '\0';
	return (result);
}