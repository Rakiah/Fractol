/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   renderer.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 21:22:20 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

void		clip_triangle(t_vertex *verts[3], t_material *mat)
{
	if (vertex_inside_frustum(verts[0]) &&
		vertex_inside_frustum(verts[1]) &&
		vertex_inside_frustum(verts[2]))
		draw_triangle(verts, mat);
}

void		draw_triangle(t_vertex *verts[3], t_material *mat)
{
	int				i;
	t_vertex		*swap;

	normalise_point(verts[0]->pos);
	normalise_point(verts[1]->pos);
	normalise_point(verts[2]->pos);
	i = 0;
	while (i < 2)
	{
		if (verts[i]->pos->y > verts[i + 1]->pos->y)
		{
			swap = verts[i];
			verts[i] = verts[i + 1];
			verts[i + 1] = swap;
			i = -1;
		}
		i++;
	}
	triangle_to_lines(verts, mat);
}

void		triangle_to_lines(t_vertex *verts[3], t_material *mat)
{
	t_bool			side;
	t_line			lines[3];
	t_line			*send_lines[2];
	t_vertex		*send_verts[2];
	t_interpolant	ipls[INTERPOLANTS_COUNT];

	ipl_set_rendering(ipls, verts);
	side = calculate_triangle_side(verts[0]->pos, verts[2]->pos, verts[1]->pos);
	send_verts[0] = verts[0];
	send_verts[1] = verts[2];
	line_setup(&lines[0], send_verts, ipls, 0);
	send_verts[0] = verts[0];
	send_verts[1] = verts[1];
	line_setup(&lines[1], send_verts, ipls, 0);
	send_verts[0] = verts[1];
	send_verts[1] = verts[2];
	line_setup(&lines[2], send_verts, ipls, 1);
	send_lines[0] = &lines[0];
	send_lines[1] = &lines[1];
	draw_between_line(send_lines, side, mat);
	send_lines[0] = &lines[0];
	send_lines[1] = &lines[2];
	draw_between_line(send_lines, side, mat);
}

t_bool		calculate_triangle_side(t_vector4f *a, t_vector4f *b, t_vector4f *c)
{
	return (((b->x - a->x) * (c->y - a->y) -
			(c->x - a->x) * (b->y - a->y)) >= 0 ? 1 : 0);
}

void		normalise_point(t_vector4f *vector)
{
	t_vector4f	*tmp;

	tmp = trs_transform_point(&get_core()->window->screen_matrix, vector);
	vector->x = tmp->x / tmp->w;
	vector->y = tmp->y / tmp->w;
	vector->z = tmp->z / tmp->w;
	vector->w = tmp->w;
	free(tmp);
}
