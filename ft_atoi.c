/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maeharahikaru <maeharahikaru@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 11:09:17 by maeharahika       #+#    #+#             */
/*   Updated: 2023/01/23 22:17:05 by hmaehara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_ou(int sign)
{
	if (sign == 1)
		return ((int)LONG_MAX);
	else
		return ((int)LONG_MIN);
}

int	c_d(long res)
{
	int	div;

	div = 1;
	while (res > 10)
	{
		res = res / 10;
		div += 1;
	}
	return (div);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
			str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
		if ((res == (LONG_MAX / 10) && '7' < str[i] && str[i] <= '9') \
				|| ((c_d(res) == 19 || res > (LONG_MAX / 10)) \
					&& str[i] >= '0' && str[i] <= '9'))
			return (check_ou(sign));
	}
	return (res * sign);
}
