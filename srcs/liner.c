/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liner.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:05:35 by adenord           #+#    #+#             */
/*   Updated: 2023/11/28 14:47:01 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	liner(t_3d_pos *coord, int size, mlx_image_t *image, int x)
{
	int	i;
	int	z;

	i = 0;
	z = 2;
	while (i < size)
	{
		while (i < x * z)
		{
			if (i < x - 1)
				master_breisen(coord[i], coord[i + 1], image);
			if (i < (x * z) - 1 && i > (x - 1))
				master_breisen(coord[i], coord[i + 1], image);
			if (i > (x - 1))
				master_breisen(coord[i], coord[i - x], image);
			i++;
		}
		z++;
	}
}
