/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:33:47 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_object	*obj_new_init(t_window *win)
{
	t_object *ret;

	if ((ret = (t_object *)malloc(sizeof(t_object))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	ret->transform = trs_new_init();
	ret->mesh = mesh_new_init();
	if (win != NULL)
		ft_pushback_array(win->objs, &ret, sizeof(t_object *));
	return (ret);
}

t_object	*obj_new_init_mesh(t_window *win, t_mesh *mesh)
{
	t_object *ret;

	if ((ret = (t_object *)malloc(sizeof(t_object))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	ret->transform = trs_new_init();
	if (win != NULL)
		ft_pushback_array(win->objs, &ret, sizeof(t_object *));
	ret->mesh = mesh;
	return (ret);
}

t_object	*obj_new(t_window *win, t_mesh *mesh, t_transform *trs)
{
	t_object *ret;

	if ((ret = (t_object *)malloc(sizeof(t_object))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	ret->transform = trs;
	ret->mesh = mesh;
	if (win != NULL)
		ft_pushback_array(win->objs, &ret, sizeof(t_object *));
	return (ret);
}

void		obj_draw(t_object *obj)
{
	if (obj->mesh != NULL)
		mesh_draw(obj->mesh, obj->transform);
}
