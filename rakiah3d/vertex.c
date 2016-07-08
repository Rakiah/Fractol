/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 18:28:42 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_vertex	*vertex_new(t_vector4f *pos,
						t_vector2f *tex_coords,
						t_vector3f *normals)
{
	t_vertex *vertex;

	if ((vertex = (t_vertex *)malloc(sizeof(t_vertex))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	vertex->pos = pos;
	vertex->tex_coords = tex_coords;
	vertex->normals = normals;
	return (vertex);
}

t_vertex	*vertex_lerp(t_vertex *v1,
						t_vertex *v2,
						t_vertex *dst,
						float lerp_factor)
{
	t_vector4f position;
	t_vector2f tex_coords;
	t_vector3f normals;

	v4f_lerp(v1->pos, v2->pos, &position, lerp_factor);
	v2f_lerp(v1->tex_coords, v2->tex_coords, &tex_coords, lerp_factor);
	v3f_lerp(v1->normals, v2->normals, &normals, lerp_factor);
	v4f_cpy(dst->pos, &position);
	v2f_cpy(dst->tex_coords, &tex_coords);
	v3f_cpy(dst->normals, &normals);
	return (dst);
}

t_vertex	*vertex_new_cpy(t_vertex *src)
{
	return (vertex_new(v4f_new_cpy(src->pos),
						v2f_new_cpy(src->tex_coords),
						v3f_new_cpy(src->normals)));
}

t_bool		vertex_inside_frustum(t_vertex *v)
{
	return ((fabs(v->pos->x) <= fabs(v->pos->w)) &&
			(fabs(v->pos->y) <= fabs(v->pos->w)) &&
			(fabs(v->pos->z) <= fabs(v->pos->w)));
}
