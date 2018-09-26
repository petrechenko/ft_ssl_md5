/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:47:49 by apetrech          #+#    #+#             */
/*   Updated: 2018/06/22 19:04:16 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*tempdst;
	const unsigned char		*tempsrc;
	size_t					i;

	i = 0;
	tempdst = (unsigned char*)dst;
	tempsrc = (const unsigned char*)src;
	while (n > i)
	{
		tempdst[i] = tempsrc[i];
		if (tempdst[i] == (unsigned char)c)
			return ((void*)tempdst + i + 1);
		i++;
	}
	return (NULL);
}
