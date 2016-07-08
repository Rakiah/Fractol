/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4f_initializers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 04:22:13 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 04:28:46 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

void		m4f_translate(t_matrix4f *matrix, float x, float y, float z)
{
	m4f_identity(matrix);
	matrix->m[0][3] = x;
	matrix->m[1][3] = y;
	matrix->m[2][3] = z;
}

void		m4f_scale(t_matrix4f *matrix, float x, float y, float z)
{
	m4f_identity(matrix);
	matrix->m[0][0] = x;
	matrix->m[1][1] = y;
	matrix->m[2][2] = z;
}

void		m4f_rotate(t_matrix4f *matrix, float x, float y, float z)
{
	t_matrix4f rx;
	t_matrix4f ry;
	t_matrix4f rz;

	x = x * ft_pi() / 180.0f;
	y = y * ft_pi() / 180.0f;
	z = z * ft_pi() / 180.0f;
	m4f_identity(&rx);
	m4f_identity(&ry);
	m4f_identity(&rz);
	rx.m[1][1] = (float)cos(x);
	rx.m[1][2] = -(float)sin(x);
	rx.m[2][1] = (float)sin(x);
	rx.m[2][2] = (float)cos(x);
	ry.m[0][0] = (float)cos(y);
	ry.m[0][2] = (float)sin(y);
	ry.m[2][0] = -(float)sin(y);
	ry.m[2][2] = (float)cos(y);
	rz.m[0][0] = (float)cos(z);
	rz.m[0][1] = -(float)sin(z);
	rz.m[1][0] = (float)sin(z);
	rz.m[1][1] = (float)cos(z);
	m4f_cpy(matrix, m4f_mul(&rz, m4f_mul(&ry, &rx)));
}

void		m4f_perspective(t_camera *camera)
{
	float	fov_rad;
	float	fov;
	float	zrange;
	float	ar;

	fov_rad = camera->fov * (ft_pi() / 180.0f);
	fov = (float)tan(fov_rad * 0.5f);
	zrange = camera->z_bounds.x - camera->z_bounds.y;
	ar = camera->size.x / camera->size.y;
	m4f_identity(&camera->projection);
	camera->projection.m[0][0] = 1.0f / (fov * ar);
	camera->projection.m[1][1] = 1.0f / fov;
	camera->projection.m[2][2] = (-camera->z_bounds.x -
									camera->z_bounds.y) / zrange;
	camera->projection.m[2][3] = 2 * camera->z_bounds.y *
									camera->z_bounds.x / zrange;
	camera->projection.m[3][2] = 1;
	camera->projection.m[3][3] = 0;
}

void		m4f_screen_space(t_matrix4f *m, float width, float height)
{
	m4f_identity(m);
	m->m[0][0] = width / 2;
	m->m[0][3] = (width / 2) - 0.5f;
	m->m[1][1] = -(height / 2);
	m->m[1][3] = (height / 2) - 0.5f;
	m->m[3][3] = 1;
}
