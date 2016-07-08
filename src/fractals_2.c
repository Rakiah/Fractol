/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:52:04 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 15:57:31 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		mandelbrot(t_fractal *f, t_palette *palette, int x, int y)
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
		f->z.i = 2 * f->z.i * xtmp + f->c.i;
		j++;
	}
	if (j == f->iter)
		return (get_color(f->iter, palette));
	return (get_color((j * j) * 0.1f, palette));
}

void	mandelbrot_init(t_fractal *f)
{
	f->name = ft_strdup("mandelbrot");
	f->method = &mandelbrot;
	f->x1 = -2.1f;
	f->y1 = -1.2f;
	f->zoom = ZOOM;
	f->zoom_factor = ZOOM;
	f->iter = ITERATION;
}

int		quadelbrot(t_fractal *f, t_palette *palette, int x, int y)
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
		f->z.r = f->z.r * f->z.r * f->z.r * f->z.r -
		6 * f->z.r * f->z.r * f->z.i * f->z.i +
		f->z.i * f->z.i * f->z.i * f->z.i + f->c.r;
		f->z.i = 4 * xtmp * xtmp * xtmp * f->z.i -
		4 * xtmp * f->z.i * f->z.i * f->z.i + f->c.i;
		j++;
	}
	if (j == f->iter)
		return (get_color(f->iter, palette));
	return (get_color((j * j) * 0.1f, palette));
}

void	quadelbrot_init(t_fractal *f)
{
	f->name = ft_strdup("quadelbrot");
	f->method = &quadelbrot;
	f->x1 = -2.1f;
	f->y1 = -1.2f;
	f->zoom = ZOOM;
	f->zoom_factor = ZOOM;
	f->iter = ITERATION;
}
