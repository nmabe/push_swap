/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 18:16:56 by nmabe             #+#    #+#             */
/*   Updated: 2017/07/22 10:17:44 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*pdst;
	char	*psrc;
	size_t	len;

	pdst = (char *)ft_memchr(dest, '\0', size);
	if (pdst == NULL)
		return (size + ft_strlen(src));
	psrc = (char *)src;
	len = (size_t)(pdst - dest) + ft_strlen(psrc);
	while ((size_t)(pdst - dest) < size - 1 && psrc)
	{
		*pdst = *psrc;
		pdst++;
		psrc++;
	}
	*pdst = '\0';
	return (len);
}
