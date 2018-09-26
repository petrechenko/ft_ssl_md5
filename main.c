/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:35:40 by apetrech          #+#    #+#             */
/*   Updated: 2018/09/25 10:05:29 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static void		file_no_rotat(t_ssl *ssl, char **argv)
{
	if (!ssl->q)
	{
		if (ft_strcmp(argv[1], "sha256") == 0)
			ft_printf("SHA256 (");
		else
			ft_printf("MD5 (");
		ft_printf("%s) = ", argv[ssl->pars]);
	}
	if (ft_strcmp(argv[1], "sha256") == 0)
		do_sha256(ssl->stdin, ssl);
	else
		do_md5(ssl->stdin, ssl);
	ft_putstr("\n");
}

static void		file_rotat(t_ssl *ssl, char **argv)
{
	if (bad_file(ssl, argv) == -1)
		return ;
	fake_gnl(&ssl->stdin, ssl->fd);
	if (!ssl->r)
		file_no_rotat(ssl, argv);
	else
	{
		if (ft_strcmp(argv[1], "sha256") == 0)
			do_sha256(ssl->stdin, ssl);
		else
			do_md5(ssl->stdin, ssl);
		if (!ssl->q)
			printf(" %s\n", argv[ssl->pars]);
		else
			ft_printf("\n");
	}
	free(ssl->stdin);
	close(ssl->fd);
	ssl->pars++;
}

static void		flags(t_ssl *ssl, int argc, char **argv)
{
	ssl->i = 2;
	ssl->p = 0;
	ssl->q = 0;
	ssl->r = 0;
	ssl->s = 0;
	while (ssl->i < argc)
	{
		if (ft_strcmp("-p", argv[ssl->i]) == 0)
			ssl->p = 1;
		else if (ft_strcmp("-q", argv[ssl->i]) == 0)
			ssl->q = 1;
		else if (ft_strcmp("-r", argv[ssl->i]) == 0)
			ssl->r = 1;
		else if (ft_strcmp("-s", argv[ssl->i]) == 0)
		{
			ssl->i++;
			ssl->s++;
		}
		else
			break ;
		ssl->i++;
	}
	ssl->n_file = ssl->i - argc;
}

static void		md5_sha_dec(t_ssl *ssl, char **argv, int argc)
{
	flags(ssl, argc, argv);
	if (ssl->p || (!ssl->n_file && !ssl->s))
	{
		fake_gnl(&ssl->stdin, 0);
		if (ssl->p)
			ft_printf("%s", ssl->stdin);
		if (ft_strcmp(argv[1], "sha256") == 0)
			do_sha256(ssl->stdin, ssl);
		else
			do_md5(ssl->stdin, ssl);
		ft_printf("\n");
		free(ssl->stdin);
	}
	ssl->pars = 2;
	while (ssl->pars < argc)
		if (print_s(ssl, argv, argc) == -1)
			break ;
	while (ssl->pars < argc)
		file_rotat(ssl, argv);
}

int				main(int argc, char **argv)
{
	t_ssl	ssl;

	if (argc == 1)
	{
		ft_printf("usage: ft_ssl command [command opts] [command args]\n");
		exit(-1);
	}
	if (ft_strcmp(argv[1], "md5") == 0 || ft_strcmp(argv[1], "sha256") == 0)
		md5_sha_dec(&ssl, argv, argc);
	else
	{
		ft_printf("ft_ssl: Error: '%s' is an invalid command.\n\nStandard \
commands:\n\nMessage Digest commands:\nmd5\nsha256\n\nCipher \
commands:\n", argv[1]);
		exit(-1);
	}
	return (0);
}
