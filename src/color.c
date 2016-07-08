/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/23 02:18:13 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 15:26:50 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		get_color(int iteration, t_palette *palette)
{
	int color;

	iteration = sin(iteration) * 100;
	color = palette->normal;
	if (iteration < 0)
		color = palette->color_0;
	else if (iteration >= 0 && iteration < 10)
		color = palette->color_1;
	else if (iteration >= 10 && iteration < 20)
		color = palette->color_2;
	else if (iteration >= 20 && iteration < 50)
		color = palette->color_3;
	else if (iteration >= 50 && iteration < 60)
		color = palette->color_4;
	else if (iteration >= 60 && iteration < 65)
		color = palette->color_5;
	else if (iteration >= 65 && iteration < 70)
		color = palette->color_6;
	else if (iteration >= 70 && iteration < 80)
		color = palette->color_7;
	else if (iteration >= 80 && iteration < 90)
		color = palette->color_8;
	else if (iteration >= 90)
		color = palette->color_9;
	return (color);
}
