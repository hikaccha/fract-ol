/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichikaw <hichikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 23:52:33 by ichikawahik       #+#    #+#             */
/*   Updated: 2025/07/16 18:45:49 by hichikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <math.h>
# include <X11/keysym.h>

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		bpp;
	int		line_size;
	int		endian;
}	t_img;

typedef struct s_fractol
{
	void	*mlx;
	void	*win;
	int		kind;
	int		color;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	double	arg_r;
	double	arg_i;
	double	max_iter;
	t_img	img;
}	t_fractol;

int		validate(int argc, char **argv, t_fractol *f);
double	ft_atof(const char *str);
void	clean_data(t_fractol *f);
int		init_data(t_fractol *f);
int		julia(double x, double y, t_fractol *f);
int		mandelbrot(double x, double y, t_fractol *f);
int		close_window(t_fractol *f);
int		keyboad_event(int key, t_fractol *f);
int		mouse_zoom(int key, int x, int y, t_fractol *f);
int		msg_error(void);
int		msg_julia_prm(void);
int		msg_operation(void);
int		render(t_fractol *f);
void	get_fractol_image(t_fractol *f);

#endif