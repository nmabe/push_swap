/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 11:52:58 by nmabe             #+#    #+#             */
/*   Updated: 2017/06/10 05:10:13 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putstr(char *str)
{
	int counter1;

	counter1 = 0;
	while (str[counter1] != '\0')
	{
		write(1, &str[counter1], 1);
		counter1++;
	}
}
