/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_operators_new.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 04:40:15 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_quaternion	*quat_new(float x, float y, float z, float w)
{
	t_quaternion *ret;

	if ((ret = (t_quaternion *)malloc(sizeof(t_quaternion))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	ret->x = x;
	ret->y = y;
	ret->z = z;
	ret->w = w;
	return (ret);
}

t_quaternion	*conjugage(t_quaternion *q)
{
	return (quat_new(-(q->x), -(q->y), -(q->z), -(q->w)));
}

t_quaternion	*quat_mul_quat_new(t_quaternion *q1, t_quaternion *q2)
{
	return (quat_new(
			q1->x * q2->w + q1->w * q2->x + q1->y * q2->z - q1->z * q2->y,
			q1->y * q2->z + q1->w * q2->y + q1->z * q2->x - q1->x * q2->z,
			q1->z * q2->w + q1->w * q2->z + q1->x * q2->y - q1->y * q2->x,
			q1->w * q2->w - q1->x * q2->x - q1->y * q2->y - q1->z * q2->z));
}

t_quaternion	*quat_mul_v3f_new(t_quaternion *q, t_vector3f *v)
{
	return (quat_new(
			q->w * v->x + q->y * v->z - q->z * v->y,
			q->w * v->y + q->z * v->x - q->x * v->z,
			q->w * v->z + q->x * v->y - q->y * v->x,
			-(q->w) * v->x - q->y * v->y - q->z * v->z));
}
