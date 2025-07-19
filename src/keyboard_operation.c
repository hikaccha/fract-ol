/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_operation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichikaw <hichikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 19:57:05 by ichikawahik       #+#    #+#             */
/*   Updated: 2025/07/19 14:01:24 by hichikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	close_window(t_fractol *f)
{
	mlx_destroy_image(f->mlx, f->img.img);
	mlx_destroy_window(f->mlx, f->win);
	mlx_destroy_display(f->mlx);
	free(f->mlx);
	exit(0);
}

static	void	keyboard_zoom(int key, t_fractol *f)
{
	double	width;
	double	height;

	width = f->max_r - f->min_r;
	height = f->max_i - f->min_i;
	if (key == 'z')
	{
		f->max_r -= width / 10;
		f->min_r += width / 10;
		f->max_i -= height / 10;
		f->min_i += height / 10;
		f->max_iter += 2;
	}
	if (key == 'x')
	{
		f->max_r += width / 10;
		f->min_r -= width / 10;
		f->max_i += height / 10;
		f->min_i -= height / 10;
		if (f->max_iter > 30)
			f->max_iter -= 2;
	}
}

static	void	keyboard_move_r(int key, t_fractol *f)
{
	double	width;

	width = f->max_r - f->min_r;
	if (key == XK_Right)
	{
		f->max_r += width / 10;
		f->min_r += width / 10;
	}
	if (key == XK_Left)
	{
		f->max_r -= width / 10;
		f->min_r -= width / 10;
	}
}

static	void	keyboard_move_i(int key, t_fractol *f)
{
	double	height;

	height = f->max_i - f->min_i;
	if (key == XK_Down)
	{
		f->max_i += height / 10;
		f->min_i += height / 10;
	}
	if (key == XK_Up)
	{
		f->max_i -= height / 10;
		f->min_i -= height / 10;
	}
}

int	keyboad_event(int key, t_fractol *f)
{
	if (key == XK_Escape)
		close_window(f);
	else if (key == XK_Right || key == XK_Left)
		keyboard_move_r(key, f);
	else if (key == XK_Down || key == XK_Up)
		keyboard_move_i(key, f);
	else if (key == 'z' || key == 'x')
		keyboard_zoom(key, 
{