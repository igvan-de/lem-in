/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_2Darray.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/20 17:24:51 by igvan-de       #+#    #+#                */
/*   Updated: 2020/01/20 17:27:21 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void 		ft_free_stringarray(char **array)
{
	int i;

	i = 0;
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
