/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichikaw <hichikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 20:50:25 by ichikawahik       #+#    #+#             */
/*   Updated: 2025/07/16 18:37:47 by hichikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	img_pix_coordinate(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_size + x * (img->bpp / 8));
	*(int *)pixel = color;
}

static void	calculate_draw_pixel(double x, double y, t_fractol *f)
{
	double	map_r;
	double	map_i;
	int		iter;

	iter = 0;
	map_r = f->min_r + (x * (f->max_r - f->min_r)) / WIDTH;
	map_i = f->min_i + (y * (f->max_i - f->min_i)) / HEIGHT;
	if (f->kind == 1)
		iter = mandelbrot(map_r, map_i, f);
	else if (f->kind == 2)
		iter = julia(map_r, map_i, f);
	if (iter == f->max_iter)
		img_pix_coordinate(&f->img, x, y, 0x000000);
	else
		img_pix_coordinate(&f->img, x, y, f->color * iter * iter);
}

void	get_fractol_image(t_fractol *f)
{
	double	x;
	double	y;

	x = -1;
	while (++x < WIDTH)
	{
		y = -1;
		while (++y < HEIGHT)
			calculate_draw_pixel(x, y, f);
	}
}
