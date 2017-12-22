/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 19:28:34 by spalmaro          #+#    #+#             */
/*   Updated: 2016/11/23 13:02:51 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_tetri_real(char **str, int i, int j, char alpha)
{
	int pound;

	pound = 0;
	if (str[i][j] == '#' && pound <= 4)
	{
		str[i][j] = alpha;
		++pound;
		if (j != 3)
			pound = pound + ft_tetri_real(str, i, j + 1, alpha);
		if (((i + 1) % 4 != 0) || (i == 0))
			pound = pound + ft_tetri_real(str, i + 1, j, alpha);
		if (j != 0)
			pound = pound + ft_tetri_real(str, i, j - 1, alpha);
		if ((i % 4 != 0))
			pound = pound + ft_tetri_real(str, i - 1, j, alpha);
	}
	return (pound);
}

char	**copy_str_to_tetri(char **str)
{
	char	**tetri;
	int		i;

	i = 0;
	while (str[i])
		i++;
	if (!(tetri = (char**)malloc((i + 1) * sizeof(char*))))
	{
		ft_error();
		return (NULL);
	}
	i = 0;
	while (str[i])
	{
		tetri[i] = ft_strdup(str[i]);
		i++;
	}
	tetri[i] = NULL;
	return (tetri);
}
