/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line copy.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:12:31 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/09 11:09:35 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_Tuple
{
	char	*line;
	char	*remain;
}			t_Tuple;
char		*get_next_line(int fd);
char		*ft_substr(char *s, unsigned int start, size_t len);
size_t		len_to_nl(char *s);
char		*ft_strdup(char *s);
char		*ft_strjoin(char *rest, char *str_buffer);
void		*ft_memcpy(void *dst, void *src, size_t n);
size_t		ft_strlen(char *s);
t_Tuple		dvd(char *s);

#endif
