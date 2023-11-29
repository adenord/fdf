/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 16:58:25 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 08:43:30 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_3d_pos	center(int size, t_3d_pos *og)
{
	int			i;
	t_3d_pos	center;

	i = 0;
	center.x = 0;
	center.y = 0;
	center.z = 0;
	while (i < size)
	{
		center.x += og[i].x;
		center.y += og[i].y;
		center.z += og[i].z;
		i++;
	}
	center.x /= size;
	center.y /= size;
	center.z /= size;
	return (center);
}
