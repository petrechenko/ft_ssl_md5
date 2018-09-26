/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   md5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:35:56 by apetrech          #+#    #+#             */
/*   Updated: 2018/09/24 20:29:13 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static const uint32_t g_s[] = {
	7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17, 22, 7, 12, 17,
	22, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 5, 9, 14, 20, 4, 11, 16,
	23, 4, 11, 16, 23, 4, 11, 16, 23, 4, 11, 16, 23, 6, 10, 15, 21, 6, 10, 15,
	21, 6, 10, 15, 21, 6, 10, 15, 21
};

static const uint32_t g_t[] = {
	0xd76aa478, 0xe8c7b756, 0x242070db, 0xc1bdceee,
	0xf57c0faf, 0x4787c62a, 0xa8304613, 0xfd469501,
	0x698098d8, 0x8b44f7af, 0xffff5bb1, 0x895cd7be,
	0x6b901122, 0xfd987193, 0xa679438e, 0x49b40821,
	0xf61e2562, 0xc040b340, 0x265e5a51, 0xe9b6c7aa,
	0xd62f105d, 0x02441453, 0xd8a1e681, 0xe7d3fbc8,
	0x21e1cde6, 0xc33707d6, 0xf4d50d87, 0x455a14ed,
	0xa9e3e905, 0xfcefa3f8, 0x676f02d9, 0x8d2a4c8a,
	0xfffa3942, 0x8771f681, 0x6d9d6122, 0xfde5380c,
	0xa4beea44, 0x4bdecfa9, 0xf6bb4b60, 0xbebfbc70,
	0x289b7ec6, 0xeaa127fa, 0xd4ef3085, 0x04881d05,
	0xd9d4d039, 0xe6db99e5, 0x1fa27cf8, 0xc4ac5665,
	0xf4292244, 0x432aff97, 0xab9423a7, 0xfc93a039,
	0x655b59c3, 0x8f0ccc92, 0xffeff47d, 0x85845dd1,
	0x6fa87e4f, 0xfe2ce6e0, 0xa3014314, 0x4e0811a1,
	0xf7537e82, 0xbd3af235, 0x2ad7d2bb, 0xeb86d391};

static void	init(t_ssl *ssl)
{
	ssl->h0 = 0x67452301;
	ssl->h1 = 0xefcdab89;
	ssl->h2 = 0x98badcfe;
	ssl->h3 = 0x10325476;
}

static int	padding_md5(unsigned char *init_mg, int len, t_ssl *ssl)
{
	init(ssl);
	ssl->len = len + 1;
	while (ssl->len % 64 != 56)
		ssl->len++;
	if (!(ssl->bytes = malloc(ssl->len + 64)))
		return (-1);
	ssl->bytes = ft_bzero(ssl->bytes, ssl->len + 64);
	ft_strcpy((char*)ssl->bytes, (const char *)init_mg);
	*(uint32_t*)(ssl->bytes + len) = 0x80;
	*(uint32_t*)(ssl->bytes + ssl->len) = (uint32_t)(8 * len);
	ssl->str = 0;
	return (0);
}

static void	figure_out_hash(t_ssl *ssl, int i)
{
	if (i < 16)
	{
		ssl->f = F1(ssl->b, ssl->c, ssl->d);
		ssl->g = i;
	}
	else if (i < 32)
	{
		ssl->f = F2(ssl->b, ssl->c, ssl->d);
		ssl->g = (5 * i + 1) % 16;
	}
	else if (i < 48)
	{
		ssl->f = F3(ssl->b, ssl->c, ssl->d);
		ssl->g = (3 * i + 5) % 16;
	}
	else
	{
		ssl->f = F4(ssl->b, ssl->c, ssl->d);
		ssl->g = (7 * i) % 16;
	}
	ssl->tmp = ssl->d;
	ssl->d = ssl->c;
	ssl->c = ssl->b;
	ssl->b = ssl->b + LROT((ssl->a + ssl->f + g_t[i] + ssl->t[ssl->g]), g_s[i]);
	ssl->a = ssl->tmp;
}

int			md5(unsigned char *init_mg, int len, t_ssl *ssl)
{
	int i;

	if (padding_md5(init_mg, len, ssl) == -1)
		return (-1);
	while (ssl->str < ssl->len)
	{
		ssl->t = (uint32_t *)(ssl->bytes + ssl->str);
		ssl->a = ssl->h0;
		ssl->b = ssl->h1;
		ssl->c = ssl->h2;
		ssl->d = ssl->h3;
		i = -1;
		while (++i < 64)
			figure_out_hash(ssl, i);
		ssl->h0 += ssl->a;
		ssl->h1 += ssl->b;
		ssl->h2 += ssl->c;
		ssl->h3 += ssl->d;
		ssl->str += 64;
	}
	free(ssl->bytes);
	return (0);
}
