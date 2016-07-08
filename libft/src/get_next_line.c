/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 13:49:53 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 17:00:27 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_filebuffer	*get_filebuffer(int const fd, t_array *reminder)
{
	int				i;
	t_filebuffer	*filebuf;

	i = 0;
	while (i < (int)reminder->count)
	{
		filebuf = ((t_filebuffer **)reminder->array)[i];
		if (fd == filebuf->fd)
			return (filebuf);
		i++;
	}
	if (read(fd, NULL, 0) == -1)
		return (NULL);
	if ((filebuf = ft_memalloc(sizeof(t_filebuffer))) == NULL)
		return (NULL);
	if ((filebuf->buffer = ft_create_array(sizeof(char))) == NULL)
		return (NULL);
	filebuf->fd = fd;
	filebuf->current_index = i;
	ft_pushback_array(reminder, &filebuf, sizeof(t_filebuffer *));
	return (filebuf);
}

char			*create_line(t_filebuffer *file, int length)
{
	char		*str;
	char		*cleanchar;

	if ((str = ft_strnew(length)) == NULL)
		return (NULL);
	ft_strncpy(str, (char *)file->buffer->array, length);
	cleanchar = ft_strtrimrchar(str, '\n');
	ft_delrange_at_array(file->buffer, 0, length + (*str == '\n' ? 0 : 1));
	free(str);
	return (cleanchar);
}

void			remove_filebuffer(t_filebuffer *file,
									t_array *reminder)
{
	int		index;

	index = file->current_index;
	if (file == NULL || file->buffer == NULL || reminder == NULL)
		return ;
	ft_del_at_array(reminder, index);
}

int				read_file(t_filebuffer *file,
						t_array *reminder,
						char **line,
						int real_size)
{
	int		read_ret;
	char	*end;
	char	*buffer;

	buffer = ft_memalloc(BUFF_SIZE + 1);
	while ((read_ret = read(file->fd, buffer, BUFF_SIZE)) > 0)
	{
		ft_pushback_array(file->buffer, buffer, read_ret);
		if (*(end = ft_strchrnul(buffer, '\n')) == '\n')
		{
			real_size += (end - buffer);
			if (end == buffer && real_size == 0)
				real_size++;
			break ;
		}
		real_size += read_ret;
	}
	free(buffer);
	if (read_ret == -1 || real_size <= 0)
	{
		remove_filebuffer(file, reminder);
		return (read_ret == -1 ? -1 : 0);
	}
	*line = create_line(file, real_size);
	return (*line == NULL ? -1 : 1);
}

int				get_next_line(int const fd, char **line)
{
	t_filebuffer	*file;
	char			*end;
	int				real_size;
	static t_array	*reminder = NULL;

	if (reminder == NULL)
		reminder = ft_create_array(sizeof(t_filebuffer *));
	if (fd < 0 || line == NULL)
		return (-1);
	if ((file = get_filebuffer(fd, reminder)) == NULL)
		return (-1);
	if (file->buffer->count > 0)
	{
		end = ft_strnchr(file->buffer->array, '\n', file->buffer->count);
		if (end != NULL && *end == '\n')
		{
			*line = create_line(file, end - ((char *)file->buffer->array));
			if (*line != NULL)
				return (1);
			return (-1);
		}
	}
	real_size = file->buffer->count;
	return (read_file(file, reminder, line, real_size));
}
