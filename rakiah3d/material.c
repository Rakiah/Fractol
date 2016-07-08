/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 05:05:17 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_material	*mat_new(t_texture *tex)
{
	t_material *ret;

	if ((ret = (t_material *)malloc(sizeof(t_material))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	ret->color = create_pixel(0, 255, 255, 255);
	ret->texture = tex;
	return (ret);
}
