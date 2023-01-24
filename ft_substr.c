/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:13:22 by maeharahika       #+#    #+#             */
/*   Updated: 2022/12/17 13:26:17 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*p;
	size_t	res_len;

	if (s == NULL)
		return (NULL);
	if ((size_t)start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (ft_strlen(s) >= (size_t)start + len)
		res_len = len;
	else
		res_len = ft_strlen(s) - (size_t)start;
	p = (char *)malloc(sizeof(char) * (res_len + 1));
	if (!p)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
		if (i >= (size_t)start && j < len)
			p[j++] = s[i];
	p[j] = '\0';
	return (p);
}
