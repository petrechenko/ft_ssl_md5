/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 13:53:22 by apetrech          #+#    #+#             */
/*   Updated: 2018/06/21 10:42:30 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char *tempsrc;
	char *tempdst;

	tempsrc = (char*)src;
	tempdst = (char*)dst;
	if (tempsrc < tempdst)
	{
		tempsrc = tempsrc + len - 1;
		tempdst = tempdst + len - 1;
		while (len > 0)
		{
			*tempdst-- = *tempsrc--;
			len--;
		}
	}
	else
	{
		while (len > 0)
		{
			*tempdst++ = *tempsrc++;
			len--;
		}
	}
	return (dst);
}
