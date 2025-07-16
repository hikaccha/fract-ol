/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichikawahikaru <ichikawahikaru@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 15:53:27 by ichikawahik       #+#    #+#             */
/*   Updated: 2025/07/15 21:37:58 by ichikawahik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	julia(double x, double y, t_fractol *f)
{
	double	zr;
	double	zi;
	double	tmp;
	int		iter;

	zr = x;
	zi = y;
	iter = 0;
	while (iter < f->max_iter)
	{
		tmp = 2 * zr * zi - f->arg_i;
		zr = zr * zr - zi * zi + f->arg_r;
		zi = tmp;
		if ((zr * zr + zi * zi) > 4)
			break ;
		++iter;
	}
	return (iter);
}
