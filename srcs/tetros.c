/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetros.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <bjanik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:00:36 by bjanik            #+#    #+#             */
/*   Updated: 2016/11/23 12:50:46 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		check_valid_position(t_tetro *tetros, char map[MAX][MAX], int i, int j)
{
	int	k;
	int	ref_abs;
	int	ref_ord;
	int	abs;
	int	ord;

	k = 1;
	ref_abs = tetros->coord[0].abs;
	ref_ord = tetros->coord[0].ord;
	if (map[i][j] != '.')
		return (0);
	while (k < 4)
	{
		abs = tetros->coord[k].abs;
		ord = tetros->coord[k].ord;
		if ((abs - ref_abs + j) < 0)
			return (0);
		if (map[ord - ref_ord + i][abs - ref_abs + j] != '.')
			return (0);
		k++;
	}
	return (1);
}

void	set_tetro(t_tetro *tetros, char map[MAX][MAX], int i, int j)
{
	int	ref_abs;
	int	ref_ord;
	int	abs;
	int	ord;
	int	k;

	ref_abs = tetros->coord[0].abs;
	ref_ord = tetros->coord[0].ord;
	k = 1;
	map[i][j] = tetros->letter;
	while (k < 4)
	{
		abs = tetros->coord[k].abs;
		ord = tetros->coord[k].ord;
		map[ord - ref_ord + i][abs - ref_abs + j] = tetros->letter;
		k++;
	}
}

void	unset_tetro(t_tetro *tetros, char map[MAX][MAX], size_t dim_map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < dim_map)
	{
		j = 0;
		while (j < dim_map)
		{
			if (map[i][j] == tetros->letter)
				map[i][j] = '.';
			j++;
		}
		i++;
	}
}

void	read_tab_to_tetros(t_tetro *tetros, char **tab, int i)
{
	int		j;
	int		k;
	int		c;

	k = 0;
	c = 0;
	while (tab[i])
	{
		j = 0;
		k = (i % 4 == 0 && i != 0) ? k + 1 : k;
		while (tab[i][j])
		{
			if (tab[i][j] == '#')
			{
				tetros[k].letter = 'A' + k;
				tetros[k].coord[c % 4].abs = j;
				tetros[k].coord[c % 4].ord = i % 4;
				c++;
			}
			j++;
		}
		i++;
	}
	tetros[++k].letter = '\0';
}
