/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/03 23:05:10 by nmabe             #+#    #+#             */
/*   Updated: 2017/06/10 05:36:35 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(char *str, int c)
{
	int		counter1;

	counter1 = ft_strlen(str);
	while (counter1 >= 0)
	{
		if (str[counter1] == (char)c)
		{
			return (&str[counter1]);
		}
		counter1--;
	}
	return (NULL);
}
