/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 15:21:44 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_core		*get_core(void)
{
	static t_core	core;

	return (&core);
}

void		core_init(void (*update)(),
					void (*expose)(t_window *),
					void (*postrender)(),
					int frame_rate)
{
	t_core	*core;

	core = get_core();
	if ((core->mlx = mlx_init()) == NULL)
		error_exit("MLX INIT FAILED");
	if ((core->wins = ft_create_array(sizeof(t_window *))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	if ((core->loaders = ft_create_array(sizeof(t_loader *))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	core_add_loader(&load_obj, ft_strdup("obj"));
	core_add_loader(&load_ro, ft_strdup("ro"));
	core_add_loader(&load_bitmap, ft_strdup("bmp"));
	core_add_loader(&load_rs, ft_strdup("rs"));
	core->update = update;
	core->postrender = postrender;
	core->expose = expose;
	core->window = NULL;
	core->data = NULL;
	core->window_id = -1;
	core->target_framerate = frame_rate;
	core->delta_time = 1.0f;
	mlx_loop_hook(core->mlx, &internal_update, core);
}

void		core_add_loader(t_floader loader, char *extension)
{
	t_loader	*to_push;
	t_core		*core;

	core = get_core();
	if ((to_push = malloc(sizeof(t_loader))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	to_push->extension = extension;
	to_push->method = loader;
	ft_pushback_array(core->loaders, &to_push, sizeof(t_loader *));
}

void		core_start(void)
{
	mlx_loop(get_core()->mlx);
}

void		core_render(void)
{
	size_t		i;
	t_object	*obj;
	t_core		*core;

	core = get_core();
	i = 0;
	while (i < core->window->objs->count)
	{
		obj = ((t_object **)core->window->objs->array)[i];
		obj_draw(obj);
		i++;
	}
}
