/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 15:49:23 by apetrech          #+#    #+#             */
/*   Updated: 2018/06/23 19:26:02 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_words(char const *str, char c, unsigned int *ind)
{
	unsigned	i;
	unsigned	begin;
	char		*wrd;

	while (str[*ind] == c && str[*ind] != '\0')
		(*ind)++;
	begin = *ind;
	while (str[*ind] != c && str[*ind] != '\0')
		(*ind)++;
	wrd = ft_strnew(*ind - begin);
	if (!wrd)
		return (NULL);
	i = 0;
	while (begin < *ind)
	{
		wrd[i] = str[begin];
		begin++;
		i++;
	}
	wrd[i] = '\0';
	return (wrd);
}

char		**ft_strsplit(char const *s, char c)
{
	unsigned	i;
	unsigned	j;
	unsigned	wrd;
	char		**new;

	i = 0;
	wrd = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			wrd++;
		i++;
	}
	i = 0;
	j = 0;
	new = (char**)malloc(sizeof(char*) * (wrd + 1));
	if (!new)
		return (NULL);
	while (i < wrd)
		new[i++] = ft_words(s, c, &j);
	new[i] = 0;
	return (new);
}
