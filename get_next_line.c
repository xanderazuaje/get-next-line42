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


char *get_next_line(int fd) {
    char        str_buffer[BUFFER_SIZE + 1];
    static char *rest;
    ssize_t     size;
    Tuple       to_return;

    if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
        return (NULL);
    while (1) {
        if (!len_to_nl(rest))
        {
            size = read(fd, str_buffer, BUFFER_SIZE);
            if (size <= 0)
            {
                if (rest != NULL) free(rest);
                return (NULL);
            }
            str_buffer[size] = '\0';
            rest = ft_strjoin(rest, str_buffer);
            if (!rest) return (NULL);
        }
        else {
            to_return = dispenser(rest);
            if (rest != NULL) free(rest);
            rest = to_return.remain;
            return to_return.line;
        }

    }
}
