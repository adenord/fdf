/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:46:16 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 12:44:30 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	main(int argc, char **argv)
{
	static mlx_image_t	*image;
	t_hook_pos			*hook;
	int					size;
	int					x;
	mlx_t				*mlx;

	mlx = NULL;
	hook = malloc(sizeof(t_hook_pos));
	if (!hook || !arg_validator(argc, argv[1], hook))
		return (1);
	hook->og = parser(argv[1], &size, &x);
	if (!hook->og)
		freeman(hook);
	mlx = mlx_init(WIDTH, HEIGHT, "fdf_adenord", true);
	image = mlx_new_image(mlx, IMAGE_WIDTH, IMAGE_HEIGHT);
	if (mlx_stuff(mlx, image))
		return (1);
	hook->mlx = mlx;
	hook_gen(x, size, image, hook);
	rotation_handler(hook);
	mlx_loop_hook(mlx, &ft_hook, hook);
	mlx_loop(mlx);
	mlx_terminate(mlx);
	freeman(hook);
	return (0);
}
