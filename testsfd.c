/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testsfd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 07:50:24 by rauizqui          #+#    #+#             */
/*   Updated: 2025/01/31 13:34:22 by rauizqui         ###   ########.fr       */
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

//funcion para hacer que lea el archivo .txt con un buffer de 5

/*int main()
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

//funcion  usando fgets

int main()
{
	FILE *file_ptr;

	char ch;

	file_ptr = fopen("prueba.txt", "r");
	
	if(file_ptr == NULL)
	{
		printf("file cant't be opened\n");
		return EXIT_FAILURE;
	}
	printf("Content of the file are:\n");

	while((ch = fgetc(file_ptr))!= EOF)
	{
		printf("%c", ch);
	}
	fclose(file_ptr);
	return (0);


}*/

//Primer uso de variables estaticas

void f();

int main()
{
	f();
	f();
	f();
	return (0);
}

void f()
{
	static int calls = 0;
	calls++;
	printf("calls:%d\n", calls);
}

















