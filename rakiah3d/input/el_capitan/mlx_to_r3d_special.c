/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_to_r3d_special.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:43:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 18:43:40 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_keycode	special_0(int keycode)
{
	if (keycode == 117)
		return (INSERT);
	if (keycode == 115)
		return (HOME);
	if (keycode == 119)
		return (END);
	if (keycode == 116)
		return (PAGE_UP);
	if (keycode == 121)
		return (PAGE_DOWN);
	if (keycode == 18)
		return (EXCLAIM);
	if (keycode == 39)
		return (DOUBLE_QUOTE);
	if (keycode == 20)
		return (HASH);
	if (keycode == 21)
		return (DOLLAR);
	if (keycode == 26)
		return (AMPERSAND);
	if (keycode == 39)
		return (QUOTE);
	return (0);
}

t_keycode	special_1(int keycode)
{
	if (keycode == 25)
		return (LEFT_PAREN);
	if (keycode == 29)
		return (RIGHT_PAREN);
	if (keycode == 28)
		return (ASTERISK);
	if (keycode == 24)
		return (PLUS);
	if (keycode == 43)
		return (COMMA);
	if (keycode == 27)
		return (MINUS);
	if (keycode == 23)
		return (PERIOD);
	if (keycode == 44)
		return (SLASH);
	if (keycode == 41)
		return (COLON);
	if (keycode == 41)
		return (SEMICOLON);
	if (keycode == 43)
		return (LESS);
	return (0);
}

t_keycode	special_2(int keycode)
{
	if (keycode == 272)
		return (SCROLL_LOCK);
	if (keycode == 272)
		return (RIGHT_SHIFT);
	if (keycode == 258)
		return (LEFT_SHIFT);
	if (keycode == 257)
		return (LEFT_CONTROL);
	if (keycode == 256)
		return (RIGHT_ALT);
	if (keycode == 261)
		return (LEFT_ALT);
	if (keycode == 262)
		return (LEFT_COMMAND);
	if (keycode == 259)
		return (LEFT_APPLE);
	if (keycode == 260)
		return (RIGHT_COMMAND);
	if (keycode == 260)
		return (RIGHT_APPLE);
	return (0);
}

t_keycode	special_3(int keycode)
{
	if (keycode == 65407)
		return (NUM_LOCK);
	if (keycode == 65509)
		return (CAPS_LOCK);
	if (keycode == 65515)
		return (RIGHT_WINDOWS);
	if (keycode == 65515)
		return (ALTGR);
	if (keycode == 65514)
		return (HELP);
	if (keycode == 65383)
		return (PRINT);
	if (keycode == 65377)
		return (SYSREQ);
	if (keycode == 65377)
		return (BREAK);
	if (keycode == 65300)
		return (MENU);
	return (0);
}

t_keycode	special_4(int keycode)
{
	if (keycode == 61)
		return (EQUALS);
	if (keycode == 46)
		return (GREATER);
	if (keycode == 47)
		return (QUESTION);
	if (keycode == 50)
		return (AT);
	if (keycode == 91)
		return (LEFT_BRACKET);
	if (keycode == 47)
		return (BACK_SLASH);
	if (keycode == 93)
		return (RIGHT_BRACKET);
	if (keycode == 54)
		return (CARET);
	if (keycode == 45)
		return (UNDER_SCORE);
	if (keycode == 39)
		return (BACK_QUOTE);
	return (0);
}
