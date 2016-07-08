/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushback_array.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkabbas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:59:34 by bkabbas           #+#    #+#             */
/*   Updated: 2016/01/12 17:40:25 by bkabbas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	CAN CRASH IF YOU TRY TO FREE SOMETHING THAT HAVE NOT BEEN ALLOCATED
**	ITS YOUR RESPONSABILITY TO CHANGE THE PARAMETER SHOULD_FREE IN CONSEQUENCE
*/

#include "libft.h"

void		ft_pushback_array(t_array *array,
							void *value,
							size_t value_size)
{
	void *tmp;

	tmp = ft_memjoin(array->array,
					value,
					array->bytes_size,
					value_size);
	free(array->array);
	array->array = tmp;
	array->bytes_size += value_size;
	array->count += value_size / array->element_size;
}
