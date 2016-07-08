/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 16:59:45 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_camera	*camera_new_init(t_window *win)
{
	t_camera *ret;

	if ((ret = (t_camera *)malloc(sizeof(t_camera))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	ret->transform = trs_new_init();
	ret->fov = 70;
	ret->z_bounds.x = 0.01f;
	ret->z_bounds.y = 1000.0f;
	ret->size.x = win->width;
	ret->size.y = win->height;
	ret->is_dirty = TRUE;
	m4f_perspective(ret);
	ft_pushback_array(win->cams, &ret, sizeof(t_camera *));
	return (ret);
}

t_camera	*camera_new(t_window *win,
			t_projection_type project,
			t_transform *transform)
{
	t_camera *ret;

	if ((ret = (t_camera *)malloc(sizeof(t_camera))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	ret->transform = transform;
	ret->fov = 70;
	ret->z_bounds.x = 0.01f;
	ret->z_bounds.y = 1000.0f;
	ret->size.x = win->width;
	ret->size.y = win->height;
	ret->is_dirty = TRUE;
	if (project == PERSPECTIVE)
		m4f_perspective(ret);
	else
		m4f_identity(&ret->projection);
	ft_pushback_array(win->cams, &ret, sizeof(t_camera *));
	return (ret);
}

void		camera_set_projection(t_camera *camera, t_projection_type project)
{
	if (project == PERSPECTIVE)
		m4f_perspective(camera);
	else
		m4f_identity(&camera->projection);
	camera->project_type = project;
	camera->is_dirty = TRUE;
}

t_matrix4f	*camera_get_matrix(t_camera *camera)
{
	if (camera->is_dirty || camera->transform->is_dirty)
		camera_recalculate_matrix(camera);
	return (&camera->projected_view);
}

void		camera_recalculate_matrix(t_camera *camera)
{
	t_matrix4f inverted;
	t_matrix4f projection;

	m4f_cpy(&projection, &camera->projection);
	m4f_invert(m4f_cpy(&inverted, trs_get_matrix(camera->transform)));
	m4f_cpy(&camera->projected_view, m4f_mul(&projection, &inverted));
	camera->is_dirty = FALSE;
}
