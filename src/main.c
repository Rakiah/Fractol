/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:34:29 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 17:00:02 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	redraw_window(t_fractal *fractal, t_palette *palette)
{
	int					i;
	int					pixel_count;
	t_texture			*tex;
	t_core				*core;

	core = get_core();
	tex = core->window->screen_tex;
	tex_clear(tex);
	i = 0;
	pixel_count = tex->size / tex->bytes_per_pixel;
	while (i < pixel_count)
	{
		tex_draw_pixel_index(tex, i, fractal->method(fractal,
								palette,
								i % tex->width,
								i / tex->width));
		i++;
	}
	mlx_put_image_to_window(core->mlx,
				core->window->win,
				tex->img,
				0, 0);
}

void	expose_handler(t_window *win)
{
	int					old_select;
	t_core				*core;
	t_main_data			*program;
	t_fractal_handler	*f_handler;

	core = get_core();
	program = (t_main_data *)core->data;
	old_select = core->window_id;
	core_select_window(win->id);
	f_handler = ((t_fractal_handler **)program->
			fractals_handler->array)[win->id];
	redraw_window(&f_handler->fractals[f_handler->s_f],
					&program->palettes[f_handler->s_p]);
	core_select_window(old_select);
}

void	update(void)
{
	t_core				*core;
	t_main_data			*program;
	t_fractal_handler	*handle;

	core = get_core();
	program = (t_main_data *)core->data;
	handle = ((t_fractal_handler **)program->
	fractals_handler->array)[core->window_id];
	core->window->cancel_render = TRUE;
	input_handler(handle);
}

void	check_args(int ac, char **av, t_main_data *program)
{
	int i;
	int j;

	if (ac < 2)
		show_usage(program);
	program->fractals_handler = ft_create_array(sizeof(t_fractal_handler **));
	j = 1;
	while (j < ac)
	{
		i = 0;
		while (i < FRACTALS_COUNT)
		{
			if (ft_strequ(av[j], program->fractals[i].name))
				create_fractal_handler(program, i, 0);
			i++;
		}
		j++;
	}
	if (program->fractals_handler->count == 0)
		show_usage(program);
}

int		main(int ac, char **av)
{
	t_main_data	*program;

	core_init(&update, &expose_handler, NULL, 100);
	if ((program = malloc(sizeof(t_main_data))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	program->mouse_variation = TRUE;
	init_palettes(program);
	init_fractales(program->fractals);
	check_args(ac, av, program);
	program->epileptic = FALSE;
	program->epileptic_timer = 0.05f;
	get_core()->data = program;
	core_start();
	return (0);
}
