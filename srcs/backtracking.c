/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtracking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 14:30:54 by bjanik            #+#    #+#             */
/*   Updated: 2016/11/21 17:09:30 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

size_t	try_set(t_tetro *tetros, char map[MAX][MAX], size_t dim_map, size_t i)
{
	size_t	j;

	while (i < dim_map)
	{
		j = 0;
		while (j < dim_map)
		{
			if (check_valid_position(tetros, map, i, j))
			{
				set_tetro(tetros, map, i, j);
				if ((tetros + 1)->letter != '\0')
				{
					if (try_set(tetros + 1, map, dim_map, 0))
						return (1);
				}
				else
					return (1);
				unset_tetro(tetros, map, dim_map);
			}
			j++;
		}
		i++;
	}
	return (0);
}
