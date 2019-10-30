/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 12:41:54 by igvan-de       #+#    #+#                */
/*   Updated: 2019/10/30 15:36:46 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	i = 0;
	while (n && s1[i] == s2[i] && s1[i] && s2[i])
	{
		i++;
		n--;
	}
	// if (n)
	// {
	// 	ft_putendl("test");
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	// }
	// return (0);
}
