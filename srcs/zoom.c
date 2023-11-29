/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 12:19:35 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 08:09:20 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	zoom(t_hook_pos *data)
{
	int			i;
	int			delta_x;
	int			delta_y;

	i = 0;
	clear(data->image);
	delta_x = (data->og[i].n_x * data->zoom) - data->og[i].n_x;
	delta_y = (data->og[i].n_y * data->zoom) - data->og[i].n_y;
	while (i < data->size)
	{
		data->og[i].n_x = (data->zoom * data->og[i].n_x) - delta_x;
		data->og[i].n_y = (data->zoom * data->og[i].n_y) - delta_y;
		i++;
	}
}
