/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:34:58 by apetrech          #+#    #+#             */
/*   Updated: 2018/09/24 14:35:06 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void		no_rotation(t_ssl *ssl, char **argv)
{
	if (!ssl->q)
	{
		if (ft_strcmp(argv[1], "sha256") == 0)
			ft_printf("SHA256 (\"");
		else
			ft_printf("MD5 (\"");
		ft_putstr(argv[ssl->pars]);
		ft_printf("\") = ");
	}
	if (ft_strcmp(argv[1], "sha256") == 0)
		do_sha256(argv[ssl->pars], ssl);
	else
		do_md5(argv[ssl->pars], ssl);
	ft_printf("\n");
}

void		rotate_s(t_ssl *ssl, char **argv)
{
	if (ft_strcmp(argv[1], "sha256") == 0)
		do_sha256(argv[ssl->pars], ssl);
	else
	{
		ft_printf("MD5 (\"%s\") = ", argv[ssl->pars]);
		do_md5(argv[ssl->pars], ssl);
	}
	if (!ssl->q)
		ft_printf(" \"%s\"\n", argv[ssl->pars]);
	else
		ft_printf("\n");
}

int			print_s(t_ssl *ssl, char **argv, int argc)
{
	if (ft_strcmp("-p", argv[ssl->pars]) == 0)
		ssl->p = 1;
	else if (ft_strcmp("-q", argv[ssl->pars]) == 0)
		ssl->q = 1;
	else if (ft_strcmp("-r", argv[ssl->pars]) == 0)
		ssl->r = 1;
	else if (ft_strcmp("-s", argv[ssl->pars]) == 0)
	{
		ssl->pars++;
		if (ssl->pars < argc)
		{
			if (!ssl->r)
				no_rotation(ssl, argv);
			else
				rotate_s(ssl, argv);
		}
	}
	else
		return (-1);
	ssl->pars++;
	return (0);
}
