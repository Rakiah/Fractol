/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 23:21:16 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 15:54:43 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		tricorn(t_fractal *f, t_palette *palette, int x, int y)
{
	int		j;
	float	xtmp;

	f->c.r = x / f->zoom + f->x1;
	f->c.i = y / f->zoom + f->y1;
	f->z.r = 0;
	f->z.i = 0;
	j = 0;
	while (f->z.r * f->z.r + f->z.i * f->z.i < 4 && j < f->iter)
	{
		xtmp = f->z.r;
		f->z.r = f->z.r * f->z.r - f->z.i * f->z.i + f->c.r;
		f->z.i = -2 * f->z.i * xtmp + f->c.i;
		j++;
	}
	if (j == f->iter)
		return (get_color(f->iter, palette));
	return (get_color((j * j) * 0.1f, palette));
}

void	tricorn_init(t_fractal *f)
{
	f->name = ft_strdup("tricorn");
	f->method = &tricorn;
	f->x1 = -2.3f;
	f->y1 = -1.55f;
	f->zoom = ZOOM / 1.3f;
	f->zoom_factor = ZOOM / 1.3f;
	f->iter = ITERATION;
}
