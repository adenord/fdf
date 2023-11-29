/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_handler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 15:00:46 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 09:00:15 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	translator1(t_3d_pos *coord, t_3d_pos center, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		coord[i].n_x = coord[i].x - center.x;
		coord[i].n_y = coord[i].y - center.y;
		coord[i].n_z = coord[i].z - center.z;
		i++;
	}
}

void	translator2(t_3d_pos *coord, t_3d_pos center, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		coord[i].n_x += center.x;
		coord[i].n_y += center.y;
		coord[i].n_z += center.z;
		i++;
	}
}

void	rotation_handler(t_hook_pos *data)
{
	clear(data->image);
	translator1(data->og, data->center, data->size);
	rotation_x(data->og, data->size, data->angle_x);
	rotation_y(data->og, data->size, data->angle_y);
	rotation_z(data->og, data->size, data->angle_z);
	translator2(data->og, data->center, data->size);
	calculator_pos(data->og, data->size);
	if (data->zoom != 1)
		zoom(data);
	liner(data->og, data->size, data->image, data->x);
}

void	z_otar(t_hook_pos *data, int flag)
{
	int	i;

	i = 0;
	clear(data->image);
	while (i < data->size)
	{
		if (flag == 3)
			data->og[i].z *= 1.2;
		if (flag == 4 && data->og[i].z != 0)
			data->og[i].z *= 0.9;
		i++;
	}
	rotation_handler(data);
}

void	lost_in_translations(t_hook_pos *data, int flag)
{
	clear(data->image);
	translation_iterator(data, flag);
	liner(data->og, data->size, data->image, data->x);
}
