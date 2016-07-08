/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 22:11:16 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 17:10:36 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		handle_click_center(t_fractal *f, t_palette *p)
{
	t_vector2f	pos;
	t_vector2f	pos_ndc_before;

	pos = get_mouse_pos();
	v2f_set(&pos_ndc_before,
			pos.x / f->zoom + f->x1,
			pos.y / f->zoom + f->y1);
	f->x1 -= (double)pos_ndc_before.x;
	f->y1 -= (double)pos_ndc_before.y;
	redraw_window(f, p);
}

void		handle_others_events(t_main_data *program,
								t_fractal_handler *f_handler,
								t_fractal *f,
								t_palette *p)
{
	if (program->mouse_variation && (f_handler->s_f == 1 ||
									f_handler->s_f == 7 || f_handler->s_f == 8))
		handle_mouse_variation(f, p);
	if (get_key_up(V))
		program->mouse_variation = !program->mouse_variation;
	else if (get_key_up(R))
	{
		init_fractales(f_handler->fractals);
		redraw_window(f, p);
	}
	else if (get_key_down(Q))
	{
		f->iter--;
		redraw_window(f, p);
	}
	else if (get_key_down(W))
	{
		f->iter++;
		redraw_window(f, p);
	}
	else if (get_key_up(ESCAPE))
		exit(0);
}

void		input_handler(t_fractal_handler *f_handler)
{
	t_main_data	*program;
	t_fractal	*f;
	t_palette	*p;

	program = (t_main_data *)get_core()->data;
	f = &f_handler->fractals[f_handler->s_f];
	p = &program->palettes[f_handler->s_p];
	handle_zoom(f, p);
	handle_movement(f, p);
	handle_epileptic(program, f_handler, f);
	handle_others_events(program, f_handler, f, p);
	if (get_key_up(SPACE))
	{
		f_handler->s_f = (f_handler->s_f + 1) % FRACTALS_COUNT;
		redraw_window(&f_handler->fractals[f_handler->s_f], p);
	}
	else if (get_key_up(C))
	{
		f_handler->s_p = (f_handler->s_p + 1) % PALETTES_COUNT;
		redraw_window(f, &program->palettes[f_handler->s_p]);
	}
	else if (get_key_down(H))
		handle_click_center(f, p);
}
