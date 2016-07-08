/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r3d.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:10:22 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 14:10:56 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R3D_H
# define R3D_H

# include "libft.h"
# include "r3d_typedefs.h"
# include "r3d_defines.h"
# include "r3d_enums.h"
# include "r3d_structs.h"
# include "r3d_input.h"
# include "r3d_loader.h"
# include <mlx.h>
# include <math.h>

/*
**	MATRIX4F METHODS
*/
void			m4f_print(t_matrix4f *matrix);
void			m4f_identity(t_matrix4f *matrix);
void			m4f_translate(t_matrix4f *matrix, float x, float y, float z);
void			m4f_rotate(t_matrix4f *matrix, float x, float y, float z);
void			m4f_scale(t_matrix4f *matrix, float x, float y, float z);
void			m4f_screen_space(t_matrix4f *m, float width, float height);
void			m4f_perspective(t_camera *camera);
float			m4f_get_determinant(t_matrix4f *m);
void			m4f_adjugate(t_matrix4f *m);
void			m4f_invert(t_matrix4f *m);
t_matrix4f		*m4f_cpy(t_matrix4f *dst, t_matrix4f *src);
t_matrix4f		*m4f_new();
t_matrix4f		*m4f_mul(t_matrix4f *m1, t_matrix4f *m2);
t_matrix4f		*m4f_mul_new(t_matrix4f *m1, t_matrix4f *m2);
/*
**	VECTOR4F METHODS
*/
float			v4f_length(t_vector4f *vector);
float			v4f_dot(t_vector4f *v1, t_vector4f *v2);
float			v4f_get_at(t_vector4f *v, int index);
void			v4f_print(t_vector4f *vector);
void			v4f_normalize(t_vector4f *vector);
void			v4f_rotate(t_vector4f *vector, float angle);
void			v4f_add(t_vector4f *v1, t_vector4f *v2);
void			v4f_sub(t_vector4f *v1, t_vector4f *v2);
void			v4f_mul(t_vector4f *v1, t_vector4f *v2);
void			v4f_div(t_vector4f *v1, t_vector4f *v2);
void			v4f_set(t_vector4f *v, float x, float y, float z);
void			v4f_cpy(t_vector4f *dst, t_vector4f *src);
t_vector4f		*v4f_lerp(t_vector4f *v1,
							t_vector4f *v2,
							t_vector4f *dst,
							float lerp_factor);
t_vector4f		*v4f_new(float x, float y, float z, float w);
t_vector4f		*v4f_new_cpy(t_vector4f *src);
t_vector4f		*v4f_add_new(t_vector4f *v1, t_vector4f *v2);
t_vector4f		*v4f_sub_new(t_vector4f *v1, t_vector4f *v2);
t_vector4f		*v4f_mul_new(t_vector4f *v1, t_vector4f *v2);
t_vector4f		*v4f_div_new(t_vector4f *v1, t_vector4f *v2);
t_vector4f		*v4f_cross(t_vector4f *v1, t_vector4f *v2);
/*
**	VECTOR3F METHODS
*/
float			v3f_length(t_vector3f *vector);
float			v3f_dot(t_vector3f *v1, t_vector3f *v2);
void			v3f_print(t_vector3f *vector);
void			v3f_normalize(t_vector3f *vector);
void			v3f_rotate(t_vector3f *vector, float angle);
void			v3f_add(t_vector3f *v1, t_vector3f *v2);
void			v3f_sub(t_vector3f *v1, t_vector3f *v2);
void			v3f_mul(t_vector3f *v1, t_vector3f *v2);
void			v3f_div(t_vector3f *v1, t_vector3f *v2);
void			v3f_set(t_vector3f *v, float x, float y, float z);
void			v3f_cpy(t_vector3f *dst, t_vector3f *src);
t_vector3f		*v3f_lerp(t_vector3f *v1,
							t_vector3f *v2,
							t_vector3f *dst,
							float lerp_factor);
