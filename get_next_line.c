/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main
*/

#include "get_next_line.h"

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}

char *my_strcat(char *buffer, char *tmp)
{
    int i = 0;
    char *result = malloc(sizeof(char) * (my_strlen(buffer) + my_strlen(tmp)) + 1);

    while (buffer[i] != '\0') {
        result[i] = buffer[i];
        i++;
    }
    while (tmp[i - my_strlen(buffer)] != '\0') {
        result[i] = tmp[i - my_strlen(buffer)];
        i++;
    }
    result[i] = '\0';
    return (result);
}

char *create_buffer(int fd)
{
    char *buffer = malloc(sizeof(char) * 1);
    ssize_t size = READ_SIZE;
    char *tmp = malloc(sizeof(char) * READ_SIZE + 1);

    if (tmp == NULL)
        return NULL;
    buffer[0] = '\0';
    for (int i = 0; size == READ_SIZE; i++) {
        size = read(fd, tmp, READ_SIZE);
        tmp[size] = '\0';
        buffer = my_strcat(buffer, tmp);
    }
    return (buffer);
}

char *get_next_line(int fd)
{
    static char *buffer = NULL;
    char *line = NULL;
    int j = 0;
    static int count_buffer = 0;

    if (buffer == NULL) {
        buffer = create_buffer(fd);
        if (buffer == NULL)
            return NULL;
    }
    while (buffer[count_buffer + j] != '\n' && buffer[count_buffer + j] != '\0')
        j++;
    line = malloc(sizeof(char) * (j + 1));
    line[j] = '\0';
    j = 0;
    while (buffer[count_buffer] != '\n' && buffer[count_buffer] != '\0') {
        line[j] = buffer[count_buffer];
        j++;
        count_buffer++;
    }
    if (*line == 0)
        return NULL;
    count_buffer++;
    return (line);
}

int main(void)
{
    char *s = get_next_line(0);
    while (s) {
        printf("%s\n", s);
        free(s);
        s = get_next_line(0);
    }
    return (0);
}
