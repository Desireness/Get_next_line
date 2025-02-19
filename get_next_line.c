/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:37:00 by rauizqui          #+#    #+#             */
/*   Updated: 2025/02/19 15:20:21 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0' && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	size_t			total_size;
	void			*ptr;
	unsigned char	*ptr_char;

	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	ptr_char = (unsigned char *)ptr;
	while (total_size--)
		*ptr_char++ = 0;
	return (ptr);
}

char	*read_and_store(int fd, char **stash, char *buffer)
{
	int		chars_read;
	char	*temp;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	chars_read = read(fd, buffer, BUFFER_SIZE);
	while (chars_read > 0)
	{
		buffer[chars_read] = '\0';
		if (!(*stash))
			*stash = ft_strdup("");
		temp = ft_strjoin(*stash, buffer);
		if (!temp)
			return (NULL);
		free(*stash);
		*stash = temp;
		if (ft_strchr(buffer, '\n'))
			break ;
		chars_read = read(fd, buffer, BUFFER_SIZE);
	}
	if (chars_read == -1)
		return (free(*stash), *stash = NULL, NULL);
	return (*stash);
}

char	*extract_line(char **stash)
{
	char	*pos;
	char	*line;
	char	*new_stash;

	if (!*stash || **stash == '\0')
		return (NULL);
	pos = ft_strchr(*stash, '\n');
	if (!pos)
	{
		line = ft_strdup(*stash);
		free(*stash);
		*stash = NULL;
		return (line);
	}
	line = ft_substr(*stash, 0, pos - *stash + 1);
	new_stash = ft_strdup(pos + 1);
	free(*stash);
	*stash = new_stash;
	if (!**stash)
	{
		free(*stash);
		*stash = NULL;
	}
	return (line);
}

//char *get_stash(char *buffer)
//{
//	char *pos;
//	char *new_stash;
//
//	pos = ft_strchr(buffer. '\n');
//	if(!pos)
//		return (NULL);
//	new_stash = ft_strdup(pos + 1);
//	return (new_stash);
//}

char	*get_next_line(int fd)
{
	static char	*stash;
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer || !read_and_store(fd, &stash, buffer))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	line = extract_line(&stash);
	if (!line)
	{
		free(stash);
		free(buffer);
		stash = NULL;
		buffer = NULL;
	}
	return (line);
}

/*int main()
{
    int fd = open("prueba.txt", O_RDONLY);
    char *line;

    if (fd < 0)
       return (1);
   while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}*/
