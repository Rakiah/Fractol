/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_to_r3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/22 15:41:16 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_keycode	f_touch(int keycode)
{
	if (keycode == 96)
		return (F1);
	if (keycode == 120)
		return (F2);
	if (keycode == 99)
		return (F3);
	if (keycode == 118)
		return (F4);
	if (keycode == 96)
		return (F5);
	if (keycode == 97)
		return (F6);
	if (keycode == 98)
		return (F7);
	if (keycode == 100)
		return (F8);
	if (keycode == 101)
		return (F9);
	if (keycode == 109)
		return (F10);
	if (keycode == 111)
		return (F11);
	return (0);
}

t_keycode	controls(int keycode)
{
	if (keycode == 51)
		return (BACK_SPACE);
	if (keycode == 48)
		return (TAB);
	if (keycode == 117)
		return (DELETE);
	if (keycode == 117)
		return (CLEAR);
	if (keycode == 36)
		return (RETURN);
	if (keycode == 35)
		return (PAUSE);
	if (keycode == 53)
		return (ESCAPE);
	if (keycode == 49)
		return (SPACE);
	if (keycode == 126)
		return (UP_ARROW);
	if (keycode == 125)
		return (DOWN_ARROW);
	if (keycode == 124)
		return (RIGHT_ARROW);
	if (keycode == 123)
		return (LEFT_ARROW);
	return (0);
}

t_keycode	alpha_num(int keycode)
{
	if (keycode == 29)
		return (ALPHA0);
	if (keycode == 18)
		return (ALPHA1);
	if (keycode == 19)
		return (ALPHA2);
	if (keycode == 20)
		return (ALPHA3);
	if (keycode == 21)
		return (ALPHA4);
	if (keycode == 23)
		return (ALPHA5);
	if (keycode == 22)
		return (ALPHA6);
	if (keycode == 26)
		return (ALPHA7);
	if (keycode == 28)
		return (ALPHA8);
	if (keycode == 25)
		return (ALPHA9);
	return (0);
}

t_keycode	mlx_to_r3d_key(int keycode)
{
	enum e_keycode ret;

	if ((ret = keypad_numbers(keycode)) ||
	(ret = keypad_operators(keycode)) ||
	(ret = f_touch(keycode)) ||
	(ret = controls(keycode)) ||
	(ret = alpha_num(keycode)) ||
	(ret = alphabet_0(keycode)) ||
	(ret = alphabet_1(keycode)) ||
	(ret = alphabet_2(keycode)) ||
	(ret = special_0(keycode)) ||
	(ret = special_1(keycode)) ||
	(ret = special_2(keycode)) ||
	(ret = special_3(keycode)) ||
	(ret = special_4(keycode)))
		return (ret);
	return (NONE);
}

int			mlx_to_r3d_mbutton(int keycode)
{
	return (keycode);
}
