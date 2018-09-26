/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:08:48 by apetrech          #+#    #+#             */
/*   Updated: 2018/07/31 18:10:04 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_int_count(unsigned long long n)
{
	int					i;
	unsigned long long	t;

	i = 1;
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
	temp = ft_strnew(i + 1);
	start = temp;
	ft_bzero(temp, i + 1);
	insert = (izero ? '0' : ' ');
	if (i)
		while (i > format->len++)
			*(temp++) = insert;
	return (start);
}

static	char	*ft_uint_precision(t_format *format, long long n)
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
	prec = ft_strnew(dig + 1);
	ft_bzero(prec, dig + 1);
	start = prec;
	while (format->precision > num++)
		*(prec++) = '0';
	temp = ft_itoaf(n);
	if (n == 0 && format->dot)
		temp = ft_strsub("", 0, 0);
	ft_strcpy(prec, temp);
	format->len = ft_strlen(start);
	free(temp);
	return (start);
}

char			*ft_print_unbr(t_format *format, va_list *arg)
{
	char					*temp;
	char					*val;
	char					*insert;
	unsigned long long int	n;

	if (format->convert == 'U')
		n = (unsigned long long)va_arg(*arg, unsigned long long);
	else
		n = ft_uconvertflags(format, arg);
	format->len = ft_int_count(n);
	val = ft_uint_precision(format, n);
	insert = ft_width(format);
	if (format->flag.minus)
		temp = ft_strjoin(val, insert);
	else
		temp = ft_strjoin(insert, val);
	format->len = ft_strlen(temp);
	return (temp);
}
