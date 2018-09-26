/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:35:16 by apetrech          #+#    #+#             */
/*   Updated: 2018/09/24 20:32:36 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
# define FT_SSL_H

# include <stdlib.h>
# include <string.h>
# include <stdint.h>
# include <unistd.h>
# include "libft/libft.h"

# define F1(x, y, z) ((x & y) | (~x & z))
# define F2(x, y, z) ((x & z) | (y & ~z))
# define F3(x, y, z) (x ^ y ^ z)
# define F4(x, y, z) (y ^ (x | ~z))

# define RROT(X, N) ((X >> N) | (X << (32 - N)))
# define LROT(X, N) ((X << N) | (X >> (32 - N)))

# define S1(X) ((RROT(X, 6)) ^ (RROT(X, 11)) ^ (RROT(X, 25)))
# define CH(x, y, z) ((x & y) ^ (~ x & z))
# define S0(X) ((RROT(X, 2)) ^ (RROT(X, 13)) ^ (RROT(X, 22)))
# define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))

typedef struct		s_ssl
{
	int				len;
	uint32_t		h0;
	uint32_t		h1;
	uint32_t		h2;
	uint32_t		h3;
	uint32_t		h4;
	uint32_t		h5;
	uint32_t		h6;
	uint32_t		h7;
	uint32_t		a;
	uint32_t		b;
	uint32_t		c;
	uint32_t		d;
	uint32_t		e;
	uint32_t		f;
	uint32_t		g;
	uint32_t		h;
	uint32_t		p;
	uint32_t		q;
	uint32_t		r;
	uint32_t		s;
	uint32_t		s0;
	uint32_t		s1;
	uint32_t		s2;
	uint32_t		s3;
	uint32_t		s4;
	uint32_t		s5;
	uint32_t		*t;
	char			*bytes;
	uint32_t		*bytes_32;
	int				i;
	uint32_t		tmp;
	int				str;
	char			*stdin;
	int				n_file;
	int				pars;
	int				fd;
}					t_ssl;

int					md5(unsigned char *init_msg, int len, t_ssl *ssl);

int					sha256(char *init_msg, int len, t_ssl *ssl);

void				do_md5(char *std, t_ssl *ssl);
void				do_sha256(char *std, t_ssl *ssl);

char				*add00(char *str);
uint32_t			revers_uint32(uint32_t n);
uint64_t			revers_uint64(uint64_t n);
void				fake_gnl(char **ptr, int fd);
int					bad_file(t_ssl *ssl, char **argv);

int					print_s(t_ssl *ssl, char **argv, int argc);
void				rotate_s(t_ssl *ssl, char **argv);
void				no_rotation(t_ssl *ssl, char **argv);

int					main(int argc, char **argv);

#endif
