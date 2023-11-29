/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:13:31 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 09:10:45 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	put_pixel(mlx_image_t *i, double x, double y, unsigned int rgb)
{
	if (x > 0 && y > 0 && x < IMAGE_WIDTH && y < IMAGE_HEIGHT)
		mlx_put_pixel(i, x, y, rgb);
}
