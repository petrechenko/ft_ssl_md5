/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apetrech <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/05 11:49:24 by apetrech          #+#    #+#             */
/*   Updated: 2018/07/31 21:28:21 by apetrech         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_read(const int fd, char **s)
{
	char	buff[BUFF_SIZE + 1];
	char	*temp;
	int		i;

	if ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		temp = s[fd];
		s[fd] = ft_strjoin(temp, buff);
		free(temp);
	}
	return (i);
}

int			ft_new_line(const int fd, char **line, int r, char **s)
{
	INT;
	nl = 0;
	if (s[fd] && s[fd][0] == '\0')
		return (0);
	while (s[fd][nl] && s[fd][nl] != '\n')
		nl++;
	if (s[fd][nl] == '\n')
	{
		*line = ft_strsub(s[fd], 0, nl);
		tmp = ft_strdup(s[fd] + nl + 1);
		free(s[fd]);
		s[fd] = ft_strdup(tmp);
		free(tmp);
		if (!s[fd][0])
			ft_strdel(&s[fd]);
	}
	else
	{
		if (r == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(s[fd]);
		ft_strdel(&s[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*s[4864];
	int			nl;
	int			r;

	nl = 0;
	if (fd < 0 || line == NULL || fd > LIMIT)
		return (-1);
	if (!s[fd])
		s[fd] = ft_strnew(1);
	r = ft_read(fd, s);
	if (r < 0)
		return (-1);
	else if (r == 0 && !s[fd])
		return (0);
	else
		return (ft_new_line(fd, line, r, s));
	return (1);
}
