/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichikawahikaru <ichikawahikaru@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/10 14:01:54 by ichikawahik       #+#    #+#             */
/*   Updated: 2025/07/15 21:53:35 by ichikawahik      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

static	int	get_kind_of_fractol(char *str)
{
	if (ft_strncmp(str, "Mandelbrot", 11) == 0 || ft_strncmp(str, "M", 2) == 0)
		return (1);
	if (ft_strncmp(str, "Julia", 5) == 0 || ft_strncmp(str, "J", 2) == 0)
		return (2);
	return (0);
}

static	int	is_number(char *str)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '-' || *str == '+')
		str++;
	if (!ft_isdigit(*str))
		return (0);
	while (ft_isdigit(*str))
		str++;
	if (*str == '.')
	{
		str++;
		if (!ft_isdigit(*str))
			return (0);
		while (ft_isdigit(*str))
			str++;
	}
	if (!*str)
		return (1);
	return (0);
}

static	int	is_julia_prms(int argc, char **argv, t_fractol *f)
{
	if (argc == 2)
		return (0);
	if (!is_number(argv[2]) || !is_number(argv[3]))
		return (0);
	f->arg_r = ft_atof(argv[2]);
	f->arg_i = ft_atof(argv[3]);
	if (f->arg_r < -2.0 || f->arg_r > 2.0 || f->arg_i < -2.0 || f->arg_i > 2.0)
		return (0);
	return (1);
}

int	validate(int argc, char **argv, t_fractol *f)
{
	if (argc < 2 || argc > 4 || argc == 3)
		return (msg_error());
	f->kind = get_kind_of_fractol(argv[1]);
	if (f->kind == 0)
		return (msg_error());
	if (f->kind == 1 && argc != 2)
		return (msg_error());
	if (f->kind == 2 && !is_julia_prms(argc, argv, f))
		return (msg_julia_prm());
	return (1);
}
