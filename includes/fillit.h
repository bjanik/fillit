/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjanik <bjanik@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 15:38:37 by bjanik            #+#    #+#             */
/*   Updated: 2017/12/22 13:41:50 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# define MAX 25

typedef struct		s_point
{
	int				abs;
	int				ord;
}					t_point;

typedef struct		s_tetro
{
	char			letter;
	t_point			coord[4];
}					t_tetro;

char				**ft_entry_check(int fd);
char				**copy_str_to_tetri(char **str);
int					ft_tetri_real(char **str, int i, int j, char alpha);
int					min_square_area(int nb_tetros);
int					check_valid_position(t_tetro *tetros, char map[MAX][MAX],
					int i, int j);
void				ft_error(void);
void				set_tetro(t_tetro *tetros, char map[MAX][MAX], int i,
					int j);
void				unset_tetro(t_tetro *tetros, char map[MAX][MAX],
					size_t dim_map);
void				read_tab_to_tetros(t_tetro *tetros, char **tab, int i);
void				ft_display_map(char map[MAX][MAX], size_t dim_map);
void				set_map(size_t dim, char map[MAX][MAX]);
void				inc_size_map(char map[MAX][MAX], size_t dim_map);
void				fillit(char **str, size_t nb_tetros);
size_t				min_map_dim(size_t nb_tetros);

size_t				try_set(t_tetro *tetros, char map[MAX][MAX], size_t dim_map,
					size_t i);
#endif
