/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 15:53:03 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 15:56:51 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int		quadia(t_fractal *f, t_palette *palette, int x, int y)
{
	int		j;
	float	xtmp;

	f->z.r = x / f->zoom + f->x1;
	f->z.i = y / f->zoom + f->y1;
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

void	quadia_init(t_fractal *f)
{
	f->name = ft_strdup("quadia");
	f->method = &quadia;
	f->x1 = -1.75f;
	f->y1 = -1.2f;
	f->zoom = ZOOM;
	f->zoom_factor = ZOOM;
	f->iter = ITERATION;
}

int		cubia(t_fractal *f, t_palette *palette, int x, int y)
{
	int		j;
	float	xtmp;

	f->z.r = x / f->zoom + f->x1;
	f->z.i = y / f->zoom + f->y1;
	j = 0;
	while (f->z.r * f->z.r + f->z.i * f->z.i < 4 && j < f->iter)
	{
		xtmp = f->z.r;
		f->z.r = f->z.r * f->z.r * f->z.r -
		3 * f->z.r * f->z.i * f->z.i + f->c.r;
		f->z.i = 3 * xtmp * xtmp * f->z.i - f->z.i * f->z.i * f->z.i + f->c.i;
		j++;
	}
	if (j == f->iter)
		return (get_color(f->iter, palette));
	return (get_color((j * j) * 0.1f, palette));
}

void	cubia_init(t_fractal *f)
{
	f->name = ft_strdup("cubia");
	f->method = &cubia;
	f->x1 = -1.75f;
	f->y1 = -1.2f;
	f->zoom = ZOOM;
	f->zoom_factor = ZOOM;
	f->iter = ITERATION;
}
