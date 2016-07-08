/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/18 18:28:50 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 18:30:23 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "r3d.h"

t_loader	*find_loader(char *ext)
{
	size_t	i;
	t_core	*core;

	core = get_core();
	if (ext == NULL)
		error_exit("TRYING TO LOAD A FILE WITHOUT EXTENSION");
	i = 0;
	ext++;
	while (i < core->loaders->count)
	{
		if (ft_strequ(ext, ((t_loader **)core->loaders->array)[i]->extension))
			return (((t_loader **)core->loaders->array)[i]);
		i++;
	}
	error_exit(ft_strjoin("NO LOADER FOUND FOR EXTENSION : ", ext));
	return (NULL);
}

void		*load(char *path)
{
	t_loader *loader;

	loader = find_loader(ft_strchr(path, '.'));
	return (loader->method(path));
}
