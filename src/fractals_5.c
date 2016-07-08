/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:53:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 15:53:46 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		julia(t_fractal *f, t_palette *palette, int x, int y)
{
	int		j;
	float	xtmp;

	f->z.r = x / f->zoom + f->x1;
	f->z.i = y / f->zoom + f->y1;
	j = 0;
	while (f->z.r * f->z.r + f->z.i * f->z.i < 4 && j < f->iter)
	{
		xtmp = f->z.r;
		f->z.r = f->z.r * f->z.r - f->z.i * f->z.i + f->c.r;
		f->z.i = 2 * f->z.i * xtmp + f->c.i;
		j++;
	}
	if (j == f->iter)
		return (get_color(f->iter, palette));
	return (get_color((j * j) * 0.1f, palette));
}

void	julia_init(t_fractal *f)
{
	f->name = ft_strdup("julia");
	f->method = &julia;
	f->x1 = -1.75f;
	f->y1 = -1.2f;
	f->zoom = ZOOM;
	f->zoom_factor = ZOOM;
	f->iter = ITERATION;
}

int		burning_ship(t_fractal *f, t_palette *palette, int x, int y)
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
		f->z.i = 2 * fabs(f->z.i * xtmp) + f->c.i;
		j++;
	}
	if (j == f->iter)
		return (get_color(f->iter, palette));
	return (get_color((j * j) * 0.1f, palette));
}

void	burning_ship_init(t_fractal *f)
{
	f->name = ft_strdup("b_ship");
	f->method = &burning_ship;
	f->x1 = -2.3f;
	f->y1 = -1.8f;
	f->zoom = ZOOM;
	f->zoom_factor = ZOOM;
	f->iter = ITERATION;
}
