/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r3d_loader.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 17:30:11 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 15:19:24 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef R3D_LOADER_H
# define R3D_LOADER_H

typedef	struct s_obj_model	t_obj_model;
typedef struct s_obj_index	t_obj_index;

struct			s_obj_model
{
	int			count;
	int			component_count;
	t_list		*pos;
	t_list		*tex_coords;
	t_list		*normals;
	t_list		*index;
};
struct			s_obj_index
{
	int i[3];
};
t_obj_model		*obj_model_new(int fd);
t_loader		*find_loader(char *ext);
void			*load_obj(char *path);
void			*load_ro(char *path);
void			*load_bitmap(char *path);
void			*load_rs(char *path);
void			*load(char *path);

#endif
