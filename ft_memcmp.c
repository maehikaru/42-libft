/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:10:41 by maeharahika       #+#    #+#             */
/*   Updated: 2022/12/17 17:49:46 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*p_s1;
	unsigned char	*p_s2;

	i = 0;
	p_s1 = (unsigned char *)s1;
	p_s2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*(p_s1 + i) == *(p_s2 + i))
			i++;
		else
			return (*(p_s1 + i) - *(p_s2 + i));
	}
	return (0);
}
