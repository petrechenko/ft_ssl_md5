/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 12:39:04 by apetrech          #+#    #+#             */
/*   Updated: 2018/06/23 09:23:41 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		slen;
	size_t		i;
	char		*s1;
	const char	*s2;

	s1 = dst;
	s2 = src;
	i = size;
	while (*s1 != '\0' && i-- != 0)
		s1++;
	slen = s1 - dst;
	i = size - slen;
	if (i == 0)
		return (slen + ft_strlen(s2));
	while (*s2 != '\0')
	{
		if (i != 1)
		{
			*s1++ = *s2;
			i--;
		}
		s2++;
	}
	*s1 = '\0';
	return (slen + (s2 - src));
}
