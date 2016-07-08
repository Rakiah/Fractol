/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_model.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 07:04:05 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 18:20:16 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"
#include "get_next_line.h"

static	t_obj_index		*parse_index(char *token)
{
	int			i;
	t_obj_index	*obj_index;
	char		**sub_tokens;

	if ((obj_index = malloc(sizeof(t_obj_index))) == NULL)
		error_exit("MEMORY ALLOCAITON FAILED");
	sub_tokens = ft_strsplit(token, '/', NULL);
	obj_index->i[0] = -1;
	obj_index->i[1] = -1;
	obj_index->i[2] = -1;
	i = 0;
	while (sub_tokens[i] != NULL)
	{
		obj_index->i[i] = ft_atoi(sub_tokens[i]) - 1;
		free(sub_tokens[i++]);
	}
	free(sub_tokens);
	return (obj_index);
}

static void				parse_face_line(t_list *index, char **split, int *count)
{
	int			i;
	t_obj_index	*tmp;

	index = ft_lst_get_end(index);
	i = 0;
	while (i < 3)
	{
		tmp = parse_index(split[i + 1]);
		index->next = ft_lstnew(&tmp, sizeof(t_obj_index *));
		index = index->next;
		(*count)++;
		i++;
	}
}

static void				parse_coord(t_list *p,
									t_list *t,
									t_list *n,
									char **split)
{
	void *parsed;

	if (split[0][1] == '\0')
	{
		p = ft_lst_get_end(p);
		parsed = v4f_new(strtod(split[1], NULL),
				strtod(split[2], NULL),
				strtod(split[3], NULL), 1.0f);
		p->next = ft_lstnew(&parsed, sizeof(t_vector4f *));
	}
	else if (split[0][1] == 't')
	{
		t = ft_lst_get_end(t);
		parsed = v2f_new(strtod(split[1], NULL),
				strtod(split[2], NULL));
		t->next = ft_lstnew(&parsed, sizeof(t_vector2f *));
	}
	else if (split[0][1] == 'n')
	{
		n = ft_lst_get_end(n);
		parsed = v3f_new(strtod(split[1], NULL),
				strtod(split[2], NULL),
				strtod(split[3], NULL));
		n->next = ft_lstnew(&parsed, sizeof(t_vector3f *));
	}
}

static t_obj_model		*obj_model_init(t_list *lst[4], int count)
{
	t_obj_model *ret;

	if ((ret = malloc(sizeof(t_obj_model))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	ret->count = count;
	ret->pos = lst[0]->next;
	ret->tex_coords = lst[1]->next;
	ret->normals = lst[2]->next;
	ret->index = lst[3]->next;
	return (ret);
}

t_obj_model				*obj_model_new(int fd)
{
	int			i;
	int			count;
	char		*line;
	t_list		*start[4];

	count = 0;
	i = -1;
	while (++i < 4)
		start[i] = ft_lstnew(NULL, 0);
	while (get_next_line(fd, &line) == 1)
	{
		if (*line == 'v')
			parse_coord(start[0],
						start[1],
						start[2],
						ft_strsplit(line, ' ', NULL));
		else if (*line == 'f')
			parse_face_line(start[3], ft_strsplit(line, ' ', NULL), &count);
	}
	return (obj_model_init(start, count));
}
