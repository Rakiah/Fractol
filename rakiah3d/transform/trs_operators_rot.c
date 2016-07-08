/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trs_operators_rot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 05:30:43 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 17:09:25 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

void		trs_rotate(t_transform *trs, t_vector3f *new_rot)
{
	v3f_add(&trs->rotation, new_rot);
	trs->is_dirty = TRUE;
}

void		trs_set_rot(t_transform *trs, t_vector3f *new_rot)
{
	trs->rotation.x = new_rot->x;
	trs->rotation.y = new_rot->y;
	trs->rotation.z = new_rot->z;
	trs->is_dirty = TRUE;
}

void		trs_set_rot_x(t_transform *trs, float x)
{
	trs->rotation.x = x;
	trs->is_dirty = TRUE;
}

void		trs_set_rot_y(t_transform *trs, float y)
{
	trs->rotation.y = y;
	trs->is_dirty = TRUE;
}

void		trs_set_rot_z(t_transform *trs, float z)
{
	trs->rotation.z = z;
	trs->is_dirty = TRUE;
}
