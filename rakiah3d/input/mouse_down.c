/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_down.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 04:53:52 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 14:09:27 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

int		internal_mouse_down_hook(int keycode, int x, int y, t_window *win)
{
	core_select_window(win->id);
	keycode = mlx_to_r3d_mbutton(keycode);
	if (keycode < 0 || keycode > MOUSEBUTTON_COUNT)
		return (0);
	mouse_down(keycode, CMD_SET, TRUE);
	mouse_pos(x, y, CMD_SET);
	return (0);
}

int		get_last_mouse_down(void)
{
	return (mouse_down(-1, CMD_GET_LAST, FALSE));
}

t_bool	get_mouse_button_down(int code)
{
	if (code < 0 || code > MOUSEBUTTON_COUNT)
		return (FALSE);
	return ((t_bool)mouse_down(code, CMD_GET, FALSE));
}

int		mouse_down(int mousebutton, t_input_cmd cmd, t_bool value)
{
	static t_bool	*button = NULL;
	static int		last_button = -1;

	if (button == NULL)
		button = (t_bool *)ft_memalloc(MOUSEBUTTON_COUNT * sizeof(t_bool));
	if (cmd == CMD_SET_ALL)
	{
		mousebutton = 0;
		while (mousebutton < MOUSEBUTTON_COUNT)
			button[mousebutton++] = value;
		last_button = -1;
	}
	else if (cmd == CMD_SET)
	{
		last_button = mousebutton;
		button[mousebutton] = value;
	}
	else if (cmd == CMD_GET)
	{
		if (mousebutton == MOUSEBUTTON_COUNT && last_button != -1)
			return (TRUE);
		return (button[mousebutton]);
	}
	return (last_button);
}
