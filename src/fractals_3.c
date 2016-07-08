/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:52:47 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 15:55:45 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		cubedelbrot(t_fractal *f, t_palette *palette, int x, int y)
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
		f->z.r = f->z.r * f->z.r * f->z.r -
		3 * f->z.r * f->z.i * f->z.i + f->c.r;
		f->z.i = 3 * xtmp * xtmp * f->z.i -
		f->z.i * f->z.i * f->z.i + f->c.i;
		j++;
	}
	if (j == f->iter)
		return (get_color(f->iter, palette));
	return (get_color((j * j) * 0.1f, palette));
}

void	cubedelbrot_init(t_fractal *f)
{
	f->name = ft_strdup("cubedelbrot");
	f->method = &cubedelbrot;
	f->x1 = -2.1f;
	f->y1 = -1.2f;
	f->zoom = ZOOM;
	f->zoom_factor = ZOOM;
	f->iter = ITERATION;
}

int		mandelmult(t_fractal *f, t_palette *palette, int x, int y)
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
		f->z.r = (f->z.r * f->z.r) - (f->z.i * f->z.i) + f->c.r;
		f->z.i = 4 * f->z.i * xtmp + f->c.i;
		j++;
	}
	if (j == f->iter)
		return (get_color(f->iter, palette));
	return (get_color((j * j) * 0.1f, palette));
}

void	mandelmult_init(t_fractal *f)
{
	f->name = ft_strdup("mandelmult");
	f->method = &mandelmult;
	f->x1 = -2.1f;
	f->y1 = -1.2f;
	f->zoom = ZOOM;
	f->zoom_factor = ZOOM;
	f->iter = ITERATION;
}
