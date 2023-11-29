/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 15:11:12 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 12:44:51 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <stdio.h>
# include <unistd.h>
# include <MLX42.h>
# include <math.h>

# define WIDTH 1920
# define HEIGHT 1080
# define IMAGE_WIDTH 1920
# define IMAGE_HEIGHT 1080

typedef struct s_3d_pos
{
	double				y;
	double				x;
	double				z;
	double				n_y;
	double				n_x;
	double				n_z;
	int					offset_x;
	int					offset_y;
	unsigned int		color;
}	t_3d_pos;

typedef struct s_breisen
{
	int			dy;
	int			dx;
	int			inc_y;
	int			inc_x;
	mlx_image_t	*image;
}	t_breisen;

typedef struct s_color
{
	long	o_red;
	long	o_green;
	long	o_blue;
	long	o_alpha;
	long	red;
	long	green;
	long	blue;
	long	alpha;
	long	color;
}	t_color;

typedef struct s_hook_pos
{
	mlx_t		*mlx;
	mlx_image_t	*image;
	int			size;
	t_3d_pos	*og;
	int			x;
	int			angle_x;
	int			angle_y;
	int			angle_z;
	float		zoom;
	t_3d_pos	center;
}	t_hook_pos;

int				arg_validator(int argc, char *file, t_hook_pos *hook);
t_3d_pos		*parser(char *file, int *size, int *x);
void			calculator_pos(t_3d_pos *coord, int size);
void			master_breisen(t_3d_pos o, t_3d_pos n, mlx_image_t *image);
void			liner(t_3d_pos *coord, int size, mlx_image_t *image, int x);
void			rotation_x(t_3d_pos *coord, int size, int angle);
void			rotation_y(t_3d_pos *coord, int size, int angle);
void			rotation_z(t_3d_pos *coord, int size, int angle);
void			clear(mlx_image_t *image);
void			inc_angle(t_hook_pos *data, int flag);
void			rotation_handler(t_hook_pos *data);
t_3d_pos		center(int size, t_3d_pos *og);
void			zoom(t_hook_pos *data);
void			translator1(t_3d_pos *coord, t_3d_pos center, int size);
void			translator2(t_3d_pos *coord, t_3d_pos center, int size);
void			put_pixel(mlx_image_t *i, double x, double y, unsigned int rgb);
void			lost_in_translations(t_hook_pos *data, int flag);
void			pp_is_p(t_hook_pos *data);
void			z_otar(t_hook_pos *data, int flag);
void			reset(t_hook_pos *data);
int				mlx_stuff(mlx_t *mlx, mlx_image_t *image);
void			hook_gen(int x, int s, mlx_image_t *mlx, t_hook_pos *hook);
void			ft_hook(void *param);
int				max(int a, int b);
unsigned int	color(int total, int i, unsigned int old, unsigned int new);
t_3d_pos		help_filler(int y, int x, char *str);
t_3d_pos		default_color(t_3d_pos og);
int				hexa_base(char c);
unsigned int	ft_atoi_hexa(char *str);
void			reset(t_hook_pos *data);
void			translation_iterator(t_hook_pos *data, int flag);
void			pp_is_p(t_hook_pos *data);
void			inc_angle(t_hook_pos *data, int flag);
void			freeman(t_hook_pos *hook);

#endif
