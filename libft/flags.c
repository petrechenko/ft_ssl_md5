/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:23:06 by apetrech          #+#    #+#             */
/*   Updated: 2018/07/31 17:28:31 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_flag				ft_firstflags(char *format, size_t *i)
{
	t_flag temp;

	ft_bzero(&temp, sizeof(t_flag));
	(*i)++;
	while (format[*i] == '+' || format[*i] == '-' ||
			format[*i] == '#' || format[*i] == ' ' || format[*i] == '0')
	{
		if (format[*i] == '-')
			temp.minus = 1;
		if (format[*i] == '+')
			temp.plus = 1;
		if (format[*i] == ' ')
			temp.space = 1;
		if (format[*i] == '0')
			temp.zero = 1;
		if (format[*i] == '#')
			temp.hashtag = 1;
		(*i)++;
	}
	return (temp);
}

long long			ft_convertflags(t_format *format, va_list *arg)
{
	long long n;

	n = 0;
	if (!(ft_strcmp(format->length, "")))
		n = va_arg(*arg, int);
	else if (!(ft_strcmp(format->length, "hh")))
		n = (char)va_arg(*arg, int);
	else if (!(ft_strcmp(format->length, "h")))
		n = (short)va_arg(*arg, int);
	else if (!(ft_strcmp(format->length, "l")))
		n = va_arg(*arg, long);
	else if (!(ft_strcmp(format->length, "ll")))
		n = va_arg(*arg, long long);
	else if (!(ft_strcmp(format->length, "j")))
		n = va_arg(*arg, intmax_t);
	else if (!(ft_strcmp(format->length, "z")))
		n = va_arg(*arg, size_t);
	return (n);
}

unsigned long long	ft_uconvertflags(t_format *format, va_list *arg)
{
	unsigned long long n;

	n = 0;
	if (!(ft_strcmp(format->length, "")))
		n = va_arg(*arg, unsigned int);
	else if (!(ft_strcmp(format->length, "hh")))
		n = (unsigned char)va_arg(*arg, unsigned int);
	else if (!(ft_strcmp(format->length, "h")))
		n = (unsigned short)va_arg(*arg, unsigned int);
	else if (!(ft_strcmp(format->length, "l")))
		n = va_arg(*arg, unsigned long);
	else if (!(ft_strcmp(format->length, "ll")))
		n = va_arg(*arg, unsigned long long);
	else if (!(ft_strcmp(format->length, "j")))
		n = va_arg(*arg, uintmax_t);
	else if (!(ft_strcmp(format->length, "z")))
		n = va_arg(*arg, size_t);
	return (n);
}
