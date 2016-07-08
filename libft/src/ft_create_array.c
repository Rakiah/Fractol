/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 04:48:12 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/13 02:43:30 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**  CAN CRASH IF YOU TRY TO FREE SOMETHING THAT HAVE NOT BEEN ALLOCATED
**  ITS YOUR RESPONSABILITY TO CHANGE THE PARAMETER SHOULD_FREE IN CONSEQUENCE
*/

#include "libft.h"

t_array			*ft_create_array(size_t element_size)
{
	t_array	*allocated;

	if ((allocated = (t_array *)ft_memalloc(sizeof(t_array))) == NULL)
		return (NULL);
	allocated->element_size = element_size;
	return (allocated);
}
