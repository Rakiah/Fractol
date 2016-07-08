/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trs_operators_scale.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 05:32:15 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 17:09:37 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

void		trs_scale(t_transform *trs, t_vector3f *new_scale)
{
	v3f_add(&trs->scale, new_scale);
	trs->is_dirty = TRUE;
}

void		trs_set_scale(t_transform *trs, t_vector3f *new_scale)
{
	trs->scale.x = new_scale->x;
	trs->scale.y = new_scale->y;
	trs->scale.z = new_scale->z;
	trs->is_dirty = TRUE;
}

void		trs_set_scale_x(t_transform *trs, float x)
{
	trs->scale.x = x;
	trs->is_dirty = TRUE;
}

void		trs_set_scale_y(t_transform *trs, float y)
{
	trs->scale.y = y;
	trs->is_dirty = TRUE;
}

void		trs_set_scale_z(t_transform *trs, float z)
{
	trs->scale.z = z;
	trs->is_dirty = TRUE;
}
