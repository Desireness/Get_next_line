/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:37:00 by rauizqui          #+#    #+#             */
/*   Updated: 2025/02/04 23:00:56 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char *stash;

char	*get_next_line(int fd)
{
	
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


