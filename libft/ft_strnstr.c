/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 16:33:51 by nmabe             #+#    #+#             */
/*   Updated: 2017/07/22 10:24:06 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	size;

	if (*little == '\0')
		return ((char*)big);
	size = ft_strlen((char *)little);
	while (*big != '\0' && len-- >= size)
	{
		if (*big == *little && ft_strncmp(big, little, size) == 0)
			return ((char*)big);
		big++;
	}
	return (NULL);
}
