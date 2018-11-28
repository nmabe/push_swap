/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/17 10:24:32 by nmabe             #+#    #+#             */
/*   Updated: 2018/09/17 10:25:13 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_realloc(char **str, size_t new_size)
{
	char	*temp;

	temp = str[0];
	str[0] = ft_strnew(new_size);
	if (str[0] != NULL)
	{
		ft_strcpy(str[0], temp);
		ft_strdel(&temp);
	}
}
