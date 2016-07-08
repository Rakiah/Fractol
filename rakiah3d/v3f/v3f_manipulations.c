/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v3f_manipulations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:52:32 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

float		v3f_length(t_vector3f *vector)
{
	return ((float)sqrt(vector->x * vector->x +
			vector->y * vector->y +
			vector->z * vector->z));
}

float		v3f_dot(t_vector3f *v1, t_vector3f *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

void		v3f_normalize(t_vector3f *vector)
{
	float length;

	length = v3f_length(vector);
	vector->x /= length;
	vector->y /= length;
	vector->z /= length;
}

void		v3f_rotate(t_vector3f *vector, float angle)
{
	float rad;
	float cosf;
	float sinf;

	rad = angle * ft_pi() / 180.0f;
	cosf = (float)cos(rad);
	sinf = (float)sin(rad);
	vector->x = vector->x * cosf - vector->y * sinf;
	vector->y = vector->x * sinf + vector->y * cosf;
}

t_vector3f	*v3f_cross(t_vector3f *v1, t_vector3f *v2)
{
	return (v3f_new(v1->y * v2->z - v1->z * v2->y,
					v1->z * v2->x - v1->x * v2->z,
					v1->x * v2->y - v1->y * v2->x));
}
