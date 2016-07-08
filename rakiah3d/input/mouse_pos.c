/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 04:55:55 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/25 15:17:02 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

int			internal_mouse_pos_hook(int x, int y, t_window *win)
{
	core_select_window(win->id);
	mouse_pos(x, y, CMD_SET);
	return (0);
}

t_vector2f	get_mouse_pos(void)
{
	return (mouse_pos(0, 0, CMD_GET));
}

t_vector2f	mouse_pos(int x, int y, t_input_cmd cmd)
{
	static t_vector2f ret;

	if (cmd == CMD_SET)
	{
		ret.x = x;
		ret.y = y;
	}
	else if (cmd == CMD_GET)
		return (ret);
	return (ret);
}
