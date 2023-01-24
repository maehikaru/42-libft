/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:11:06 by maeharahika       #+#    #+#             */
/*   Updated: 2022/12/17 12:08:52 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *buf, int ch, size_t n)
{
	unsigned char	*tmp;
	size_t			i;

	tmp = (unsigned char *)buf;
	i = 0;
	while (i < n)
	{
		tmp[i] = (unsigned char)ch;
		i++;
	}
	return (buf);
}
