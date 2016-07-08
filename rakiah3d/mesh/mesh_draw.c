/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mesh_draw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 06:31:50 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 17:45:07 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

void	mesh_draw_wireframe_inner(t_mesh *mesh,
				t_matrix4f *model_projection,
				unsigned int *index)
{
	int				j;
	t_vertex		verts[2];

	j = -1;
	while (++j < 3)
	{
		if (!mesh->draw_hypotenuses && j == 2)
			continue ;
		verts[0].pos = trs_transform_point(model_projection,
				((t_vertex *)mesh->vertices[index[j]])->pos);
		verts[1].pos = trs_transform_point(model_projection,
				((t_vertex *)mesh->vertices[index[(j + 1) % 3]])->pos);
		if (vertex_inside_frustum(&verts[0]) &&
			vertex_inside_frustum(&verts[1]))
		{
			normalise_point(verts[0].pos);
			normalise_point(verts[1].pos);
			draw_line(verts[0].pos, verts[1].pos);
		}
		free(verts[0].pos);
		free(verts[1].pos);
	}
}

void	mesh_draw_filled_inner(t_mesh *mesh,
								t_matrix4f *model_projection,
								unsigned int *index)
{
	t_vertex	*send_vertex[3];
	t_vertex	*tmp;
	t_vertex	verts[3];
	int			j;

	j = 0;
	while (j < 3)
	{
		tmp = (t_vertex *)mesh->vertices[index[j]];
		verts[j].pos = trs_transform_point(model_projection, tmp->pos);
		verts[j].tex_coords = tmp->tex_coords;
		send_vertex[j] = &verts[j];
		j++;
	}
	clip_triangle(send_vertex, mesh->material);
	free(verts[0].pos);
	free(verts[1].pos);
	free(verts[2].pos);
}

void	mesh_draw(t_mesh *mesh, t_transform *trs)
{
	size_t			i;
	t_matrix4f		model_projection;
	t_core			*core;

	core = get_core();
	m4f_cpy(&model_projection, camera_get_matrix(core->window->camera));
	m4f_mul(&model_projection, trs_get_matrix(trs));
	i = 0;
	if (mesh->wireframe_mode)
	{
		while (i < mesh->v_count)
			mesh_draw_wireframe_inner(mesh,
										&model_projection,
										(unsigned int *)mesh->indexs[i++]);
	}
	else
	{
		while (i < mesh->v_count)
			mesh_draw_filled_inner(mesh,
									&model_projection,
									(unsigned int *)mesh->indexs[i++]);
	}
}

void	mesh_print(t_mesh *mesh)
{
	size_t					i;
	unsigned int			*tri;

	i = 0;
	while (i < mesh->v_count)
	{
		tri = ((unsigned int **)mesh->indexs)[i];
		ft_putstr("TRI NUMBER ");
		ft_putnbr(i);
		ft_putchar('\n');
		v4f_print(((t_vertex **)mesh->vertices)[tri[0]]->pos);
		v4f_print(((t_vertex **)mesh->vertices)[tri[1]]->pos);
		v4f_print(((t_vertex **)mesh->vertices)[tri[2]]->pos);
		ft_putstr("END TRI\n");
		i++;
	}
}
