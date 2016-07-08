/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trs_manipulations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 05:27:20 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 17:08:55 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_transform	*trs_new_init(void)
{
	t_transform *ret;

	if ((ret = (t_transform *)malloc(sizeof(t_transform))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	v3f_set(&ret->position, 0.0f, 0.0f, 0.0f);
	v3f_set(&ret->rotation, 0.0f, 0.0f, 0.0f);
	v3f_set(&ret->scale, 1.0f, 1.0f, 1.0f);
	ret->is_dirty = TRUE;
	return (ret);
}

t_transform	*trs_new(t_vector3f *position,
					t_vector3f *rotation,
					t_vector3f *scale)
{
	t_transform *ret;

	if ((ret = (t_transform *)malloc(sizeof(t_transform))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	v3f_set(&ret->position, position->x, position->y, position->z);
	v3f_set(&ret->rotation, rotation->x, rotation->y, rotation->z);
	v3f_set(&ret->scale, scale->x, scale->y, scale->z);
	ret->is_dirty = TRUE;
	return (ret);
}

t_matrix4f	*trs_get_matrix(t_transform *trs)
{
	if (trs->is_dirty)
		trs_recalculate_matrix(trs);
	return (&trs->model_world_matrix);
}

void		trs_recalculate_matrix(t_transform *trs)
{
	t_matrix4f translation_matrix;
	t_matrix4f rotation_matrix;
	t_matrix4f scale_matrix;

	m4f_translate(&translation_matrix,
		trs->position.x,
		trs->position.y,
		trs->position.z);
	m4f_rotate(&rotation_matrix,
		trs->rotation.x,
		trs->rotation.y,
		trs->rotation.z);
	m4f_scale(&scale_matrix,
		trs->scale.x,
		trs->scale.y,
		trs->scale.z);
	m4f_cpy(&trs->model_world_matrix,
		m4f_mul(&translation_matrix,
			m4f_mul(&rotation_matrix,
				&scale_matrix)));
	trs->is_dirty = FALSE;
}

t_vector4f	*trs_transform_point(t_matrix4f *m, t_vector4f *v)
{
	t_vector4f *ret;

	ret = v4f_new(0.0f, 0.0f, 0.0f, 0.0f);
	ret->x = m->m[0][0] * v->x + m->m[0][1] *
	v->y + m->m[0][2] * v->z + m->m[0][3] * v->w;
	ret->y = m->m[1][0] * v->x + m->m[1][1] *
	v->y + m->m[1][2] * v->z + m->m[1][3] * v->w;
	ret->z = m->m[2][0] * v->x + m->m[2][1] *
	v->y + m->m[2][2] * v->z + m->m[2][3] * v->w;
	ret->w = m->m[3][0] * v->x + m->m[3][1] *
	v->y + m->m[3][2] * v->z + m->m[3][3] * v->w;
	return (ret);
}
