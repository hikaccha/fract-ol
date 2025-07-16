/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichikawahikaru <ichikawahikaru@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 18:41:23 by ichikawahik       #+#    #+#             */
/*   Updated: 2025/07/15 21:52:41 by ichikawahik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static	void	release_all(t_fractol *f)
{
	if (f->img.img != 0)
		mlx_destroy_image(f->mlx, f->img.img);
	if (f->win != 0)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx != 0)
	{
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
}

void	clean_data(t_fractol *f)
{
	f->mlx = 0;
	f->win = 0;
	f->kind = 0;
	f->color = 0;
	f->min_r = -2.0;
	f->max_r = 2.0;
	f->min_i = -2.0;
	f->max_i = 2.0;
	f->arg_r = 0.0;
	f->arg_i = 0.0;
	f->max_iter = 50;
	f->img.img = 0;
	f->img.addr = 0;
	f->img.bpp = 0;
	f->img.line_size = 0;
	f->img.endian = 0;
}

static	void	set_fractol(t_fractol *f)
{
	if (f->kind == 1)
	{
		f->min_r = -2.0;
		f->max_r = 1.0;
		f->min_i = -1.5;
		f->max_i = (f->max_r - f->min_r) * HEIGHT / WIDTH + f->min_i;
		f->max_iter = 30;
		f->color = 265;
	}
	if (f->kind == 2)
	{
		f->min_r = -2.0;
		f->max_r = 2.0;
		f->min_i = -2.0;
		f->max_i = (f->max_r - f->min_r) * HEIGHT / WIDTH + f->min_i;
		f->max_iter = 30;
		f->color = 265;
	}
}

static	int	init_window(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		return (0);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fract-ol");
	if (!f->win)
	{
		release_all(f);
		return (0);
	}
	f->img.img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img.img)
	{
		release_all(f);
		return (0);
	}
	f->img.addr = mlx_get_data_addr(f->img.img, &f->img.bpp, &f->img.line_size,
			&f->img.endian);
	if (!f->img.addr)
	{
		release_all(f);
		return (0);
	}
	return (1);
}

int	init_data(t_fractol *f)
{
	clean_data(f);
	if (!init_window(f))
		return (0);
	set_fractol(f);
	return (1);
}
