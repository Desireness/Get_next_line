/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:37:00 by rauizqui          #+#    #+#             */
/*   Updated: 2025/02/06 14:08:48 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *stash;

char *get_stash(char *buffer)
{
	char *pos;
	char *new_stash;

	pos = ft_strchr(buffer. '\n');
	if(!pos)
		return (NULL);
	new_stash = ft_strdup(pos + 1);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char *stash;
	char buff[BUFFER_SIZE + 1];
	char *line;
	int chars_read;

	if(fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while((chars_read  =read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[chars_read] = '\0';	
	}
	return (line);	
}

int main()
{
        int fd;
        char buff[BUFFER_SIZE + 1];
	char *pos;
        int     chars_read;

        fd = open("prueba2.txt", O_RDONLY);
	if(fd < 0)
		return (1);
        while((chars_read = read(fd, buff, 5)) >0)
        {
                buff[chars_read] = '\0';
		pos = ft_strchr(buff, '\n');
		if (pos)
		{
			*pos = '\0';
			printf("buff->%s\n", buff);
			free(stash);
			stash = ft_strdup(pos + 1);
			printf("stash->%s\n", stash);
			break;	
		}
		else
		{
                	printf("Buffer[5]:%s\n", buff);
		}
        }      
	close(fd);
	return (0); 
}


