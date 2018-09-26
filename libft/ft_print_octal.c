/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_octal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:59:32 by apetrech          #+#    #+#             */
/*   Updated: 2018/07/31 18:01:12 by apetrech         ###   ########.fr       */
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
	if (format->flag.hashtag)
	{
		if (!format->dot && !format->flag.minus && format->flag.zero)
			*start = ft_strjoin(ft_strsub("0", 0, 1), *start);
		else
			*val = ft_strjoin(ft_strsub("0", 0, 1), *val);
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
		format->len = format->len + 1;
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

static	char	*ft_octal_precision(t_format *format, long long n)
{
	char	*temp;
	char	*prec;
	char	*start;
	int		dig;
	int		num;

	temp = ft_itoa_base_uns(n, 8, 'x');
	if (n == 0 && (format->dot || format->flag.hashtag))
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
	ft_strcpy(prec, temp);
	format->len = ft_strlen(start);
	ft_memdel((void **)&temp);
	return (start);
}

char			*ft_print_octal(t_format *format, va_list *arg)
{
	char					*temp;
	char					*val;
	char					*insert;
	unsigned long long int	n;

	if (format->convert == '0')
		n = (unsigned long long)va_arg(*arg, unsigned long long);
	else
		n = ft_uconvertflags(format, arg);
	format->len = ft_int_count(n);
	val = ft_octal_precision(format, n);
	insert = ft_width(format);
	ft_add_ox(format, &val, &insert);
	if (format->flag.minus)
		temp = ft_strjoin(val, insert);
	else
		temp = ft_strjoin(insert, val);
	format->len = ft_strlen(temp);
	return (temp);
}
