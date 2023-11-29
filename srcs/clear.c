/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 08:11:41 by adenord           #+#    #+#             */
/*   Updated: 2023/11/27 14:26:18 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	clear(mlx_image_t *image)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < IMAGE_HEIGHT)
	{
		mlx_put_pixel(image, x, y, 0x0);
		x++;
		if (x == IMAGE_WIDTH)
		{
			x = 0;
			y++;
		}
	}
}
