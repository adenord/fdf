/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculator_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:20:17 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 08:12:55 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	calculator_pos(t_3d_pos *coord, int size)
{
	int		i;
	double	rad;
	double	cos45;
	double	sin45;
	double	x;

	i = 0;
	rad = 45 * (M_PI / 180);
	cos45 = cos(rad);
	sin45 = sin(rad);
	while (i < size)
	{
		x = coord[i].n_x;
		coord[i].n_x = ((x - coord[i].n_y) * cos45) + coord[i].offset_x;
		coord[i].n_y = (((x + coord[i].n_y) * sin45) \
		- coord[i].n_z) + coord[i].offset_y;
		coord[i].n_z = coord[i].z;
		i++;
	}
}
