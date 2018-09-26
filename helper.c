/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:35:28 by apetrech          #+#    #+#             */
/*   Updated: 2018/09/24 20:24:02 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char		*add00(char *str)
{
	int i;

	i = ft_strlen(str);
	while (i < 8)
	{
		ft_printf("0");
		i++;
	}
	return (str);
}

uint32_t	revers_uint32(uint32_t n)
{
	return ((n >> 24) | ((n & 0xff0000) >> 8) |
		((n & 0xff00) << 8) | (n << 24));
}

uint64_t	revers_uint64(uint64_t n)
{
	return ((n & 0xff00000000000000) >> 56 \
			| (n & 0x00ff000000000000) >> 40 \
			| (n & 0x0000ff0000000000) >> 24 \
			| (n & 0x000000ff00000000) >> 8 \
			| (n & 0x00000000ff000000) << 8 \
			| (n & 0x0000000000ff0000) << 24 \
			| (n & 0x000000000000ff00) << 40 \
			| (n & 0x00000000000000ff) << 56);
}

void		fake_gnl(char **ptr, int fd)
{
	char	c[2];
	int		verif;
	char	*str;
	char	*tmp;

	c[1] = 0;
	verif = 42;
	str = ft_strdup("");
	while (verif > 0)
	{
		verif = read(fd, c, 1);
		if (verif == 0)
		{
			break ;
		}
		tmp = str;
		str = ft_strjoin(str, c);
		free(tmp);
	}
	ptr[0] = str;
}

int			bad_file(t_ssl *ssl, char **argv)
{
	if ((ssl->fd = open(argv[ssl->pars], O_RDWR)) < 0)
	{
		if (ft_strcmp(argv[1], "sha256") == 0)
			ft_printf("ft_ssl: sha256: ");
		if (ft_strcmp(argv[1], "sha224") == 0)
			ft_printf("ft_ssl: sha224: ");
		else
			ft_printf("ft_ssl: md5: ");
		ft_putstr(argv[ssl->pars]);
		ft_printf(": No such file or directory\n");
		ssl->pars++;
		return (-1);
	}
	return (0);
}
