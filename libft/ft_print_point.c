/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:01:48 by apetrech          #+#    #+#             */
/*   Updated: 2018/07/31 18:04:51 by apetrech         ###   ########.fr       */
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

static void		ft_add_ox(t_format *format, char **val, char **start)
{
	if (!format->dot && !format->flag.minus && format->flag.zero)
		*start = ft_strjoin(ft_strsub("0x", 0, 2), *start);
	else
		*val = ft_strjoin(ft_strsub("0x", 0, 2), *val);
	return ;
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
	insert = (izero ? '0' : ' ');
	if (i)
		while (i > format->len++)
			*(temp++) = insert;
	return (start);
}

static	char	*ft_point_precision(t_format *format, long long n)
{
	char	*temp;
	char	*prec;
	char	*start;
	int		dig;
	int		num;

	num = ft_int_count(n);
	temp = ft_itoa_base_uns(n, 16, 'x');
	if (n == 0 && format->dot)
		temp = ft_strnew(0);
	num = ft_strlen(temp);
	if (format->precision > num)
		dig = format->precision;
	else
		dig = num;
	prec = ft_strnew(dig + 1);
	start = prec;
	while (format->precision > num++)
		*(prec++) = '0';
	if (n < 0)
		n = -n;
	ft_strcpy(prec, temp);
	format->len = ft_strlen(start) + 2;
	ft_memdel((void*)&temp);
	return (start);
}

char			*ft_print_point(t_format *format, va_list *arg)
{
	char					*temp;
	char					*val;
	char					*insert;
	unsigned long long int	n;
	void					*p;

	p = va_arg(*arg, void*);
	n = (unsigned long long)p;
	format->len = ft_int_count(n);
	val = ft_point_precision(format, n);
	insert = ft_width(format);
	ft_add_ox(format, &val, &insert);
	if (format->flag.minus)
		temp = ft_strjoin(val, insert);
	else
		temp = ft_strjoin(insert, val);
	format->len = ft_strlen(temp);
	return (temp);
}
