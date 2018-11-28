/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmabe <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/22 10:29:59 by nmabe             #+#    #+#             */
/*   Updated: 2017/07/22 10:30:14 by nmabe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count(const char *s, char c)
{
	int			counter1;
	int			substr1;

	substr1 = 0;
	counter1 = 0;
	while (*s != '\0')
	{
		if (substr1 == 1 && *s == c)
			substr1 = 0;
		if (substr1 == 0 && *s != c)
		{
			substr1 = 1;
			counter1++;
		}
		s++;
	}
	return (counter1);
}

static int		ft_word(const char *s, char c)
{
	int			len1;

	len1 = 0;
	while (*s != c && *s != '\0')
	{
		len1++;
		s++;
	}
	return (len1);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**spl;
	int			word;
	int			i;

	i = 0;
	if (!s || !c)
		return (NULL);
	word = ft_count((const char *)s, c);
	spl = (char **)malloc(sizeof(*spl) * (ft_count((const char *)s, c) + 1));
	if (spl == NULL)
		return (NULL);
	while (word--)
	{
		while (*s == c && *s != '\0')
			s++;
		spl[i] = ft_strsub((const char *)s, 0, ft_word((const char *)s, c));
		if (spl[i] == NULL)
			return (NULL);
		s = s + ft_word(s, c);
		i++;
	}
	spl[i] = NULL;
	return (spl);
}
