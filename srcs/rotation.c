/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 21:25:42 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 09:09:31 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	rotation_x(t_3d_pos *coord, int size, int angle)
{
	int		i;
	float	rad;
	double	y;

	if (angle != 0)
	{
		rad = angle * (M_PI / 180);
		i = 0;
		while (i < size)
		{
			y = coord[i].n_y;
			coord[i].n_y = (cos(rad) * y) - (sin(rad) * coord[i].n_z);
			coord[i].n_z = (sin(rad) * y) + (cos(rad) * coord[i].n_z);
			i++;
		}
	}
}

void	rotation_y(t_3d_pos *coord, int size, int angle)
{
	int		i;
	float	rad;
	double	x;

	if (angle != 0)
	{
		rad = angle * (M_PI / 180);
		i = 0;
		while (i < size)
		{
			x = coord[i].n_x;
			coord[i].n_x = (cosf(rad) * x) + (sinf(rad) * coord[i].n_z);
			coord[i].n_z = (-sinf(rad) * x) + (cosf(rad) * coord[i].n_z);
			i++;
		}
	}
}

void	rotation_z(t_3d_pos *coord, int size, int angle)
{
	int		i;
	float	rad;
	double	x;

	if (angle != 0)
	{
		i = 0;
		rad = angle * (M_PI / 180);
		while (i < size)
		{
			x = coord[i].n_x;
			coord[i].n_x = (cosf(rad) * x) - (sinf(rad) * coord[i].n_y);
			coord[i].n_y = (sinf(rad) * x) + (cosf(rad) * coord[i].n_y);
			i++;
		}
	}
}
