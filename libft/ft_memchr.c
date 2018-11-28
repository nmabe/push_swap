/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 17:01:41 by nmabe             #+#    #+#             */
/*   Updated: 2017/07/21 10:26:09 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter1;
	unsigned char	*ps;

	counter1 = 0;
	ps = (unsigned char *)s;
	while (counter1 < n)
	{
		if (ps[counter1] == (unsigned char)c)
			return (ps + counter1);
		counter1++;
	}
	return (NULL);
}