t_vector3f		*v3f_new(float x, float y, float z);
t_vector3f		*v3f_new_cpy(t_vector3f *src);
t_vector3f		*v3f_add_new(t_vector3f *v1, t_vector3f *v2);
t_vector3f		*v3f_sub_new(t_vector3f *v1, t_vector3f *v2);
t_vector3f		*v3f_mul_new(t_vector3f *v1, t_vector3f *v2);
t_vector3f		*v3f_div_new(t_vector3f *v1, t_vector3f *v2);
t_vector3f		*v3f_cross(t_vector3f *v1, t_vector3f *v2);
/*
**	VECTOR2F METHODS
*/
float			v2f_length(t_vector2f *vector);
float			v2f_dot(t_vector2f *v1, t_vector2f *v2);
void			v2f_print(t_vector2f *vector);
void			v2f_normalize(t_vector2f *vector);
void			v2f_rotate(t_vector2f *vector, float angle);
void			v2f_add(t_vector2f *v1, t_vector2f *v2);
void			v2f_sub(t_vector2f *v1, t_vector2f *v2);
void			v2f_mul(t_vector2f *v1, t_vector2f *v2);
void			v2f_div(t_vector2f *v1, t_vector2f *v2);
void			v2f_set(t_vector2f *v, float x, float y);
void			v2f_cpy(t_vector2f *dst, t_vector2f *src);
t_vector2f		*v2f_lerp(t_vector2f *v1,
							t_vector2f *v2,
							t_vector2f *dst,
							float lerp_factor);
t_vector2f		*v2f_new(float x, float y);
t_vector2f		*v2f_new_cpy(t_vector2f *src);
t_vector2f		*v2f_add_new(t_vector2f *v1, t_vector2f *v2);
t_vector2f		*v2f_sub_new(t_vector2f *v1, t_vector2f *v2);
t_vector2f		*v2f_mul_new(t_vector2f *v1, t_vector2f *v2);
t_vector2f		*v2f_div_new(t_vector2f *v1, t_vector2f *v2);
/*
**	QUATERNION METHODS
*/
void			quat_print(t_quaternion *q);
void			quat_normalize(t_quaternion *q);
float			quat_length(t_quaternion *q);
t_quaternion	*conjugage(t_quaternion *q);
t_quaternion	*quat_new(float x, float y, float z, float w);
t_quaternion	*quat_mul_quat_new(t_quaternion *q1, t_quaternion *q2);
t_quaternion	*quat_mul_v3f_new(t_quaternion *q, t_vector3f *v);
/*
**	TRANSFORM METHODS
*/
t_transform		*trs_new_init();
t_transform		*trs_new(t_vector3f *translation,
							t_vector3f *rotation,
							t_vector3f *scale);
t_vector4f		*trs_transform_point(t_matrix4f *m, t_vector4f *v);
t_matrix4f		*trs_get_matrix(t_transform *trs);
void			trs_recalculate_matrix(t_transform *trs);
void			trs_set_pos(t_transform *trs, t_vector3f *new_pos);
void			trs_set_rot(t_transform *trs, t_vector3f *new_rot);
void			trs_set_scale(t_transform *trs, t_vector3f *new_scale);
void			trs_translate(t_transform *trs, t_vector3f *new_pos);
void			trs_rotate(t_transform *trs, t_vector3f *new_rot);
void			trs_scale(t_transform *trs, t_vector3f *new_scale);
/*
**	ENV METHODS
*/

t_core			*get_core(void);
t_window		*core_select_window(int win);
void			core_init(void (*update)(),
				void (*expose)(t_window *),
				void (*postrender)(),
				int framerate);
void			core_add_loader(t_floader loader, char *extension);
void			core_start();
void			core_render();
/*
**	WINDOW METHODS
*/
t_window		*window_new(int x, int y, char *title);
void			clear_z_buffer(t_window *win);
/*
**	CAMERA METHODS
*/
t_camera		*camera_new_init(t_window *win);
t_camera		*camera_new(t_window *win,
							t_projection_type type,
							t_transform *transform);
