/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichikawahikaru <ichikawahikaru@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:16:10 by ichikawahik       #+#    #+#             */
/*   Updated: 2025/07/12 17:36:41 by ichikawahik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	render(t_fractol *f)
{
	get_fractol_image(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img.img, 0, 0);
	return (1);
}
