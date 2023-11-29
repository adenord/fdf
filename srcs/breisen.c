/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breisen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 10:16:52 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 08:23:58 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	breisen_y_0(t_3d_pos o, t_3d_pos n, t_breisen elmt)
{
	int	p;
	int	tl;

	tl = (int)n.n_x - (int)o.n_x;
	p = 0;
	if (tl < 0)
		tl *= -1;
	while ((int)o.n_x != (int)n.n_x + elmt.inc_x)
	{
		put_pixel(elmt.image, o.n_x, o.n_y, color(tl, p, o.color, n.color));
		o.n_x += elmt.inc_x;
		p++;
	}
}

static void	breisen_x_0(t_3d_pos o, t_3d_pos n, t_breisen elmt)
{
	int	p;
	int	tl;

	tl = (int)n.n_y - (int)o.n_y;
	p = 0;
	if (tl < 0)
		tl *= -1;
	while ((int)o.n_y != (int)n.n_y + elmt.inc_y)
	{
		put_pixel(elmt.image, o.n_x, o.n_y, color(tl, p, o.color, n.color));
		o.n_y += elmt.inc_y;
	}
}

static void	breisen_dx_bigger(t_3d_pos o, t_3d_pos n, t_breisen elmt)
{
	int	slope;
	int	error;
	int	inc_e;
	int	tl;
	int	p;

	p = 0;
	tl = max(abs((int)n.n_x - (int)o.n_x), abs((int)n.n_y - (int)o.n_y)) + 1;
	slope = elmt.dy << 1;
	error = -(elmt.dx);
	inc_e = error << 1;
	while ((int)o.n_x != (int)n.n_x + elmt.inc_x)
	{
		put_pixel(elmt.image, o.n_x, o.n_y, color(tl, p, o.color, n.color));
		error += slope;
		if (error >= 0)
		{
			o.n_y += elmt.inc_y;
			error += inc_e;
		}
		o.n_x += elmt.inc_x;
		p++;
	}
}

static void	breisen_standard(t_3d_pos o, t_3d_pos n, t_breisen elmt)
{
	int	slope;
	int	error;
	int	inc_e;
	int	tl;
	int	p;

	p = 0;
	tl = max(abs((int)n.n_x - (int)o.n_x), abs((int)n.n_y - (int)o.n_y)) + 1;
	slope = elmt.dx << 1;
	error = -(elmt.dy);
	inc_e = error << 1;
	while ((int)o.n_y != (int)n.n_y + elmt.inc_y)
	{
		put_pixel(elmt.image, o.n_x, o.n_y, color(tl, p, o.color, n.color));
		error += slope;
		if (error >= 0)
		{
			o.n_x += elmt.inc_x;
			error += inc_e;
		}
		o.n_y += elmt.inc_y;
		p++;
	}
}

void	master_breisen(t_3d_pos current, t_3d_pos next, mlx_image_t *image)
{
	t_breisen	elmt;

	elmt.dy = next.n_y - current.n_y;
	elmt.dx = next.n_x - current.n_x;
	elmt.inc_y = 1;
	elmt.inc_x = 1;
	if (elmt.dy < 0)
	{
		elmt.inc_y = -1;
		elmt.dy *= -1;
	}
	if (elmt.dx < 0)
	{
		elmt.inc_x = -1;
		elmt.dx *= -1;
	}
	elmt.image = image;
	if (elmt.dy == 0)
		breisen_y_0(current, next, elmt);
	else if (elmt.dx == 0)
		breisen_x_0(current, next, elmt);
	else if (elmt.dx >= elmt.dy)
		breisen_dx_bigger(current, next, elmt);
	else
		breisen_standard(current, next, elmt);
}
