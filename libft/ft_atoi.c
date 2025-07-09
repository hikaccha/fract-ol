/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichikawahikaru <ichikawahikaru@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 08:03:55 by hichikaw          #+#    #+#             */
/*   Updated: 2025/07/09 20:40:19 by ichikawahik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_overflow(long result, int sign, char digit)
{
	if (sign == 1 && result > (INT_MAX - (digit - '0')) / 10)
		return (1);
	if (sign == -1 && result > (-(long)INT_MIN - (digit - '0')) / 10)
		return (1);
	return (0);
}

long	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\n'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		if (check_overflow(result, sign, nptr[i]))
			return (LONG_MIN);
		result = result * 10 + (nptr[i] - '0');
		i++;
	}
	return (sign * result);
}
