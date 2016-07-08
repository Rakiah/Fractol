/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:55:32 by bkabbas           #+#    #+#             */
/*   Updated: 2015/12/17 18:31:02 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include "libft.h"
# define BUFF_SIZE 4096

typedef	struct	s_filebuffer
{
	int			fd;
	int			current_index;
	t_array		*buffer;
}				t_filebuffer;
int				get_next_line(int const fd, char **line);
int				read_file(t_filebuffer *file,
							t_array *reminder,
							char **line,
							int real_size);
t_filebuffer	*get_filebuffer(int const fd,
								t_array *reminder);
char			*create_line(t_filebuffer *file,
							int length);
void			remove_filebuffer(t_filebuffer *file,
									t_array *reminder);
#endif
