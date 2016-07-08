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
	if (keycode == 97)
		return (A);
	if (keycode == 98)
		return (B);
	if (keycode == 99)
		return (C);
	if (keycode == 100)
		return (D);
	if (keycode == 101)
		return (E);
	if (keycode == 102)
		return (F);
	if (keycode == 103)
		return (G);
	if (keycode == 104)
		return (H);
	if (keycode == 105)
		return (I);
	return (0);
}

t_keycode	alphabet_1(int keycode)
{
	if (keycode == 106)
		return (J);
	if (keycode == 107)
		return (K);
	if (keycode == 108)
		return (L);
	if (keycode == 109)
		return (M);
	if (keycode == 110)
		return (N);
	if (keycode == 111)
		return (O);
	if (keycode == 112)
		return (P);
	if (keycode == 113)
		return (Q);
	if (keycode == 114)
		return (R);
	return (0);
}

t_keycode	alphabet_2(int keycode)
{
	if (keycode == 115)
		return (S);
	if (keycode == 116)
		return (T);
	if (keycode == 117)
		return (U);
	if (keycode == 118)
		return (V);
	if (keycode == 119)
		return (W);
	if (keycode == 120)
		return (X);
	if (keycode == 121)
		return (Y);
	if (keycode == 122)
		return (Z);
	return (0);
}
