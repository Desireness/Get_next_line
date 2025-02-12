/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:37:00 by rauizqui          #+#    #+#             */
/*   Updated: 2025/02/11 19:06:13 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


char *read_and_store(int fd, char **stash)
{
    char buff[BUFFER_SIZE + 1];
    int chars_read;
    char *temp;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    while ((chars_read = read(fd, buff, BUFFER_SIZE)) > 0)
    {
        buff[chars_read] = '\0';
        if (!(*stash))
            *stash = ft_strdup("");
        temp = ft_strjoin(*stash, buff);
        if (!temp)
            return (NULL);
        free(*stash);
        *stash = temp;
        if (ft_strchr(buff, '\n'))
            break;
    }
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
	static char *stash;
	char *line;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if(!read_and_store(fd, &stash))
		return (NULL);
	line = extract_line(&stash);
	return (line);
}


//int main()
//{
//	int fd = open("prueba.txt", 0_RDONLY);
//	char line;
//	
//	while((line = get_next_line))
//}

