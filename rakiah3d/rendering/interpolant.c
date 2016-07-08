/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpolant.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 21:22:34 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

/*
**		ipls[0] = texture coord X
**		ipls[1] = texture coord Y
**		ipls[2] = z_buffer
**		ipls[3] = perspective texture mapping
*/

void			ipl_set_rendering(t_interpolant ipls[INTERPOLANTS_COUNT],
							t_vertex *verts[3])
{
	float	w[3];

	w[0] = 1.0f / verts[0]->pos->w;
	w[1] = 1.0f / verts[1]->pos->w;
	w[2] = 1.0f / verts[2]->pos->w;
	ipl_calculate_steps(ipl_set_values(&ipls[0],
										verts[0]->tex_coords->x * w[0],
										verts[1]->tex_coords->x * w[1],
										verts[2]->tex_coords->x * w[2]),
						verts[0]->pos, verts[1]->pos, verts[2]->pos);
	ipl_calculate_steps(ipl_set_values(&ipls[1],
										verts[0]->tex_coords->y * w[0],
										verts[1]->tex_coords->y * w[1],
										verts[2]->tex_coords->y * w[2]),
						verts[0]->pos, verts[1]->pos, verts[2]->pos);
	ipl_calculate_steps(ipl_set_values(&ipls[2],
										verts[0]->pos->z,
										verts[1]->pos->z,
										verts[2]->pos->z),
						verts[0]->pos, verts[1]->pos, verts[2]->pos);
	ipl_calculate_steps(ipl_set_values(&ipls[3],
										w[0],
										w[1],
										w[2]),
						verts[0]->pos, verts[1]->pos, verts[2]->pos);
}

void			ipl_calculate_steps(t_interpolant *ipl,
					t_vector4f *min,
					t_vector4f *mid,
					t_vector4f *max)
{
	float inverse_dx;

	inverse_dx = 1.0f /
	(((mid->x - max->x) * (min->y - max->y)) -
	((min->x - max->x) * (mid->y - max->y)));
	ipl->x_step = (((ipl->values[1] - ipl->values[2]) *
			(min->y - max->y)) -
			((ipl->values[0] - ipl->values[2]) *
			(mid->y - max->y))) * inverse_dx;
	ipl->y_step = (((ipl->values[1] - ipl->values[2]) *
			(min->x - max->x)) -
			((ipl->values[0] - ipl->values[2]) *
			(mid->x - max->x))) * (-inverse_dx);
}

t_interpolant	*ipl_set_values(t_interpolant *ipl,
				float x,
				float y,
				float z)
{
	ipl->values[0] = x;
	ipl->values[1] = y;
	ipl->values[2] = z;
	return (ipl);
}

t_interpolant	*ipl_new(float values[3], t_vector4f *min,
			t_vector4f *mid,
			t_vector4f *max)
{
	t_interpolant	*ret;

	if ((ret = (t_interpolant *)malloc(sizeof(t_interpolant))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	ret->values[0] = values[0];
	ret->values[1] = values[1];
	ret->values[2] = values[2];
	ipl_calculate_steps(ret, min, mid, max);
	return (ret);
}
