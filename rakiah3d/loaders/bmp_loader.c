/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_loader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/13 02:33:32 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/18 18:31:39 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "r3d.h"

unsigned int				endian_read_int(FILE *file)
{
	unsigned char	b[4];
	unsigned int	i;

	if (fread(b, 1, 4, file) < 4)
		error_exit("BITMAP FILE NOT FORMATTED CORRECTLY");
	i = (b[3] << 24) | (b[2] << 16) | (b[1] << 8) | b[0];
	return (i);
}

static unsigned short int	endian_read_short(FILE *file)
{
	unsigned char	b[2];
	unsigned short	s;

	if (fread(b, 1, 2, file) < 2)
		error_exit("BITMAP FILE NOT FORMATTED CORRECTLY");
	s = (b[1] << 8) | b[0];
	return (s);
}

static t_texture			*create_image(FILE *file)
{
	int	bounds[2];

	fseek(file, 18, SEEK_CUR);
	if (!(bounds[0] = endian_read_int(file)))
		error_exit("BITMAP FILE NOT FORMATTED CORRECTLY");
	if (!(bounds[1] = endian_read_int(file)))
		error_exit("BITMAP FILE NOT FORMATTED CORRECTLY");
	if (endian_read_short(file) != 1)
		error_exit("BITMAP FILE NOT FORMATTED CORRECTLY");
	if (endian_read_short(file) != 24)
		error_exit("BITMAP FILE NOT FORMATTED CORRECTLY");
	fseek(file, 24, SEEK_CUR);
	return (tex_new(bounds[0], bounds[1]));
}

void						*load_bitmap(char *path)
{
	FILE			*file;
	unsigned long	size;
	unsigned long	i;
	char			*tmp;
	t_texture		*image;

	if ((file = fopen(path, "rb")) == NULL)
		error_exit(ft_strjoin("COULDN'T FIND FILE AT : ", path));
	image = create_image(file);
	size = image->width * image->height * 3;
	tmp = (char *)malloc(size);
	if ((i = fread(tmp, size, 1, file)) != 1)
		error_exit(ft_strjoin("BITMAP FILE NOT FORMATTED CORRECTLY : ", path));
	i = 0;
	while (i < size)
	{
		tex_draw_pixel_index(image,
				i + (i / 3),
				create_pixel(0, tmp[i + 2], tmp[i + 1], tmp[i]));
		i += 3;
	}
	free(tmp);
	return (image);
}
