/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   breisen_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:14:41 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 08:26:01 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

unsigned int	color(int total, int i, unsigned int old, unsigned int new)
{
	t_color	c;
	float	fraction;

	if (i == 0)
		return (old);
	if (i == total - 1)
		return (new);
	fraction = (float)i / (float)(total - 1);
	c.o_red = (old >> 24) & 0xFF;
	c.o_green = (old >> 16) & 0xFF;
	c.o_blue = (old >> 8) & 0xFF;
	c.o_alpha = old & 0xFF;
	c.red = c.o_red + (((new >> 24) & 0xFF) - c.o_red) * fraction;
	c.green = c.o_green + (((new >> 16) & 0xFF) - c.o_green) * fraction;
	c.blue = c.o_blue + (((new >> 8) & 0xFF) - c.o_blue) * fraction;
	c.alpha = c.o_alpha + ((new & 0xFF) - c.o_alpha) * fraction;
	c.color = ((c.red << 24) | (c.green << 16) | (c.blue << 8) | c.alpha);
	return (c.color);
}
