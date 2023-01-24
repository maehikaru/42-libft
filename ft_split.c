/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:11:46 by maeharahika       #+#    #+#             */
/*   Updated: 2022/12/17 13:46:38 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count_strs(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			count++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	return (count);
}

static	char	**ft_freemalloc(char **split)
{
	size_t	i;

	i = 0;
	while (split[i])
		free(split[i++]);
	free(split);
	return (NULL);
}

static	char	**ft_subsplit(char const *s, char c, char **split, size_t index)
{
	size_t		len;
	const char	*p;

	while (*s != '\0')
	{
		while (*s && *s == c)
			s++;
		p = s;
		len = 0;
		while (*s && *s != c)
		{
			s++;
			len++;
		}
		if (*(s - 1) != c)
		{
			split[index] = ft_substr(p, 0, len);
			if (!split[index])
				return (ft_freemalloc(split));
			index++;
		}
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	index;

	index = 0;
	if (!s)
		return (NULL);
	split = (char **) ft_calloc(((count_strs(s, c)) + 1), sizeof(char *));
	if (!split)
		return (NULL);
	return (ft_subsplit(s, c, split, index));
}
