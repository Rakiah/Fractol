/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r3d_typedefs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:35:46 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 15:19:59 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R3D_TYPEDEFS_H
# define R3D_TYPEDEFS_H

typedef char				t_bool;
typedef enum e_keycode			t_keycode;
typedef enum e_input_cmd		t_input_cmd;
typedef enum e_projection_type	t_projection_type;
typedef struct s_vector4f		t_vector4f;
typedef struct s_vector3f		t_vector3f;
typedef struct s_vector2f		t_vector2f;
typedef struct s_matrix4f		t_matrix4f;
typedef struct s_quaternion		t_quaternion;
typedef struct s_transform		t_transform;
typedef struct s_camera			t_camera;
typedef struct s_window			t_window;
typedef struct s_core			t_core;
typedef struct s_mesh			t_mesh;
typedef struct s_object			t_object;
typedef struct s_line			t_line;
typedef struct s_vertex			t_vertex;
typedef struct s_interpolant	t_interpolant;
typedef struct s_texture		t_texture;
typedef struct s_material		t_material;
typedef struct s_loader			t_loader;
typedef void *(*t_floader)(char *path);

#endif
