/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:51:47 by apetrech          #+#    #+#             */
/*   Updated: 2018/07/31 17:58:46 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_int_count(long long n)
{
	int					i;
	unsigned long long	t;

	if (n == 0)
		return (0);
	t = n;
	if (n < 0)
		t = -t;
	i = 1;
	while (t > 9)
	{
		t /= 10;
		i++;
	}
	return (i);
}

static void		ft_flag(t_format *format, char **temp, long long n)
{
	if (!format->flag.plus && format->flag.space && n > 0)
		*((*temp)++) = ' ';
	else if (n < 0 && (format->dot || format->flag.minus ||
				!(format->flag.zero)))
		*((*temp)++) = '-';
	else if (format->flag.plus && (format->dot ||
				format->flag.minus || !(format->flag.zero)))
		*((*temp)++) = '+';
	return ;
}

static char		*ft_width(t_format *format, long long n)
{
	char	*temp;
	char	*start;
	int		i;
	char	insert;

	insert = ' ';
	if (!format->dot && !format->flag.minus && format->flag.zero)
	{
		insert = '0';
		if (n < 0 || format->flag.space)
			(format->len)++;
	}
	i = format->width > format->len ? format->width : 0;
	temp = ft_strnew(i + 1);
	start = temp;
	if (format->flag.space && !format->flag.plus && insert == '0')
		*(temp)++ = ' ';
	else if (n < 0 && insert == '0')
		*(temp++) = '-';
	else if (format->flag.plus && insert == '0' && format->len++)
		*(temp++) = '+';
	while (i > format->len++)
		*(temp++) = insert;
	return (start);
}

static char		*ft_int_precision(t_format *format, long long n)
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
	start = prec;
	ft_flag(format, &prec, n);
	while (format->precision > num++)
		*(prec++) = '0';
	if (n < 0)
		n = n * (-1);
	temp = ft_itoaf(n);
	if (n == 0 && format->dot)
		temp = ft_strsub("", 0, 0);
	ft_strcpy(prec, temp);
	free(temp);
	format->len = ft_strlen(start);
	return (start);
}

char			*ft_print_nbr(t_format *format, va_list *arg)
{
	char			*temp;
	char			*val;
	char			*insert;
	long long int	n;

	if (format->convert == 'D')
		n = (long long)va_arg(*arg, long long);
	else
		n = ft_convertflags(format, arg);
	format->len = ft_int_count(n);
	if (n < 0 || format->flag.plus || format->flag.space)
		(format->len)++;
	val = ft_int_precision(format, n);
	insert = ft_width(format, n);
	if (format->flag.minus)
		temp = ft_strjoin(val, insert);
	else
		temp = ft_strjoin(insert, val);
	format->len = ft_strlen(temp);
	return (temp);
}
