/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/24 14:36:12 by apetrech          #+#    #+#             */
/*   Updated: 2018/09/24 20:36:14 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void			do_md5(char *std, t_ssl *g)
{
	char	*temp;

	if (md5((uint8_t *)std, ft_strlen(std), g) == -1)
		return ;
	temp = ft_itoa_base_extra(revers_uint32(g->h0), 16);
	add00(temp);
	ft_putstr(temp);
	free(temp);
	temp = ft_itoa_base_extra(revers_uint32(g->h1), 16);
	add00(temp);
	ft_putstr(temp);
	free(temp);
	temp = ft_itoa_base_extra(revers_uint32(g->h2), 16);
	add00(temp);
	ft_putstr(temp);
	free(temp);
	temp = ft_itoa_base_extra(revers_uint32(g->h3), 16);
	add00(temp);
	ft_putstr(temp);
	free(temp);
}

static void		do_again_sha256(t_ssl *g)
{
	char	*temp;

	temp = ft_itoa_base_extra(g->h3, 16);
	add00(temp);
	ft_putstr(temp);
	free(temp);
	temp = ft_itoa_base_extra(g->h4, 16);
	add00(temp);
	ft_putstr(temp);
	free(temp);
	temp = ft_itoa_base_extra(g->h5, 16);
	add00(temp);
	ft_putstr(temp);
	free(temp);
	temp = ft_itoa_base_extra(g->h6, 16);
	add00(temp);
	ft_putstr(temp);
	free(temp);
	temp = ft_itoa_base_extra(g->h7, 16);
	add00(temp);
	ft_putstr(temp);
	free(temp);
}

void			do_sha256(char *std, t_ssl *g)
{
	char	*temp;

	if (sha256(std, ft_strlen(std), g) == -1)
		return ;
	temp = ft_itoa_base_extra(g->h0, 16);
	add00(temp);
	ft_putstr(temp);
	free(temp);
	temp = ft_itoa_base_extra(g->h1, 16);
	add00(temp);
	ft_putstr(temp);
	free(temp);
	temp = ft_itoa_base_extra(g->h2, 16);
	add00(temp);
	ft_putstr(temp);
	free(temp);
	do_again_sha256(g);
}
