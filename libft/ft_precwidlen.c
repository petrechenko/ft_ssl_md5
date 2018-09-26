/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_precwidlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 17:27:37 by apetrech          #+#    #+#             */
/*   Updated: 2018/07/31 18:49:29 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_flag_width(char *format, size_t *i,
		va_list *arg, t_format *star)
{
	int		temp;
	size_t	j;

	j = *i;
	while (ft_isdigit(format[*i]))
		(*i)++;
	if (format[(*i)] == '*')
	{
		temp = va_arg(*arg, int);
		if (temp < 0)
		{
			temp *= -1;
			star->flag.minus = 1;
		}
		(*i)++;
	}
	else
		temp = ft_atoi(format + j);
	return (temp);
}

int					ft_precision(char *format, size_t *i,
		va_list *arg, t_format *conv)
{
	int temp;
	int j;

	temp = 0;
	if (format[(*i)] == '.')
	{
		conv->dot = 1;
		(*i)++;
		j = *i;
		while (ft_isdigit(format[*i]))
			(*i)++;
		if (format[(*i)] == '*')
		{
			temp = va_arg(*arg, int);
			if (temp < 0)
			{
				temp *= -1;
				conv->flag.minus = 1;
			}
			(*i)++;
		}
		else
			temp = ft_atoi(format + j);
	}
	return (temp);
}

char				*ft_length(char *format, size_t *i)
{
	char	*temp;

	temp = ft_strnew(2);
	if (format[*i] == 'j' || format[*i] == 'z' || format[*i] == 't' ||
			format[*i] == 'L' || format[*i] == 'h' || format[*i] == 'l')
	{
		*temp = format[(*i)++];
		if (format[*i] == 'l' || format[*i] == 'h')
		{
			*(++temp) = format[(*i)];
			(*i)++;
			temp--;
		}
	}
	return (temp);
}

t_format			*ft_flags(char *format, va_list *arg, size_t *i)
{
	t_format *temp;

	temp = malloc(sizeof(t_format));
	ft_bzero(temp, sizeof(t_format));
	temp->flag = ft_firstflags(format, i);
	temp->width = ft_flag_width(format, i, arg, temp);
	temp->precision = ft_precision(format, i, arg, temp);
	temp->length = ft_length(format, i);
	temp->convert = format[(*i)];
	return (temp);
}
