/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m4f_operators.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 04:01:16 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_matrix4f	*m4f_new(void)
{
	t_matrix4f *ret;

	if ((ret = (t_matrix4f *)malloc(sizeof(t_matrix4f))) == NULL)
		error_exit("MEMORY ALLOCATION FAILED");
	return (ret);
}

t_matrix4f	*m4f_mul(t_matrix4f *m1, t_matrix4f *m2)
{
	t_matrix4f	tmp;
	int			x;
	int			y;

	m4f_cpy(&tmp, m1);
	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			m1->m[x][y] = tmp.m[x][0] * m2->m[0][y] +
							tmp.m[x][1] * m2->m[1][y] +
							tmp.m[x][2] * m2->m[2][y] +
							tmp.m[x][3] * m2->m[3][y];
			y++;
		}
		x++;
	}
	return (m1);
}

t_matrix4f	*m4f_cpy(t_matrix4f *dst, t_matrix4f *src)
{
	int x;
	int y;

	x = 0;
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			dst->m[x][y] = src->m[x][y];
			y++;
		}
		x++;
	}
	return (dst);
}

t_matrix4f	*m4f_mul_new(t_matrix4f *m1, t_matrix4f *m2)
{
	t_matrix4f	*new;
	int			x;
	int			y;

	x = 0;
	y = 0;
	new = m4f_new();
	while (x < 4)
	{
		y = 0;
		while (y < 4)
		{
			new->m[x][y] = m1->m[x][0] * m2->m[0][y] +
							m1->m[x][1] * m2->m[1][y] +
							m1->m[x][2] * m2->m[2][y] +
							m1->m[x][3] * m2->m[3][y];
			y++;
		}
		x++;
	}
	return (new);
}
