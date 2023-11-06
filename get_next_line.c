/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/30 18:12:29 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/06 16:15:22 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd)
{
	char		str_buffer[BUFFER_SIZE + 1];
	char		*to_free;
	static char	*rest;
	ssize_t		size;
	t_Tuple		to_return ;

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	size = 0;
	while (1)
	{
		if (!len_to_nl(rest))
		{
			size = read(fd, str_buffer, BUFFER_SIZE);
			if (size < 0)
			{
				if (rest)
				{
					free(rest);
					rest = NULL;
				}
				return (NULL);
			}
			if (size == 0)
			{
				if (rest)
				{
					to_return.line = ft_strdup(rest);
					free(rest);
					rest = NULL;
					return (to_return.line);
				}
				return (NULL);
			}
			str_buffer[size] = '\0';
			to_free = rest;
			rest = ft_strjoin(rest, str_buffer);
			if (!rest)
				return (NULL);
			if (to_free)
				free(to_free);
			if (!size && rest)
				return (to_return.line = ft_strdup(rest), free(rest),
					to_return.line);
		}
		else
		{
			to_return = dispenser(rest);
			if (rest)
				free(rest);
			rest = to_return.remain;
			return (to_return.line);
		}
	}
}

char	*ft_strjoin(char *rest, char *str_buffer)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;
	size_t	total;

	if (!rest)
	{
		if (str_buffer)
			return (new_str = ft_strdup(str_buffer), new_str);
		return (NULL);
	}
	len1 = ft_strlen(rest);
	len2 = ft_strlen(str_buffer);
	total = len1 + len2;
	if (!total)
		return (NULL);
	new_str = malloc(total + 1);
	if (!new_str)
		return (NULL);
	ft_memcpy(new_str, rest, len1);
	ft_memcpy((new_str + len1), str_buffer, len2);
	new_str[total] = '\0';
	return (new_str);
}
