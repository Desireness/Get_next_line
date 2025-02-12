/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:37:36 by rauizqui          #+#    #+#             */
/*   Updated: 2025/02/11 19:05:47 by rauizqui         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	char	*new_str;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_str = malloc(sizeof(char) * (len_s1 + len_s2 + 1));
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, s1, len_s1);
	ft_memcpy(new_str + len_s1, s2, len_s2 + 1);
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
	if (strlen - start < len)
		len = strlen - start;
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (NULL);
	ft_memcpy(substr, s + start, len);
	return (substr);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

void	*ft_memcpy(void *dest, const void	*src, size_t n)
{
	size_t				i;
	const unsigned char	*s;
	unsigned char		*d;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	if (n <= 0 || dest == src)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

void	ft_bzero(void *s, size_t n)
{
	size_t		i;
	char		*c;

	c = (char *)s;
	i = 0;
	while (i < n)
	{
		c[i] = 0;
		i++;
	}
}


