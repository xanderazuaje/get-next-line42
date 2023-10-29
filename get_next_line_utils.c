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


void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*dest_aux;
	const char	*src_aux;

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

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*new;

	len = ft_strlen(s1);
	new = malloc(len + 1);
	if (new == 0)
		return (0);
	ft_memcpy(new, s1, len);
	new[len] = 0;
	return (new);
}

size_t	len_to_char(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub_str;
	size_t	new_len;
	size_t	i;

	if (start + len >= ft_strlen(s))
		new_len = ft_strlen(s) - start + 1;
	else
		new_len = len + 1;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	sub_str = malloc(new_len);
	if (!sub_str)
		return (0);
	i = 0;
	while (s[start + i] && i < len)
	{
		sub_str[i] = s[start + i];
		i++;
	}
	sub_str[i] = 0;
	return (sub_str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len1;
	size_t	len2;
	size_t	total;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	total = len1 + len2;
	new_str = malloc(total + 1);
	if (!new_str)
		return (0);
	ft_memcpy(new_str, s1, len1);
	ft_memcpy((new_str + len1), s2, len2);
	new_str[total] = 0;
	return (new_str);
}