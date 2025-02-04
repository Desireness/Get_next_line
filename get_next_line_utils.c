/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:37:36 by rauizqui          #+#    #+#             */
/*   Updated: 2025/02/04 22:39:07 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while(*s != '\0' && *s != (char)c)
		s++;
	if(*s == (char)c)
		return ((char *)s);
	return (NULL);
}

size_t  ft_strlen(const char *s)
{
        size_t  size;

        size = 0;
        while (s[size] != '\0')
                size++;
        return (size);
}


char	*ft_strdup(const char *s)
{
	char	*new;
	size_t	i;

	i = 0;
	new = (malloc(sizeof(char) * ft_strlen(s) + 1));
	if (!new)
		return (NULL);
	while (*s)
		new[i++] = *s++;
	new[i] = '\0';
	return (new);
}

