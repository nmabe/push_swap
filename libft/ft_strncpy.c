/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 13:22:26 by nmabe             #+#    #+#             */
/*   Updated: 2017/07/21 11:14:36 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char const *src, size_t n)
{
	size_t counter1;

	counter1 = 0;
	while (src[counter1] && n)
	{
		dest[counter1] = src[counter1];
		counter1++;
		n--;
	}
	while (n)
	{
		dest[counter1] = '\0';
		n--;
		counter1++;
	}
	return (dest);
}
