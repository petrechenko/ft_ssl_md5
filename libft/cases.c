/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:17:53 by apetrech          #+#    #+#             */
/*   Updated: 2018/07/31 17:19:25 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_dashtable(t_fun *f)
{
	f['x'] = &ft_print_hex;
	f['X'] = &ft_print_hex;
	f['s'] = &ft_print_str;
	f['S'] = &ft_print_wstr;
	f['i'] = &ft_print_nbr;
	f['d'] = &ft_print_nbr;
	f['D'] = &ft_print_nbr;
	f['o'] = &ft_print_octal;
	f['O'] = &ft_print_octal;
	f['c'] = &ft_print_char;
	f['C'] = &ft_print_char;
	f['p'] = &ft_print_point;
	f['b'] = &ft_print_binary;
	f['u'] = &ft_print_unbr;
	f['U'] = &ft_print_unbr;
}

t_fun		ft_function(char c)
{
	static t_fun	*f;
	int				i;

	if (!f)
	{
		f = ft_memalloc(sizeof(*f) * 256);
		if (f)
			ft_dashtable(f);
	}
	i = (int)c;
	return (f[i]);
}

int			ft_type(t_format *format, va_list *arg)
{
	char	*val;
	t_fun	f;
	int		temp;

	f = ft_function(format->convert);
	if (f)
		val = f(format, arg);
	else if (format->width != 0)
	{
		format->len = format->width;
		val = ft_strnew(format->width);
		ft_memset(val, ' ', format->width);
		temp = (format->flag.minus) ? 0 : format->width - 1;
		ft_memset(val + temp, format->convert, 1);
	}
	else
	{
		format->len = 1;
		val = ft_strnew(1);
		ft_memset(val, format->convert, 1);
	}
	temp = write(1, val, format->len);
	ft_memdel((void **)&val);
	return (temp);
}
