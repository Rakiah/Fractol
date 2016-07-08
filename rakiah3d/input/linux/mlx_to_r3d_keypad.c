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
	if (keycode == 65438)
		return (KEYPAD0);
	if (keycode == 65436)
		return (KEYPAD1);
	if (keycode == 65433)
		return (KEYPAD2);
	if (keycode == 65435)
		return (KEYPAD3);
	if (keycode == 65430)
		return (KEYPAD4);
	if (keycode == 65437)
		return (KEYPAD5);
	if (keycode == 65432)
		return (KEYPAD6);
	if (keycode == 65429)
		return (KEYPAD7);
	if (keycode == 65431)
		return (KEYPAD8);
	if (keycode == 65434)
		return (KEYPAD9);
	return (0);
}

t_keycode	keypad_operators(int keycode)
{
	if (keycode == 65439)
		return (KEYPAD_PERIOD);
	if (keycode == 65455)
		return (KEYPAD_DIVIDE);
	if (keycode == 65450)
		return (KEYPAD_MULTIPLY);
	if (keycode == 65453)
		return (KEYPAD_MINUS);
	if (keycode == 65451)
		return (KEYPAD_PLUS);
	if (keycode == 65421)
		return (KEYPAD_ENTER);
	if (keycode == 61)
		return (KEYPAD_EQUALS);
	return (0);
}
