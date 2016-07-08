/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r3d_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:30:57 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 15:20:38 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R3D_STRUCTS_H
# define R3D_STRUCTS_H

struct					s_vector3f
{
	float				x;
	float				y;
	float				z;
};
struct					s_vector4f
{
	float				x;
	float				y;
	float				z;
	float				w;
};
struct					s_vector2f
{
	float				x;
	float				y;
};
struct					s_interpolant
{
	float				values[3];
	float				x_step;
	float				y_step;
};
struct					s_matrix4f
{
	float				m[4][4];
};
struct					s_quaternion
{
	float				x;
	float				y;
	float				z;
	float				w;
};
struct					s_transform
{
	t_vector3f			position;
	t_vector3f			rotation;
	t_vector3f			scale;
	t_matrix4f			model_world_matrix;
	t_bool				is_dirty;
};
struct					s_texture
{
	void				*img;
	char				*pixels;
	int					bytes_per_pixel;
	int					l_size;
	int					size;
	int					width;
	int					height;
	t_bool				endian;
};
struct					s_camera
{
	float				fov;
	t_vector2f			size;
	t_vector2f			z_bounds;
	t_matrix4f			projection;
	t_matrix4f			projected_view;
	t_transform			*transform;
	t_projection_type	project_type;
	t_bool				is_dirty;
};
struct					s_vertex
{
	t_vector4f			*pos;
	t_vector2f			*tex_coords;
	t_vector3f			*normals;
};
struct					s_line
{
	float				x_curr;
	float				x_step;
	t_interpolant		*ipls[INTERPOLANTS_COUNT];
	int					y_start;
	int					y_end;
	float				ipls_curr[INTERPOLANTS_COUNT];
	float				ipls_step[INTERPOLANTS_COUNT];
};
struct					s_material
{
	t_texture			*texture;
	int					color;
};
struct					s_window
{
	void				*win;
	t_array				*objs;
	t_array				*cams;
	t_camera			*camera;
	t_texture			*screen_tex;
	t_matrix4f			screen_matrix;
	float				**z_buffer;
	int					width;
	int					height;
	int					id;
	t_bool				cancel_render;
};
struct					s_core
{
	void				*mlx;
	t_window			*window;
	t_array				*wins;
	t_array				*loaders;
	void				(*update)();
	void				(*postrender)();
	void				(*expose)(t_window *);
	int					target_framerate;
	int					window_id;
	double				delta_time;
	void				*data;
};
struct					s_mesh
{
	t_vertex			**vertices;
	unsigned int		**indexs;
	t_material			*material;
	size_t				v_count;
	t_bool				draw_hypotenuses;
	t_bool				wireframe_mode;
};
struct					s_object
{
	t_transform			*transform;
	t_mesh				*mesh;
};
struct					s_loader
{
	char				*extension;
	t_floader			method;
};

#endif
