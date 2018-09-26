/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:12:32 by apetrech          #+#    #+#             */
/*   Updated: 2018/07/31 18:28:36 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_delmem(t_format *array)
{
	if (!array)
		return ;
	ft_strdel(&(array->length));
	ft_memdel((void **)&array);
}

int		ft_printf(char *format, ...)
{
	size_t		i;
	size_t		count;
	t_format	*temp;
	va_list		arg;

	i = 0;
	count = 0;
	va_start(arg, format);
	while (format[i])
	{
		if (format[i] != '%')
		{
			write(1, (format + i), 1);
			count++;
		}
		else
		{
			temp = ft_flags((char *)format, &arg, &i);
			count = count + ft_type(temp, &arg);
			ft_delmem(temp);
		}
		i++;
	}
	va_end(arg);
	return (count);
}
