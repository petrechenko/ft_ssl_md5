/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:52:08 by apetrech          #+#    #+#             */
/*   Updated: 2018/06/21 19:16:38 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tempdst;
	const char	*tempsrc;

	tempdst = dst;
	tempsrc = src;
	while (n > 0)
	{
		*tempdst++ = *tempsrc++;
		n--;
	}
	return (dst);
}
