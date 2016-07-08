/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_to_r3d_keypad.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:45:35 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 18:45:55 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_keycode	keypad_numbers(int keycode)
{
	if (keycode == 82)
		return (KEYPAD0);
	if (keycode == 83)
		return (KEYPAD1);
	if (keycode == 84)
		return (KEYPAD2);
	if (keycode == 85)
		return (KEYPAD3);
	if (keycode == 86)
		return (KEYPAD4);
	if (keycode == 87)
		return (KEYPAD5);
	if (keycode == 88)
		return (KEYPAD6);
	if (keycode == 89)
		return (KEYPAD7);
	if (keycode == 91)
		return (KEYPAD8);
	if (keycode == 92)
		return (KEYPAD9);
	return (0);
}

t_keycode	keypad_operators(int keycode)
{
	if (keycode == 65)
		return (KEYPAD_PERIOD);
	if (keycode == 75)
		return (KEYPAD_DIVIDE);
	if (keycode == 67)
		return (KEYPAD_MULTIPLY);
	if (keycode == 78)
		return (KEYPAD_MINUS);
	if (keycode == 69)
		return (KEYPAD_PLUS);
	if (keycode == 76)
		return (KEYPAD_ENTER);
	if (keycode == 81)
		return (KEYPAD_EQUALS);
	return (0);
}
