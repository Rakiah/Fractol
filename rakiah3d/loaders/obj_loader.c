/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 07:04:05 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 18:27:30 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"
#include <fcntl.h>

void	create_vertex(t_list *index, t_list *vertices, t_obj_model *model)
{
	t_vertex	*v_tmp;
	t_obj_index	*i_tmp;

	v_tmp = vertex_new(NULL, NULL, NULL);
	i_tmp = *((t_obj_index **)index->content);
	v_tmp->pos = *((t_vector4f **)
			(ft_lstfindbyindex(model->pos,
					i_tmp->i[0])->content));
	if (i_tmp->i[1] >= 0)
		v_tmp->tex_coords = *((t_vector2f **)
				ft_lstfindbyindex(model->tex_coords,
						i_tmp->i[1])->content);
	if (i_tmp->i[2] >= 0)
		v_tmp->normals = *((t_vector3f **)
				ft_lstfindbyindex(model->normals,
						i_tmp->i[2])->content);
	vertices->next = ft_lstnew(&v_tmp, sizeof(t_vertex *));
}

int		arrange_vertices_obj(t_obj_model *model,
								t_list *vertices,
								t_list *index_m)
{
	int				i;
	int				index;
	int				count;
	unsigned int	*tri;
	t_list			*iter;

	count = 0;
	index = 0;
	iter = model->index;
	while (iter != NULL && (i = -1))
	{
		if ((tri = malloc(sizeof(int) * 3)) == NULL)
			error_exit("MEMORY ALLOCTION FAILED");
		while (++i < 3)
		{
			create_vertex(iter, vertices, model);
			vertices = vertices->next;
			iter = iter->next;
			tri[i] = index++;
		}
		index_m->next = ft_lstnew(&tri, sizeof(int *));
		index_m = index_m->next;
		count++;
	}
	return (count);
}

void	*load_obj(char *path)
{
	int			fd;
	t_obj_model	*model;
	t_list		*start[2];
	t_mesh		*mesh;

	mesh = mesh_new_init();
	start[0] = ft_lstnew(NULL, 0);
	start[1] = ft_lstnew(NULL, 0);
	if ((fd = open(path, O_RDONLY)) < 0)
		error_exit(ft_strjoin("COULDN'T FIND FILE AT : ", path));
	model = obj_model_new(fd);
	mesh->v_count = arrange_vertices_obj(model, start[0], start[1]);
	mesh->vertices = (t_vertex **)ft_lst_to_array(start[0]->next,
						ft_lstcount(start[0]->next));
	mesh->indexs = (unsigned int **)ft_lst_to_array(start[1]->next,
													mesh->v_count);
	close(fd);
	return (mesh);
}
