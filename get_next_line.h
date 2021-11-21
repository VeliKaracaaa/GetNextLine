/*
** EPITECH PROJECT, 2020
** my.h
** File description:
** get_next_line
*/

#ifndef _GET_NEXT_LINE_H_
#define _GET_NEXT_LINE_H_

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int my_strlen(char *str);
char *my_strcat(char *buffer, char *tmp);
char *create_buffer(int fd);
char *get_next_line(int fd);

#endif /* !GET_NEXT_LINE_H_ */

#ifndef READ_SIZE
#define READ_SIZE (1000)
#endif