/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 10:51:45 by nmabe             #+#    #+#             */
/*   Updated: 2018/09/06 10:56:03 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_get_line(const int fd, char **content)
{
	char		*buff;
	char		*tmp;
	int			rd;

	if (!(buff = (char *)malloc(sizeof(*buff) * BUFF_SIZE + 1)))
		return (-1);
	rd = read(fd, buff, BUFF_SIZE);
	if (rd > 0)
	{
		buff[rd] = '\0';
		tmp = ft_strjoin(*content, buff);
		free(*content);
		*content = tmp;
	}
	free(buff);
	return (rd);
}

static int		ft_read_line(int fd, char **lhold)
{
	int			rd;
	char		*str;

	str = *lhold;
	rd = ft_get_line(fd, lhold);
	if (rd == 0)
	{
		if (ft_strlen(*lhold) == 0)
			return (0);
		*lhold = ft_strcat(str, "\n");
	}
	else if (rd < 0)
		return (-1);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	char		*lfeed;
	static char	*lhold;
	size_t		lh;
	int			rd;

	if ((!lhold && (lhold = (char *)malloc(sizeof(*lhold))) == NULL)
			|| !line || fd < 0 || BUFF_SIZE < 0)
		return (-1);
	lfeed = ft_strchr(lhold, '\n');
	while (lfeed == NULL)
	{
		rd = ft_read_line(fd, &lhold);
		if (rd <= 0)
		{
			ft_strdel(&lhold);
			return (rd);
		}
		else
			lfeed = ft_strchr(lhold, '\n');
	}
	lh = ft_strlen(lhold);
	*line = ft_strsub(lhold, 0, (lh - ft_strlen(lfeed)));
	lhold = ft_memcpy(lhold, lfeed + 1, ft_strlen(lfeed));
	return (1);
}
