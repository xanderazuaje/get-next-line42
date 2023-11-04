/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:22:46 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/10/09 00:27:56 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#include <stdio.h>

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char		*dest_aux;
	char	*src_aux;

	if (!(dst == 0 && src == 0))
	{
		dest_aux = dst;
		src_aux = src;
		while (n--)
		{
			*dest_aux++ = *src_aux++;
		}
	}
	return (dst);
}

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

size_t	len_to_nl(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

Tuple dispenser(char *s){
    int i;
    Tuple to_return;

    i = 0;
    to_return.recent = NULL;
    to_return.remain = NULL;
    while(s[i])
    {
        if (s[i] == '\n' || s[i + 1] == '\0')
        {
            to_return.recent = ft_substr(s, 0, i + 1);
            to_return.remain = ft_substr(s, i + 1, ft_strlen(s) - i + 1);
            break;
        }

        i++;
    }
    return to_return;
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	i;

	sub_str = malloc(len + 1);
	if (!sub_str)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
	{
		sub_str[i] = s[i + start];
		i++;
	}
	sub_str[i] = '\0';
	return (sub_str);
}

char    *ft_strdup(char *s)
{
    char *new_str;
    int i;

    i = 0;
    new_str = (char *) malloc(ft_strlen(s) + 1);
    if(!new_str)
        return (NULL);
    while(s[i])
    {
        new_str[i] = s[i];
        i++;
    }
    new_str[i] = '\0';
    return (new_str);
}

char	*ft_strjoin(char *rest, char *str_buffer)
{
    char	*new_str;
    size_t	len1;
    size_t	len2;
    size_t	total;

    if (!rest)
    {
        return (new_str = ft_strdup(str_buffer), new_str);
    }
    len1 = ft_strlen(rest);
    len2 = ft_strlen(str_buffer);
    total = len1 + len2;
    new_str = malloc(total + 1);
    if (!new_str)
        return (NULL);
    ft_memcpy(new_str, rest, len1);
    ft_memcpy((new_str + len1), str_buffer, len2);
    new_str[total] = '\0';
    free(rest);
    return (new_str);
}
