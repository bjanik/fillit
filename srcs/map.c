/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 09:56:28 by bjanik            #+#    #+#             */
/*   Updated: 2016/11/23 12:59:12 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
**The following functions determines the minimal square dimension in which
**the tetros can theorically fit, according to their number.
*/

size_t	min_map_dim(size_t nb_tetros)
{
	size_t	i;
	size_t	nb_squares;

	i = 0;
	nb_squares = nb_tetros * 4;
	while (i * i < nb_squares)
		i++;
	return (i);
}

/*
**Function fills the square  map with dots '.'. The map is delimited with \0
**on the right(end of string) and on the bottom.
*/

void	set_map(size_t dim_map, char map[MAX][MAX])
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < dim_map)
	{
		j = 0;
		while (j < dim_map)
		{
			map[i][j] = '.';
			j++;
		}
		map[i][j] = '\0';
		i++;
	}
	ft_bzero(map[i], dim_map);
}

void	ft_display_map(char map[MAX][MAX], size_t dim_map)
{
	size_t	i;

	i = 0;
	while (i < dim_map)
		ft_putendl(map[i++]);
}
