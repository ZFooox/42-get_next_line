/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocroon <jocroon@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:55:00 by jocroon           #+#    #+#             */
/*   Updated: 2024/11/24 23:15:33 by jocroon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const *str, int c)
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