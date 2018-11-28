/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/09 20:00:41 by nmabe             #+#    #+#             */
/*   Updated: 2017/07/22 10:13:37 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int result1;

	if (!s1 || !s2)
		return (0);
	result1 = ft_strcmp((char *)s1, (char *)s2);
	if (result1 == 0)
		return (1);
	else
		return (0);
}
