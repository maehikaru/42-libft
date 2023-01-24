/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:10:56 by maeharahika       #+#    #+#             */
/*   Updated: 2022/12/17 17:40:09 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*p_dst;
	unsigned char	*p_src;

	p_dst = (unsigned char *)dst;
	p_src = (unsigned char *)src;
	i = 0;
	if (!p_dst && !p_src)
		return (NULL);
	if (p_dst > p_src)
	{
		while (++i <= n)
			p_dst[n - i] = p_src[n - i];
	}
	else
	{
		while (0 < n--)
		*(p_dst++) = *(p_src++);
	}
	return (dst);
}
