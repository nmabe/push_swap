/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 11:18:56 by nmabe             #+#    #+#             */
/*   Updated: 2017/07/22 10:07:08 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		*ft_memcpy_2(void *s1, const void *s2, size_t len)
{
	char *ps1;
	char *ps2;

	if (len == 0 || s1 == s2)
		return (s1);
	ps1 = (char *)s1;
	ps2 = (char *)s2;
	while (len--)
	{
		ps1[len] = ps2[len];
	}
	return (s1);
}

void			*ft_memmove(void *dest, const void *src, size_t size)
{
	if (dest < src)
		return (ft_memcpy(dest, src, size));
	if (dest > src)
		return (ft_memcpy_2(dest, src, size));
	return (dest);
}
