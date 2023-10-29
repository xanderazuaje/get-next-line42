/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:12:29 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/10/09 00:25:05 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_substr_from_rest(char **rest, size_t newline)
{
    char    *to_return;

    to_return = ft_substr(*rest, 0, newline);
    if (!to_return)
        return (NULL);
    *rest = ft_substr(*rest, newline + 1, ft_strlen(*rest) - newline);
    if (!rest)
    {
        free(to_return);
        return (NULL);
    }
    return (to_return);

}

void alloc_buffer(char **str_buffer, int fd)
{
    *str_buffer = (char *)malloc(BUFFER_SIZE + 1);
    if (!*str_buffer)
        return;
    read(fd, *str_buffer, BUFFER_SIZE);
    *str_buffer[BUFFER_SIZE] = '\0';
}

char *get_next_line(int fd) {
    char        *str_buffer;
    char        *addr_to_free;
    size_t      newline;
    static char *rest;

    if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
        return (NULL);
    while (1) {
        if (rest) {
            newline = len_to_char(rest, '\n');
            addr_to_free = rest;
            if (newline)
            {
                return get_substr_from_rest(&rest, newline);
            }
            alloc_buffer(&str_buffer, fd);
            if(!str_buffer)
                return (NULL);
            addr_to_free = rest;
            rest = ft_strjoin(rest, str_buffer);
            free(addr_to_free);
            if (!rest){
                rest = str_buffer;
                return (NULL);
            }
            free(str_buffer);
        } else {
            alloc_buffer(&str_buffer, fd);
            if (!str_buffer)
                return(NULL);
            rest = str_buffer;
        }
    }
}

int main(void) {
    int fd;

    fd = open("quijote.txt", O_RDONLY);

    printf("%s\n\n", get_next_line(fd));
    printf("%s\n\n", get_next_line(fd));
    printf("%s\n\n", get_next_line(fd));
    printf("%s\n\n", get_next_line(fd));
    printf("%s\n\n", get_next_line(fd));
    printf("%s\n\n", get_next_line(fd));
    printf("%s\n\n", get_next_line(fd));
}
