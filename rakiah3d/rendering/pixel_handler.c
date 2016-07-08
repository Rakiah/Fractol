/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 05:20:34 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 05:21:03 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

int				create_pixel(unsigned char a,
			unsigned char r,
			unsigned char g,
			unsigned char b)
{
	return ((a << 24) | (r << 16) | (g << 8) | (b));
}

unsigned char	get_pixel_component(int pixel, int index)
{
	return ((pixel >> (8 * index)));
}
