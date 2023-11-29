/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:36:48 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 08:44:18 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	mlx_stuff(mlx_t *mlx, mlx_image_t *image)
{
	if (!mlx)
	{
		ft_printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	if (!image)
	{
		mlx_close_window(mlx);
		ft_printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
	{
		mlx_close_window(mlx);
		ft_printf("%s", mlx_strerror(mlx_errno));
		return (1);
	}
	return (0);
}

void	hook_gen(int x, int s, mlx_image_t *image, t_hook_pos *hook)
{
	hook->x = x;
	hook->image = image;
	hook->size = s;
	hook->angle_x = 0;
	hook->angle_y = 0;
	hook->angle_z = 0;
	hook->center = center(s, hook->og);
	hook->zoom = 1;
}
