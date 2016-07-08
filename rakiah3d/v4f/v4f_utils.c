/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v4f_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:53:47 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 03:54:35 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_vector4f	*v4f_new_cpy(t_vector4f *src)
{
	return (v4f_new(src->x, src->y, src->z, src->w));
}

t_vector4f	*v4f_lerp(t_vector4f *v1,
					t_vector4f *v2,
					t_vector4f *dst,
					float lerp_factor)
{
	t_vector4f tmp;

	v4f_cpy(&tmp, v2);
	v4f_sub(&tmp, v1);
	tmp.x *= lerp_factor;
	tmp.y *= lerp_factor;
	tmp.z *= lerp_factor;
	tmp.w *= lerp_factor;
	v4f_add(&tmp, v1);
	v4f_cpy(dst, &tmp);
	return (dst);
}

void		v4f_cpy(t_vector4f *dst, t_vector4f *src)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
	dst->w = src->w;
}

void		v4f_set(t_vector4f *vector, float x, float y, float z)
{
	vector->x = x;
	vector->y = y;
	vector->z = z;
	vector->w = 1.0f;
}

void		v4f_print(t_vector4f *vector)
{
	ft_putstr("vector4f values :\n");
	ft_putstr("x = [");
	ft_putnbr(floor(vector->x));
	ft_putstr("], y = [");
	ft_putnbr(floor(vector->y));
	ft_putstr("], z = [");
	ft_putnbr(floor(vector->z));
	ft_putstr("], w = [");
	ft_putnbr(floor(vector->w));
	ft_putstr("]\n");
}
