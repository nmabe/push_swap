/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 15:52:16 by nmabe             #+#    #+#             */
/*   Updated: 2017/06/10 05:30:44 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	int		counter1;

	str = b;
	counter1 = 0;
	while (counter1 < (int)len)
	{
		str[counter1] = c;
		counter1++;
	}
	return (str);
}
