/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:43:33 by apetrech          #+#    #+#             */
/*   Updated: 2018/07/31 18:46:31 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_width(t_format *format)
{
	int		n;
	char	*str;
	char	insert;

	insert = ' ';
	if (format->precision > 0 && format->precision < format->len)
		n = format->width - format->precision;
	else
		n = format->width - format->len;
	if (n < 0)
		n = 0;
	str = ft_strnew(n);
	ft_memset(str, insert, n);
	return (str);
}

static char	*ft_ws_precision(t_format *format, wchar_t *wchr)
{
	char	*str;
	char	*temp;
	int		i;

	i = 0;
	temp = ft_strnew(format->len);
	while (*((unsigned *)wchr) != L'\0')
	{
		temp[i] = *wchr;
		wchr++;
		i++;
	}
	if (format->precision > 0 && format->precision < format->len)
		str = ft_strsub(temp, 0, format->precision);
	else
		str = ft_strsub(temp, 0, format->len);
	free(temp);
	return (str);
}

size_t		ft_wstrlen(unsigned *str)
{
	size_t l;

	l = 0;
	while (*str != L'\0')
	{
		l++;
		++str;
	}
	return (l);
}

char		*ft_print_wstr(t_format *format, va_list *arg)
{
	char	*temp;
	char	*val;
	char	*insert;
	wchar_t	*wchr;

	wchr = va_arg(*arg, wchar_t*);
	format->len = (int)(ft_wstrlen((unsigned *)wchr));
	val = ft_ws_precision(format, wchr);
	insert = ft_width(format);
	if (format->flag.minus)
		temp = ft_strjoin(val, insert);
	else
		temp = ft_strjoin(insert, val);
	format->len = ft_strlen(temp);
	return (temp);
}
