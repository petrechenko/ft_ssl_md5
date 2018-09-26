/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 19:24:31 by apetrech          #+#    #+#             */
/*   Updated: 2018/06/22 16:22:22 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	n;
	char	*s1;
	char	*s2;

	if (!*str2)
		return ((void *)str1);
	while (len-- && *str1)
	{
		if (*str1 == *str2)
		{
			n = len;
			s1 = (void *)str1 + 1;
			s2 = (void *)str2 + 1;
			while (n-- && *s1 && *s2 && *s1 == *s2)
			{
				++s1;
				++s2;
			}
			if (!*s2)
				return ((void *)str1);
		}
		str1++;
	}
	return (NULL);
}
