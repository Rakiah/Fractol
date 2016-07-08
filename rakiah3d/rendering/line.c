/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 19:05:26 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 15:14:58 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

static void	draw_scan_line_inner(float value[INTERPOLANTS_COUNT],
								t_material *mat,
								int pos[2])
{
	float		tex_coords[2];
	int			pixel;
	t_core		*core;

	core = get_core();
	if (value[2] < core->window->z_buffer[pos[0]][pos[1]])
	{
		pixel = mat->color;
		if (mat->texture != NULL)
		{
			tex_coords[0] = ft_clampf01((value[0] * (1.0f / value[3])));
			tex_coords[1] = ft_clampf01((value[1] * (1.0f / value[3])));
			core->window->z_buffer[pos[0]][pos[1]] = value[2];
			pixel = tex_get_pixel(mat->texture,
					(int)(tex_coords[0] * (mat->texture->width - 1)),
					(int)(tex_coords[1] * (mat->texture->height - 1)));
		}
		tex_draw_pixel(core->window->screen_tex, pos[0], pos[1], pixel);
	}
}

void		draw_scan_line(t_line *lines[2],
							int y,
							t_material *mat)
{
	float	value[INTERPOLANTS_COUNT];
	float	step[INTERPOLANTS_COUNT];
	int		pos[2];
	int		i;

	i = -1;
	while (++i < INTERPOLANTS_COUNT)
	{
		value[i] = lines[0]->ipls_curr[i];
		step[i] = lines[0]->ipls[i]->x_step;
	}
	pos[0] = (int)lines[0]->x_curr;
	pos[1] = y;
	while (pos[0] < (int)lines[1]->x_curr)
	{
		draw_scan_line_inner(value, mat, pos);
		pos[0]++;
		i = -1;
		while (++i < INTERPOLANTS_COUNT)
			value[i] += step[i];
	}
}

void		draw_between_line(t_line *lines[2],
				t_bool swap,
				t_material *mat)
{
	t_line	*tmp;
	int		y_start;
	int		y_end;

	y_start = lines[1]->y_start;
	y_end = lines[1]->y_end;
	if (swap)
	{
		tmp = lines[0];
		lines[0] = lines[1];
		lines[1] = tmp;
	}
	while (y_start < y_end)
	{
		draw_scan_line(lines, y_start++, mat);
		line_do_step(lines[0]);
		line_do_step(lines[1]);
	}
}

void		line_setup(t_line *l,
					t_vertex *pts[2],
					t_interpolant ipls[INTERPOLANTS_COUNT],
					int min_index)
{
	int	i;

	i = -1;
	l->y_start = (int)pts[0]->pos->y;
	l->y_end = (int)pts[1]->pos->y;
	l->x_curr = pts[0]->pos->x;
	l->x_step = (float)(pts[1]->pos->x - pts[0]->pos->x) /
						(pts[1]->pos->y - pts[0]->pos->y);
	while (++i < INTERPOLANTS_COUNT)
	{
		l->ipls[i] = &ipls[i];
		l->ipls_curr[i] = ipls[i].values[min_index];
		l->ipls_step[i] = ipls[i].y_step + ipls[i].x_step * l->x_step;
	}
}

void		line_do_step(t_line *l)
{
	int i;

	i = -1;
	while (++i < INTERPOLANTS_COUNT)
		l->ipls_curr[i] += l->ipls_step[i];
	l->x_curr += l->x_step;
}
