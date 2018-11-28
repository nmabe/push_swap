/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 14:12:15 by nmabe             #+#    #+#             */
/*   Updated: 2017/06/10 05:34:19 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, char const *src)
{
	int counter1;

	counter1 = 0;
	while (src[counter1] != '\0')
	{
		dest[counter1] = src[counter1];
		counter1++;
	}
	dest[counter1] = '\0';
	return (dest);
}
