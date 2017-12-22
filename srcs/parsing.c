/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:19:29 by spalmaro          #+#    #+#             */
/*   Updated: 2016/11/23 13:10:58 by bjanik           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_tetri_check(char **str, int i, int j, char alpha)
{
	while (str[i])
	{
		while (str[i] && i % 4 != 0)
			i++;
		j = 0;
		while (str[i] && str[i][j] != '#')
		{
			j++;
			if ((str[i][j + 1] == '\0') && (str[i][j] == '#'))
				break ;
			else if ((str[i][j + 1] == '\0') && (str[i][j] != '#'))
			{
				i++;
				j = 0;
			}
		}
		if (str[i] && (ft_tetri_real(str, i, j, alpha)) != 4)
			return (0);
		if (str[i])
			i++;
		alpha++;
	}
	return (1);
}

static int		ft_pound_numbercheck(char **str, int i, int j)
{
	int pound;

	pound = 0;
	while (str[i])
	{
		if (str[i][j] == '#')
			pound++;
		if (str[i][j + 1] == '\0' && str[i][j])
		{
			if (j % 3 != 0)
				return (0);
			if (++i % 4 == 0)
			{
				if (pound != 4)
					return (0);
				pound = 0;
			}
			j = -1;
		}
		j++;
	}
	return (1);
}

static int		ft_char_check(char *buf, int i, int j)
{
	while (buf[i])
	{
		if ((buf[i] != '.') && (buf[i] != '\n') && (buf[i] != '#'))
			return (0);
		if (buf[i] == '\n')
		{
			j++;
			if ((buf[i + 1] == '\n' || buf[i + 1] == '\0') && j != 4)
				return (0);
		}
		if (buf[i] && j == 5)
		{
			if ((buf[i] != '\n' || buf[i - 1] != '\n') && (buf[i + 1] != '.'
			|| buf[i + 1] != '#'))
				return (0);
			else
				j = 0;
		}
		i++;
	}
	return (1);
}

static char		**ft_read_to_tab(int fd)
{
	char	**str;
	int		ret;
	char	buf[547];
	int		j;

	if (!(ret = read(fd, buf, 547)))
		return (NULL);
	buf[ret] = '\0';
	if (!(j = ft_char_check(buf, 0, 0)))
		return (NULL);
	if (!(str = ft_strsplit(buf, '\n')))
		return (NULL);
	if (close(fd) < 0)
		return (NULL);
	return (str);
}

char			**ft_entry_check(int fd)
{
	char	**str;
	char	**tetri;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(str = ft_read_to_tab(fd)))
		return (NULL);
	tetri = copy_str_to_tetri(str);
	if (!(ft_pound_numbercheck(str, i, j)))
		return (NULL);
	if (!(ft_tetri_check(str, 0, 0, 'A')))
		return (NULL);
	free(str);
	return (tetri);
}
