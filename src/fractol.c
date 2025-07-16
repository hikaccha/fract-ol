/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichikawahikaru <ichikawahikaru@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 12:30:49 by ichikawahik       #+#    #+#             */
/*   Updated: 2025/07/15 21:38:27 by ichikawahik      ###   ########.fr       */
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
	mlx_hook(f.win, 2, 1L << 0, &keyboad_event, &f);
	mlx_hook(f.win, 4, 1L << 2, &mouse_zoom, &f);
	mlx_hook(f.win, 17, 0L, &close_window, &f);
	mlx_loop(f.mlx);
	return (0);
}