t_matrix4f		*camera_get_matrix(t_camera *camera);
void			camera_set_projection(t_camera *camera,
						t_projection_type project);
void			camera_recalculate_matrix(t_camera *camera);
/*
**	MESH METHODS
*/
t_mesh			*mesh_new_init();
void			mesh_draw(t_mesh *mesh, t_transform *trs);
void			mesh_print(t_mesh *mesh);
/*
**	RENDERING METHODS
*/
void			normalise_point(t_vector4f *vector);
void			draw_triangle(t_vertex *verts[3], t_material *mat);
void			draw_scan_line(t_line *lines[2],
					int y,
					t_material *mat);
void			clip_triangle(t_vertex *verts[3],
					t_material *mat);
void			triangle_to_lines(t_vertex *verts[3],
									t_material *mat);
t_bool			calculate_triangle_side(t_vector4f *a,
										t_vector4f *b,
										t_vector4f *c);
/*
**	LINE RENDERING METHODS
*/
void			draw_line(t_vector4f *a, t_vector4f *b);
void			draw_between_line(t_line *lines[2],
									t_bool swap,
									t_material *mat);
void			line_setup(t_line *l,
							t_vertex *pts[2],
							t_interpolant ipls[3],
							int min_index);
void			line_do_step(t_line *l);
/*
**	OBJECTS METHODS
*/
t_object		*obj_new_init(t_window *win);
t_object		*obj_new_init_mesh(t_window *win, t_mesh *mesh);
t_object		*obj_new(t_window *win, t_mesh *mesh, t_transform *trs);
void			obj_draw(t_object *obj);
/*
**	VERTEX METHODS
*/
t_vertex		*vertex_new(t_vector4f *pos,
							t_vector2f *tex_coords,
							t_vector3f *normals);
t_vertex		*vertex_new_cpy(t_vertex *vertex);
t_vertex		*vertex_lerp(t_vertex *v1,
								t_vertex *v2,
								t_vertex *dst,
								float lerp_factor);
t_bool			vertex_inside_frustum(t_vertex *v);
/*
**	INTERPOLANT METHODS
*/
void			ipl_set_rendering(t_interpolant ipls[INTERPOLANTS_COUNT],
								t_vertex *verts[3]);
void			ipl_calculate_steps(t_interpolant *ipl,
									t_vector4f *min,
									t_vector4f *mid,
									t_vector4f *max);

t_interpolant	*ipl_set_values(t_interpolant *ipl,
								float x,
								float y,
								float z);
t_interpolant	*ipl_new(float values[3],
							t_vector4f *min,
							t_vector4f *mid,
							t_vector4f *max);
/*
**	TEXTURE METHODS
*/
t_texture		*tex_new(int width, int height);
void			tex_clear(t_texture *tex);
void			tex_draw_pixel(t_texture *tex, int x, int y, int pixel);
void			tex_draw_pixel_index(t_texture *tex, int index, int pixel);
void			tex_to_screen(t_texture *tex, t_core *core);
int				tex_get_pixel(t_texture *tex, int x, int y);
unsigned char	get_pixel_component(int pixel, int index);
int				create_pixel(unsigned char a,
								unsigned char r,
								unsigned char g,
								unsigned char b);
/*
**	MATERIAL METHODS
*/
t_material		*mat_new(t_texture *tex);
/*
**	ERROR GESTIONS METHODS
*/
void			error_exit(char *error);
/*
**	INTERNAL METHODS
*/
int				internal_update(t_core *core);
int				internal_key_down_hook(int code, t_window *win);
int				internal_key_up_hook(int code, t_window *win);
int				internal_mouse_down_hook(int code, int x, int y, t_window *win);
int				internal_mouse_up_hook(int code, int x, int y, t_window *win);
int				internal_mouse_pos_hook(int x, int y, t_window *win);
int				internal_expose_hook(t_window *win);
int				internal_focus_in_hook(t_window *win);
#endif
