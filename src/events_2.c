/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:33:40 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 17:00:05 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void		zoom(t_fractal *f, float value, int iter)
{
	t_vector2f	pos;
	t_vector2f	pos_ndc_before;
	t_vector2f	pos_ndc_after;

	pos = get_mouse_pos();
	v2f_set(&pos_ndc_before,
			pos.x / f->zoom + f->x1,
			pos.y / f->zoom + f->y1);
	f->zoom *= value;
	f->zoom_factor /= value;
	f->iter += iter;
	f->x1 -= (double)pos_ndc_before.x;
	f->y1 -= (double)pos_ndc_before.y;
	v2f_set(&pos_ndc_after,
			pos.x / f->zoom + f->x1,
			pos.y / f->zoom + f->y1);
	f->x1 += (pos_ndc_before.x - pos_ndc_after.x);
	f->y1 += (pos_ndc_before.y - pos_ndc_after.y);
}

void		handle_zoom(t_fractal *f, t_palette *p)
{
	static int zoomed = 0;

	if (get_key_down(KEYPAD_PLUS) || get_mouse_button_down(4))
	{
		zoomed++;
		zoom(f, 1.1f, zoomed % 2 == 0 ? 1 : 0);
		redraw_window(f, p);
	}
	else if (get_key_down(KEYPAD_MINUS) || get_mouse_button_down(5))
	{
		zoomed++;
		zoom(f, 1.0f / 1.1f, zoomed % 2 == 0 ? -1 : 0);
		redraw_window(f, p);
	}
}

void		handle_movement(t_fractal *f, t_palette *p)
{
	if (get_key_down(LEFT_ARROW))
	{
		f->x1 += f->zoom_factor / 5000.0f;
		redraw_window(f, p);
	}
	else if (get_key_down(RIGHT_ARROW))
	{
		f->x1 -= f->zoom_factor / 5000.0f;
		redraw_window(f, p);
	}
	else if (get_key_down(UP_ARROW))
	{
		f->y1 += f->zoom_factor / 5000.0f;
		redraw_window(f, p);
	}
	else if (get_key_down(DOWN_ARROW))
	{
		f->y1 -= f->zoom_factor / 5000.0f;
		redraw_window(f, p);
	}
}

void		handle_mouse_variation(t_fractal *f, t_palette *p)
{
	static t_vector2f	old_pos;
	t_vector2f			new_pos;

	new_pos = get_mouse_pos();
	if (old_pos.x == new_pos.x && old_pos.y == new_pos.y)
		return ;
	f->c.r = new_pos.x / f->zoom + f->x1;
	f->c.i = new_pos.y / f->zoom + f->y1;
	redraw_window(f, p);
	old_pos = new_pos;
}

void		handle_epileptic(t_main_data *program,
							t_fractal_handler *f_handler,
							t_fractal *f)
{
	static float	timer = 0.0f;

	if (get_key_up(E))
	{
		ft_putstr("EPILEPTIC CHANGED\n");
		program->epileptic = !program->epileptic;
	}
	if (program->epileptic)
	{
		if (get_key_down(ALPHA1))
			program->epileptic_timer += 0.01f;
		if (get_key_down(ALPHA2) && program->epileptic_timer > 0.01f)
			program->epileptic_timer -= 0.01f;
		timer += get_core()->delta_time;
		if (timer >= program->epileptic_timer)
		{
			f_handler->s_p = (f_handler->s_p + 1) % PALETTES_COUNT;
			redraw_window(f, &program->palettes[f_handler->s_p]);
			timer = 0.0f;
		}
	}
}
