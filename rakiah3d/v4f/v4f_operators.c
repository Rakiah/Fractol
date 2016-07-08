/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4f_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 03:53:43 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

void		v4f_add(t_vector4f *v1, t_vector4f *v2)
{
	v1->x += v2->x;
	v1->y += v2->y;
	v1->z += v2->z;
	v1->w += v2->w;
}

void		v4f_sub(t_vector4f *v1, t_vector4f *v2)
{
	v1->x -= v2->x;
	v1->y -= v2->y;
	v1->z -= v2->z;
	v1->w -= v2->w;
}

void		v4f_mul(t_vector4f *v1, t_vector4f *v2)
{
	v1->x *= v2->x;
	v1->y *= v2->y;
	v1->z *= v2->z;
	v1->w *= v2->w;
}

void		v4f_div(t_vector4f *v1, t_vector4f *v2)
{
	v1->x /= v2->x;
	v1->y /= v2->y;
	v1->z /= v2->z;
	v1->w /= v2->w;
}

float		v4f_get_at(t_vector4f *v, int index)
{
	if (index == 0)
		return (v->x);
	if (index == 1)
		return (v->y);
	if (index == 2)
		return (v->z);
	if (index == 3)
		return (v->w);
	error_exit("OUT OF BOUNDS");
	return (0);
}
