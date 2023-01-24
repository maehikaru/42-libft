/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:10:28 by maeharahika       #+#    #+#             */
/*   Updated: 2022/12/17 21:15:53 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	count(int n)
{
	int		i;
	size_t	size;

	i = n;
	size = 1;
	if (i < 0)
	{
		i = -i;
		size++;
	}
	while (10 <= i)
	{
		i = i / 10;
		size++;
	}
	return (size);
}

static char	*return_intmin(void)
{
	char	*res;

	res = (char *)ft_calloc(12, sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, "-2147483648", 11);
	return (res);
}

char	*ft_itoa(int n)
{
	size_t	size;
	char	*res;

	if (n == -2147483648)
		return (return_intmin());
	size = count(n) - 1;
	res = (char *)ft_calloc(size + 2, sizeof(char));
	if (!res)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	while (10 <= n)
	{
		res[size--] = '0' + (n % 10);
		n = n / 10;
	}
	res[size] = '0' + n;
	return (res);
}
