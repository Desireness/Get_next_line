/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester_mains_gnl.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rauizqui <rauizqui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 00:39:35 by rauizqui          #+#    #+#             */
/*   Updated: 2025/02/23 13:27:08 by rauizqui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//1. Lectura de una línea normal

//Un archivo con una sola línea de texto.

int main()
{
    int fd = open("single_line.txt", O_RDONLY);
    char *line;

    if (fd < 0) return (1);

    while ((line = get_next_line(fd))) {
        printf("Line: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}

//2. Archivo con múltiples líneas

//Un archivo con varias líneas de texto.
int main() {
    int fd = open("multi_lines.txt", O_RDONLY);
    char *line;

    if (fd < 0) return (1);

    while ((line = get_next_line(fd))) {
        printf("Line: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}

//3. Archivo vacío

//Un archivo vacío.

int main() {
    int fd = open("empty_file.txt", O_RDONLY);
    char *line;

    if (fd < 0) return (1);

    while ((line = get_next_line(fd))) {
        printf("Line: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}

//4. Lectura de un archivo que termina con un salto de línea

//Archivo con una línea terminada por un salto de línea.

int main() {
    int fd = open("line_with_newline.txt", O_RDONLY);
    char *line;

    if (fd < 0) return (1);

    while ((line = get_next_line(fd))) {
        printf("Line: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}

//5. Lectura de un archivo sin salto de línea final

//Archivo con una línea sin salto de línea al final.
int main() {
    int fd = open("line_without_newline.txt", O_RDONLY);
    char *line;

    if (fd < 0) return (1);

    while ((line = get_next_line(fd))) {
        printf("Line: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}

//6. Leer con un archivo que tiene líneas de tamaño variable

//archivo con varias líneas de tamaños variables.

int main() {
    int fd = open("variable_size_lines.txt", O_RDONLY);
    char *line;

    if (fd < 0) return (1);

    while ((line = get_next_line(fd))) {
        printf("Line: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}

//7. Leer un archivo grande (de varios MB)

//Archivo grande para verificar el rendimiento.
int main() {
    int fd = open("large_file.txt", O_RDONLY);
    char *line;

    if (fd < 0) return (1);

    while ((line = get_next_line(fd))) {
        free(line); // No hace falta imprimir el contenido
    }
    close(fd);
    return (0);
}

//8. Leer un archivo con caracteres especiales

//Archivo que contiene caracteres no ASCII o especiales, como \t, \n, \r, etc.

int main() {
    int fd = open("special_chars.txt", O_RDONLY);
    char *line;

    if (fd < 0) return (1);

    while ((line = get_next_line(fd))) {
        printf("Line: %s", line); // Deberías ver los caracteres correctamente impresos
        free(line);
    }
    close(fd);
    return (0);
}

//9. Leer un archivo con múltiples saltos de línea consecutivos

//Archivo con líneas vacías entre texto.

int main() {
    int fd = open("multiple_empty_lines.txt", O_RDONLY);
    char *line;

    if (fd < 0) return (1);

    while ((line = get_next_line(fd))) {
        printf("Line: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}

//10. Leer desde stdin

//Para probar get_next_line con entrada estándar 
//(puedes escribir directamente en la consola).

int main() {
    char *line;

    while ((line = get_next_line(0))) { // 0 es el descriptor de archivo para stdin
        printf("Line: %s", line);
        free(line);
    }
    return (0);
}


//11. Leer un archivo binario (para ver si maneja bien caracteres no imprimibles)

//Archivo binario, por ejemplo, una imagen o cualquier archivo no de texto.

int main() {
    int fd = open("binary_file.bin", O_RDONLY);
    char *line;

    if (fd < 0) return (1);

    while ((line = get_next_line(fd))) {
        // Esto puede imprimir caracteres no legibles, pero debería funcionar.
        free(line);
    }
    close(fd);
    return (0);
}

//12. Probar con archivos con diferentes tamaños de buffer

#define BUFFER_SIZE 16

int main() {
    int fd = open("multi_lines.txt", O_RDONLY);
    char *line;

    if (fd < 0) return (1);

    while ((line = get_next_line(fd))) {
        printf("Line: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}

//13. Probar con archivo muy pequeño

//Archivo con solo un carácter.

int main() {
    int fd = open("small_file.txt", O_RDONLY);
    char *line;

    if (fd < 0) return (1);

    while ((line = get_next_line(fd))) {
        printf("Line: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}


//14. Probar errores de apertura de archivo

//Archivo que no existe o cuyo descriptor de archivo es inválido.

int main() {
    int fd = open("non_existent_file.txt", O_RDONLY);
    char *line;

    if (fd < 0) {
        printf("Failed to open file.\n");
        return (1);
    }

    while ((line = get_next_line(fd))) {
        printf("Line: %s", line);
        free(line);
    }
    close(fd);
    return (0);
}

























