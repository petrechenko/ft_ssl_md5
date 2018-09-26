/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_binary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:31:44 by apetrech          #+#    #+#             */
/*   Updated: 2018/07/31 17:34:20 by apetrech         ###   ########.fr       */
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

static char		*ft_width(t_format *format)
{
	char	*temp;
	char	*start;
	int		i;
	int		izero;
	char	insert;

	izero = 0;
	if (!format->dot && !format->flag.minus && format->flag.zero)
		izero = 1;
	i = format->width > format->len ? format->width : 0;
	temp = ft_strnew(i);
	start = temp;
	insert = (izero ? '0' : ' ');
	if (i)
		while (i > format->len++)
			*(temp++) = insert;
	return (start);
}

static	char	*ft_binary_precision(t_format *format, long long n)
{
	char	*temp;
	char	*prec;
	char	*start;
	int		dig;
	int		num;

	num = ft_int_count(n);
	if (format->precision > num)
		dig = format->precision;
	else
		dig = num;
	prec = ft_strnew(dig);
	start = prec;
	while (format->precision > num++)
		*(prec++) = '0';
	if (n < 0)
		n = -n;
	temp = ft_itoa_base_uns(n, 2, 'x');
	ft_strcpy(prec, temp);
	format->len = ft_strlen(start) + 2;
	ft_memdel((void*)&temp);
	return (start);
}

char			*ft_print_binary(t_format *format, va_list *arg)
{
	char				*temp;
	char				*val;
	char				*insert;
	char				*res;
	unsigned long long	n;

	n = ft_uconvertflags(format, arg);
	format->len = ft_int_count(n);
	val = ft_binary_precision(format, n);
	insert = ft_width(format);
	if (format->flag.minus)
		temp = ft_strjoin(val, insert);
	else
		temp = ft_strjoin(insert, val);
	res = temp;
	format->len = ft_strlen(res);
	return (res);
}
