/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trs_operators_pos.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 05:29:08 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 17:09:13 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

void		trs_translate(t_transform *trs, t_vector3f *new_pos)
{
	v3f_add(&trs->position, new_pos);
	trs->is_dirty = TRUE;
}

void		trs_set_pos(t_transform *trs, t_vector3f *new_pos)
{
	trs->position.x = new_pos->x;
	trs->position.y = new_pos->y;
	trs->position.z = new_pos->z;
	trs->is_dirty = TRUE;
}

void		trs_set_pos_x(t_transform *trs, float x)
{
	trs->position.x = x;
	trs->is_dirty = TRUE;
}

void		trs_set_pos_y(t_transform *trs, float y)
{
	trs->position.y = y;
	trs->is_dirty = TRUE;
}

void		trs_set_pos_z(t_transform *trs, float z)
{
	trs->position.z = z;
	trs->is_dirty = TRUE;
}
