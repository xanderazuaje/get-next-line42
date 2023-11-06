/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xazuaje- <xazuaje-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 21:22:46 by xazuaje-          #+#    #+#             */
/*   Updated: 2023/11/06 16:14:21 by xazuaje-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_memcpy(void *dst, void *src, size_t n)
{
	char	*dest_aux;
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

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

t_Tuple	dispenser(char *s)
{
	size_t	nl_pos;
	size_t	len;
	t_Tuple	to_return ;

	nl_pos = len_to_nl(s);
	len = ft_strlen(s);
	to_return.line = NULL;
	to_return.remain = NULL;
	if (nl_pos)
	{
		to_return.line = ft_substr(s, 0, nl_pos);
		if (!(len == nl_pos))
			to_return.remain = ft_substr(s, nl_pos, len - nl_pos);
	}
	else
		to_return.remain = ft_strdup(s);
	return (to_return);
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

char	*ft_strdup(char *s)
{
	char	*new_str;
	int		i;

	i = 0;
	new_str = (char *)malloc(ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	while (s[i])
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

