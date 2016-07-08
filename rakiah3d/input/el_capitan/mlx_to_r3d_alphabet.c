/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_to_r3d_alphabet.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:42:50 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 18:42:58 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_keycode	alphabet_0(int keycode)
{
	if (keycode == 0)
		return (A);
	if (keycode == 11)
		return (B);
	if (keycode == 8)
		return (C);
	if (keycode == 2)
		return (D);
	if (keycode == 14)
		return (E);
	if (keycode == 3)
		return (F);
	if (keycode == 5)
		return (G);
	if (keycode == 4)
		return (H);
	if (keycode == 34)
		return (I);
	return (0);
}

t_keycode	alphabet_1(int keycode)
{
	if (keycode == 38)
		return (J);
	if (keycode == 40)
		return (K);
	if (keycode == 37)
		return (L);
	if (keycode == 46)
		return (M);
	if (keycode == 45)
		return (N);
	if (keycode == 31)
		return (O);
	if (keycode == 35)
		return (P);
	if (keycode == 12)
		return (Q);
	if (keycode == 15)
		return (R);
	return (0);
}

t_keycode	alphabet_2(int keycode)
{
	if (keycode == 1)
		return (S);
	if (keycode == 17)
		return (T);
	if (keycode == 32)
		return (U);
	if (keycode == 9)
		return (V);
	if (keycode == 13)
		return (W);
	if (keycode == 7)
		return (X);
	if (keycode == 16)
		return (Y);
	if (keycode == 6)
		return (Z);
	return (0);
}
