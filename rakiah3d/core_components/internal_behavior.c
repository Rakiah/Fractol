/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_behavior.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 06:14:15 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 15:24:26 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"
#include <time.h>

void	internal_render(t_core *core)
{
	size_t		i;
	int			selected;

	if ((selected = core->window_id) == -1)
		return ;
	i = 0;
	while (i < core->wins->count)
	{
		core_select_window(i);
		if (!core->window->cancel_render)
		{
			if (core->window->cams->count > 0)
			{
				tex_clear(core->window->screen_tex);
				clear_z_buffer(core->window);
				core_render(core);
				mlx_put_image_to_window(core->mlx, core->window->win,
										core->window->screen_tex->img, 0, 0);
			}
		}
		else
			core->window->cancel_render = FALSE;
		i++;
	}
	core_select_window(selected);
}

void	reset_inputs(void)
{
	int i;

	i = 3;
	key_up(-1, CMD_SET_ALL, FALSE);
	key_down(-1, CMD_SET_ALL, FALSE);
	mouse_up(-1, CMD_SET_ALL, FALSE);
	while (++i < 7)
		mouse_down(i, CMD_SET, FALSE);
}

void	calculate_delta_time(t_core *core, clock_t start)
{
	long		sleep_time;
	double		render_time;

	render_time = (double)(clock() - start) / CLOCKS_PER_SEC;
	sleep_time = ((((double)1 / core->target_framerate)
				- render_time) * 1000000);
	if (sleep_time >= 0)
	{
		core->delta_time = (double)sleep_time / 1000000;
		usleep(sleep_time);
	}
	else
		core->delta_time = 0;
	core->delta_time += (double)(clock() - start) / CLOCKS_PER_SEC;
}

int		internal_expose_hook(t_window *window)
{
	t_core *core;

	core = get_core();
	if (core->expose != NULL)
		core->expose(window);
	return (0);
}

int		internal_update(t_core *core)
{
	clock_t		start;

	start = clock();
	if (core->update != NULL)
		core->update();
	internal_render(core);
	if (core->postrender != NULL)
		core->postrender();
	reset_inputs();
	calculate_delta_time(core, start);
	return (0);
}
