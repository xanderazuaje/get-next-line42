/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:12:31 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/10/08 23:51:42 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct Tuple_t {
    char *recent;
    char *remain;
} Tuple;
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
size_t	len_to_nl(char *s);
size_t	ft_strlen(char *s);
char	*ft_strjoin(char *rest, char *str_buffer);
Tuple dispenser(char *s);

#endif
