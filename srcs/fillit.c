/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:17:46 by bjanik            #+#    #+#             */
/*   Updated: 2016/11/22 15:20:58 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	fillit(char **str, size_t nb_tetros)
{
	char	map[25][25];
	t_tetro	*tetros;
	size_t	dim_map;

	dim_map = min_map_dim(nb_tetros);
	if ((tetros = (t_tetro*)malloc((nb_tetros + 1) * sizeof(t_tetro))) == NULL)
	{
		ft_error();
		exit(-1);
	}
	read_tab_to_tetros(tetros, str, 0);
	set_map(dim_map, map);
	while (try_set(tetros, map, dim_map, 0) == 0)
	{
		dim_map++;
		set_map(dim_map, map);
	}
	ft_display_map(map, dim_map);
	free(tetros);
}
