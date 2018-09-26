/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:47:44 by apetrech          #+#    #+#             */
/*   Updated: 2018/07/31 17:51:08 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_int_count(unsigned long long n)
{
	int					i;
	unsigned long long	t;

	i = 0;
	t = n;
	while (t > 9)
	{
		t = t / 10;
		i++;
	}
	return (i);
}

static void		ft_add_ox(t_format *format,
		char **val, char **start, unsigned long long n)
{
	if (format->flag.hashtag && n != 0)
	{
		if (!format->dot && !format->flag.minus && format->flag.zero)
		{
			if (format->convert == 'x')
				*start = ft_strjoin(ft_strsub("0x", 0, 2), *start);
			else
				*start = ft_strjoin(ft_strsub("0X", 0, 2), *start);
		}
		else
		{
			if (format->convert == 'x')
				*val = ft_strjoin(ft_strsub("0x", 0, 2), *val);
			else
				*val = ft_strjoin(ft_strsub("0X", 0, 2), *val);
		}
	}
	return ;
}

static char		*ft_width(t_format *format)
{
	char	*temp;
	char	*start;
	int		i;
	char	insert;

	insert = ' ';
	if (format->flag.hashtag)
		format->len = format->len + 2;
	if (!format->dot && !format->flag.minus && format->flag.zero)
		insert = '0';
	i = format->width > format->len ? format->width : 0;
	temp = ft_strnew(i + 1);
	start = temp;
	if (i)
	{
		while (i > format->len++)
			*(temp++) = insert;
	}
	return (start);
}

static	char	*ft_hex_precision(t_format *format, unsigned long long n)
{
	char	*temp;
	char	*prec;
	char	*start;
	int		dig;
	int		num;

	num = ft_int_count(n);
	temp = ft_itoa_base_uns(n, 16, format->convert);
	num = ft_strlen(temp);
	if (format->precision > num)
		dig = format->precision;
	else
		dig = num;
	prec = ft_strnew(dig + 1);
	ft_bzero(prec, dig + 1);
	start = prec;
	while (format->precision > num++)
		*(prec++) = '0';
	if (n == 0 && format->dot)
		temp = ft_strsub("", 0, 0);
	ft_strcpy(prec, temp);
	ft_memdel((void**)&temp);
	format->len = ft_strlen(start);
	return (start);
}

char			*ft_print_hex(t_format *format, va_list *arg)
{
	char					*temp;
	char					*val;
	char					*insert;
	unsigned long long int	n;

	n = ft_uconvertflags(format, arg);
	format->len = ft_int_count(n);
	val = ft_hex_precision(format, n);
	insert = ft_width(format);
	ft_add_ox(format, &val, &insert, n);
	if (format->flag.minus)
		temp = ft_strjoin(val, insert);
	else
		temp = ft_strjoin(insert, val);
	format->len = ft_strlen(temp);
	return (temp);
}
