/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_drawing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 21:03:38 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 15:14:24 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

void	calculate_increment(int increment[2],
							int diff[2],
							t_vector4f *a,
							t_vector4f *b)
{
	int i;

	diff[0] = b->x - a->x;
	diff[1] = b->y - a->y;
	i = -1;
	while (++i < 2)
		if (diff[i] > 0)
			increment[i] = 1;
		else if (diff[i] == 0)
			increment[i] = 0;
		else
			increment[i] = -1;
	diff[0] = ft_abs(diff[0]);
	diff[1] = ft_abs(diff[1]);
}

void	calculate_errors(int increment[2],
						int err[2],
						int bounds[2],
						int pos[2])
{
	if (err[0] >= bounds[1])
	{
		err[0] -= bounds[1];
		pos[0] += increment[0];
	}
	if (err[1] >= bounds[1])
	{
		err[1] -= bounds[1];
		pos[1] += increment[1];
	}
}

void	draw_line(t_vector4f *a, t_vector4f *b)
{
	int bounds[2];
	int err[2];
	int increment[2];
	int diff[2];
	int pos[2];

	ft_memset(err, 0, sizeof(err));
	calculate_increment(increment, diff, a, b);
	bounds[1] = ft_max(diff[0], diff[1]);
	bounds[0] = -1;
	pos[0] = (int)a->x;
	pos[1] = (int)a->y;
	while (++bounds[0] < bounds[1])
	{
		tex_draw_pixel(get_core()->window->screen_tex,
						pos[0], pos[1], 0xFFFFFF);
		err[0] += diff[0];
		err[1] += diff[1];
		calculate_errors(increment, err, bounds, pos);
	}
}
