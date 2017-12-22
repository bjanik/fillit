/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spalmaro <spalmaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:47:52 by spalmaro          #+#    #+#             */
/*   Updated: 2016/11/07 17:56:55 by spalmaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_base_size(int nb, int base)
{
	int i;

	i = 1;
	if (nb < 0)
		nb = -nb;
	if (base == 0)
		return (0);
	while (nb >= base)
	{
		nb = nb / base;
		i++;
	}
	return (i);
}
