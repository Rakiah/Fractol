/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:57:47 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 16:35:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	init_palettes(t_main_data *program)
{
	program->palettes[0] = (t_palette){ 0x000000, 0x090132, 0x04044A, 0x000865,
										0x0B2C89, 0x1752B0, 0x88B4E3, 0xD4EBFB,
										0xF1EABE, 0xF6CB5A, 0xFFAA00 };
	program->palettes[1] = (t_palette){ 0x7AE0F2, 0x1e2a66, 0x1FBF06, 0xA63C7F,
										0x262473, 0x0A3BB0, 0xD94A39, 0x403231,
										0x8C5AA6, 0x8BB16C, 0xD9C860 };
	program->palettes[2] = (t_palette){ 0x7AE0F2, 0x752859, 0xF29CD4, 0xA65A8B,
										0x25591F, 0x62A65A, 0x78EDF2, 0x337073,
										0xA65A8B, 0x7AF2B5, 0x337352 };
	program->palettes[3] = (t_palette){ 0xFFFFFF, 0xEEEEEE, 0x000000, 0xCCCCCC,
										0xBBBBBB, 0xAAAAAA, 0x999999, 0x888888,
										0x777777, 0x666666, 0x555555 };
}

void	show_usage(t_main_data *program)
{
	int i;

	i = 0;
	ft_putstr("usage ./fractol [");
	while (i < FRACTALS_COUNT)
	{
		ft_putstr(program->fractals[i++].name);
		if (i != FRACTALS_COUNT)
			ft_putstr(" | ");
	}
	ft_putendl("]");
	exit(0);
}

void	init_fractales(t_fractal fractals[FRACTALS_COUNT])
{
	mandelbrot_init(&fractals[0]);
	julia_init(&fractals[1]);
	burning_ship_init(&fractals[2]);
	tricorn_init(&fractals[3]);
	mandelmult_init(&fractals[4]);
	cubedelbrot_init(&fractals[5]);
	quadelbrot_init(&fractals[6]);
	cubia_init(&fractals[7]);
	quadia_init(&fractals[8]);
}

void	create_fractal_handler(t_main_data *program,
								int selected_fractal,
								int selected_palette)
{
	t_fractal_handler *ret;

	if ((ret = malloc(sizeof(t_fractal_handler))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	ret->s_f = selected_fractal;
	ret->s_p = selected_palette;
	init_fractales(ret->fractals);
	ret->win = window_new(1200, 800, ret->fractals[ret->s_f].name);
	ft_pushback_array(program->fractals_handler,
						&ret, sizeof(t_fractal_handler *));
}
