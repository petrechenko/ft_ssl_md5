/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 14:09:43 by apetrech          #+#    #+#             */
/*   Updated: 2018/06/21 12:58:18 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *temp;

	temp = s;
	while (*temp)
		temp++;
	if (c == 0)
		return ((char*)temp);
	while (temp > s)
	{
		temp--;
		if (((char)*temp) == c)
			return ((char*)temp);
	}
	return (0);
}
