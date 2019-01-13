/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:44:02 by apetrech          #+#    #+#             */
/*   Updated: 2018/06/23 15:17:48 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		count_digits(long long n)
{
	int i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static int		is_neg(long long n)
{
	if (n < 0)
		return (1);
	return (0);
}

static	int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

char			*ft_itoa(long long number)
{
	long long		n;
	int				len;
	char			*res;
	int				neg;

	n = number;
	neg = is_neg(n);
	if (n == -9223372036854775807)
		return (ft_strdup("-9223372036854775807"));
	if (neg)
		n = -n;
	len = neg + count_digits(n);
	res = ft_strnew(len);
	ft_bzero(res, len);
	if (!res)
		return (NULL);
	while (len--)
	{
		res[len] = ft_abs(n % 10) + '0';
		n /= 10;
	}
	if (neg)
		res[0] = '-';
	return (res);
}
