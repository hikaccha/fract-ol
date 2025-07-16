/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichikawahikaru <ichikawahikaru@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:21:29 by ichikawahik       #+#    #+#             */
/*   Updated: 2025/07/14 20:02:16 by ichikawahik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

double	ft_atof(const char *str)
{
	double	num;
	double	power;
	int		sign;

	num = 0;
	sign = 1;
	power = 1;
	while ((*str > 9 && *str < 13) || *str == 32)
		++str;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (ft_isdigit(*str))
		num = num * 10 + (*str++ - '0');
	if (*str == '.')
		++str;
	while (ft_isdigit(*str))
	{
		power *= 10;
		num = num * 10 + (*str++ - '0');
	}
	return (sign * num / power);
}
