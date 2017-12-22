/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:11:31 by spalmaro          #+#    #+#             */
/*   Updated: 2016/11/23 12:59:37 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putendl("error");
	exit(1);
}

int		main(int argc, char **argv)
{
	int		fd;
	char	**tetri;
	size_t	nb_tetros;

	nb_tetros = 0;
	if (argc != 2)
	{
		ft_putendl("usage: fillit source_file");
		exit(1);
	}
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		ft_error();
	if (!(tetri = ft_entry_check(fd)))
		ft_error();
	while (tetri[nb_tetros])
		nb_tetros++;
	nb_tetros /= 4;
	fillit(tetri, nb_tetros);
	return (0);
}
