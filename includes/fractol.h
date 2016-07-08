/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:02:20 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 16:09:33 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <r3d.h>
# define ITERATION 30
# define ZOOM 330
# define FRACTALS_COUNT 9
# define PALETTES_COUNT 4

typedef struct s_fractal			t_fractal;
typedef struct s_palette			t_palette;
typedef struct s_main_data			t_main_data;
typedef struct s_complex			t_complex;
typedef struct s_fractal_handler	t_fractal_handler;
typedef int	(*t_fractal_meth)(t_fractal *, t_palette *, int, int);

struct				s_complex
{
	double			r;
	double			i;
};

struct				s_fractal
{
	char			*name;
	t_fractal_meth	method;
	double			x1;
	double			y1;
	t_complex		z;
	t_complex		c;
	double			zoom;
	double			zoom_factor;
	int				iter;
};

struct				s_fractal_handler
{
	int				s_f;
	int				s_p;
	t_window		*win;
	t_fractal		fractals[FRACTALS_COUNT];
};

struct				s_palette
{
	int				normal;
	int				color_0;
	int				color_1;
	int				color_2;
	int				color_3;
	int				color_4;
	int				color_5;
	int				color_6;
	int				color_7;
	int				color_8;
	int				color_9;
};

struct				s_main_data
{
	t_array			*fractals_handler;
	t_fractal		fractals[FRACTALS_COUNT];
	t_palette		palettes[PALETTES_COUNT];
	t_bool			mouse_variation;
	t_bool			epileptic;
	float			epileptic_timer;
};

void				redraw_window(t_fractal *fractal, t_palette *palette);
void				draw_fractal(t_fractal *f, t_texture *img);
void				quadelbrot_init(t_fractal *f);
void				cubedelbrot_init(t_fractal *f);
void				mandelbrot_init(t_fractal *f);
void				mandelmult_init(t_fractal *f);
void				quadia_init(t_fractal *f);
void				cubia_init(t_fractal *f);
void				julia_init(t_fractal *f);
void				burning_ship_init(t_fractal *f);
void				tricorn_init(t_fractal *f);
void				squaredbrot_init(t_fractal *f);
void				zoom(t_fractal *f, float value, int iter);
void				handle_mouse_variation(t_fractal *f, t_palette *p);
void				handle_zoom(t_fractal *f, t_palette *p);
void				handle_movement(t_fractal *f, t_palette *p);
void				handle_epileptic(t_main_data *program,
									t_fractal_handler *f_h,
									t_fractal *f);
void				input_handler(t_fractal_handler *f);
void				init_fractales(t_fractal fractals[FRACTALS_COUNT]);
int					get_color(int iter, t_palette *p);
void				show_usage(t_main_data *program);
void				create_fractal_handler(t_main_data *program,
											int i, int j);
void				init_palettes(t_main_data *program);

#endif
