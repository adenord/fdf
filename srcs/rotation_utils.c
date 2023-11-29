/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:54:28 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 08:57:32 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	reset(t_hook_pos *data)
{
	data->angle_x = 0;
	data->angle_y = 0;
	data->angle_z = 0;
	data->zoom = 1;
	rotation_handler(data);
}

void	translation_iterator(t_hook_pos *data, int flag)
{
	int	i;

	i = 0;
	while (i < data->size)
	{
		if (flag == 1)
			data->og[i].offset_y -= 10;
		if (flag == 2)
			data->og[i].offset_x += 10;
		if (flag == 3)
			data->og[i].offset_y += 10;
		if (flag == 4)
			data->og[i].offset_x -= 10;
		i++;
	}
	rotation_handler(data);
}

void	pp_is_p(t_hook_pos *data)
{
	int	i;

	i = 0;
	clear(data->image);
	while (i < data->size)
	{
		data->og[i].n_x = data->og[i].x + 1000;
		data->og[i].n_y = data->og[i].y + 500;
		i++;
	}
	liner(data->og, data->size, data->image, data->x);
}

void	inc_angle(t_hook_pos *data, int flag)
{
	if (flag == 1)
		data->angle_x += 6;
	if (flag == 2)
		data->angle_x -= 6;
	if (flag == 3)
		data->angle_y += 6;
	if (flag == 4)
		data->angle_y -= 6;
	if (flag == 5)
		data->angle_z += 6;
	if (flag == 6)
		data->angle_z -= 6;
	if (flag == 7)
		data->zoom += 0.2;
	if (flag == 8 && data->zoom > 0.1)
		data->zoom -= 0.2;
	rotation_handler(data);
}
