/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_to_r3d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/21 18:00:40 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_keycode	f_touch(int keycode)
{
	if (keycode == 65470)
		return (F1);
	if (keycode == 65471)
		return (F2);
	if (keycode == 65472)
		return (F3);
	if (keycode == 65473)
		return (F4);
	if (keycode == 65474)
		return (F5);
	if (keycode == 65475)
		return (F6);
	if (keycode == 65476)
		return (F7);
	if (keycode == 65477)
		return (F8);
	if (keycode == 65478)
		return (F9);
	if (keycode == 65479)
		return (F10);
	if (keycode == 65480)
		return (F11);
	if (keycode == 65481)
		return (F12);
	return (0);
}

t_keycode	controls(int keycode)
{
	if (keycode == 65288)
		return (BACK_SPACE);
	if (keycode == 65289)
		return (TAB);
	if (keycode == 65535)
		return (DELETE);
	if (keycode == 65535)
		return (CLEAR);
	if (keycode == 65293)
		return (RETURN);
	if (keycode == 65299)
		return (PAUSE);
	if (keycode == 65307)
		return (ESCAPE);
	if (keycode == 32)
		return (SPACE);
	if (keycode == 65362)
		return (UP_ARROW);
	if (keycode == 65364)
		return (DOWN_ARROW);
	if (keycode == 65363)
		return (RIGHT_ARROW);
	if (keycode == 65361)
		return (LEFT_ARROW);
	return (0);
}

t_keycode	alpha_num(int keycode)
{
	if (keycode == 48)
		return (ALPHA0);
	if (keycode == 49)
		return (ALPHA1);
	if (keycode == 50)
		return (ALPHA2);
	if (keycode == 51)
		return (ALPHA3);
	if (keycode == 52)
		return (ALPHA4);
	if (keycode == 53)
		return (ALPHA5);
	if (keycode == 54)
		return (ALPHA6);
	if (keycode == 55)
		return (ALPHA7);
	if (keycode == 56)
		return (ALPHA8);
	if (keycode == 57)
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
