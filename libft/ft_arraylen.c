/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_arraylen.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: igvan-de <igvan-de@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/05/16 13:33:48 by igvan-de       #+#    #+#                */
/*   Updated: 2019/05/16 17:40:04 by igvan-de      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_arraylen(char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
