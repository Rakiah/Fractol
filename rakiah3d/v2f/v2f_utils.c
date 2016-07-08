/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v2f_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:44:49 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:47:18 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

void		v2f_set(t_vector2f *v, float x, float y)
{
	v->x = x;
	v->y = y;
}

void		v2f_cpy(t_vector2f *dst, t_vector2f *src)
{
	dst->x = src->x;
	dst->y = src->y;
}

t_vector2f	*v2f_new_cpy(t_vector2f *src)
{
	return (v2f_new(src->x, src->y));
}

t_vector2f	*v2f_lerp(t_vector2f *v1,
			t_vector2f *v2,
			t_vector2f *dst,
			float lerp_factor)
{
	t_vector2f tmp;

	v2f_cpy(&tmp, v2);
	v2f_sub(&tmp, v1);
	tmp.x *= lerp_factor;
	tmp.y *= lerp_factor;
	v2f_add(&tmp, v1);
	v2f_cpy(dst, &tmp);
	return (dst);
}

void		v2f_print(t_vector2f *vector)
{
	ft_putstr("vector2f values :\n");
	ft_putstr("x = [");
	ft_putnbr(floor(vector->x));
	ft_putstr("], y = [");
	ft_putnbr(floor(vector->y));
	ft_putstr("]\n");
}
