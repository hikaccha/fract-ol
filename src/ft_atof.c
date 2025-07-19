/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichikaw <hichikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:21:29 by ichikawahik       #+#    #+#             */
/*   Updated: 2025/07/19 19:11:29 by hichikaw         ###   ########.fr       */
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
	while ((*str >= 9 && *str <= 13) || *str == 32)
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
