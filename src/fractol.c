/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hichikaw <hichikaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:30:49 by ichikawahik       #+#    #+#             */
/*   Updated: 2025/07/19 13:39:19 by hichikaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	main(int argc, char **argv)
{
	t_fractol	f;

	if (!validate(argc, argv, &f))
		return (-1);
	if (!init_data(&f))
		return (0);
	msg_operation();
	mlx_loop_hook(f.mlx, &render, &f);
	mlx_hook(f.win, 2, 1L << 0, &keyboard_event, &f);
	mlx_hook(f.win, 4, 1L << 2, &mouse_zoom, &f);
	mlx_hook(f.win, 17, 0L, &close_window, &f);
	mlx_loop(f.mlx);
	return (0);
}
