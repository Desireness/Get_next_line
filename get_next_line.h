/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 22:37:16 by rauizqui          #+#    #+#             */
/*   Updated: 2025/01/31 15:21:53 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 5
# endif

//nodos que uso en la linked list


//funciones usadas en el GNL

char	*get_next_line(int fd);

# include <stdio.h>
# include <unistd.h>
# include <stdbool.h>
# include <fcntl.h>

//funciones usadas en el GNL

char	*get_next_line(int fd);
char    *ft_strchr(const char *s, int c);


#endif
