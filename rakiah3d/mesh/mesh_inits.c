/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_inits.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 06:33:01 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 17:10:53 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_mesh	*mesh_new_init(void)
{
	t_mesh	*ret;

	if ((ret = (t_mesh *)malloc(sizeof(t_mesh))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	ret->indexs = NULL;
	ret->vertices = NULL;
	ret->v_count = 0;
	ret->draw_hypotenuses = TRUE;
	ret->wireframe_mode = FALSE;
	ret->material = mat_new(NULL);
	return (ret);
}
