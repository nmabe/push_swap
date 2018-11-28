/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 13:39:03 by nmabe             #+#    #+#             */
/*   Updated: 2017/07/21 11:53:32 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f) (unsigned int, char*))
{
	int counter1;

	counter1 = 0;
	if (!s || !f)
		return ;
	while (s[counter1] != '\0')
	{
		f(counter1, &s[counter1]);
		counter1++;
	}
}
