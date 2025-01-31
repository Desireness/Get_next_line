/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsfd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 07:50:24 by rauizqui          #+#    #+#             */
/*   Updated: 2025/01/31 08:20:16 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdbool.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd;
	char buff[256];
	int	chars_read;

	fd = open("prueba.txt", O_RDONLY);
	while((chars_read = read(fd, buff, 5)))
	{
		buff[chars_read] = '\0';
		printf("buff->%s\n", buff);
	}
	
}
