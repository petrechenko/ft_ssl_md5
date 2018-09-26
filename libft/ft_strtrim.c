/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:48:37 by apetrech          #+#    #+#             */
/*   Updated: 2018/06/23 19:17:16 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*new;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] <= ' ' && s[i] != '\0')
		i++;
	start = i;
	while (s[i] != '\0')
		i++;
	while (s[i] <= ' ' && i > start)
		i--;
	end = i;
	new = ft_strnew(end - start + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (start++ <= end)
		new[i++] = s[start - 1];
	new[i] = '\0';
	return (new);
}
