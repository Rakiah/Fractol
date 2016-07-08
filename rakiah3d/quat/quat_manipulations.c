/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quat_manipulations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:10 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 04:38:22 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

float	quat_length(t_quaternion *q)
{
	return ((float)sqrt(q->x * q->x + q->y * q->y + q->z * q->z + q->w * q->w));
}

void	quat_normalize(t_quaternion *q)
{
	float length;

	length = quat_length(q);
	q->x /= length;
	q->y /= length;
	q->z /= length;
	q->w /= length;
}

void	quat_print(t_quaternion *q)
{
	ft_putstr("quaternion values :\n");
	ft_putstr("x = [");
	ft_putnbr(floor(q->x));
	ft_putstr("], y = [");
	ft_putnbr(floor(q->y));
	ft_putstr("], z = [");
	ft_putnbr(floor(q->z));
	ft_putstr("], w = [");
	ft_putnbr(floor(q->w));
	ft_putstr("]\n");
}
