/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:37:24 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 12:41:54 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	ft_hook2(t_hook_pos *hook, mlx_t *mlx)
{
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		inc_angle(hook, 1);
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
		inc_angle(hook, 2);
	else if (mlx_is_key_down(mlx, MLX_KEY_W))
		inc_angle(hook, 3);
	else if (mlx_is_key_down(mlx, MLX_KEY_S))
		inc_angle(hook, 4);
	else if (mlx_is_key_down(mlx, MLX_KEY_Q))
		inc_angle(hook, 5);
	else if (mlx_is_key_down(mlx, MLX_KEY_E))
		inc_angle(hook, 6);
	else if (mlx_is_key_down(mlx, MLX_KEY_1))
		inc_angle(hook, 7);
	else if (mlx_is_key_down(mlx, MLX_KEY_2))
		inc_angle(hook, 8);
	else if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
}

void	ft_hook(void *param)
{
	t_hook_pos	*hook;
	mlx_t		*mlx;

	hook = param;
	mlx = hook->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_I))
		lost_in_translations(param, 1);
	if (mlx_is_key_down(mlx, MLX_KEY_K))
		lost_in_translations(param, 3);
	if (mlx_is_key_down(mlx, MLX_KEY_J))
		lost_in_translations(param, 4);
	if (mlx_is_key_down(mlx, MLX_KEY_L))
		lost_in_translations(param, 2);
	else if (mlx_is_key_down(mlx, MLX_KEY_P))
		pp_is_p(param);
	else if (mlx_is_key_down(mlx, MLX_KEY_3))
		z_otar(param, 3);
	else if (mlx_is_key_down(mlx, MLX_KEY_4))
		z_otar(param, 4);
	else if (mlx_is_key_down(mlx, MLX_KEY_R))
		reset(param);
	ft_hook2(hook, mlx);
}
