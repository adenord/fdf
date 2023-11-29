/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:47:19 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 08:51:20 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_3d_pos	help_filler(int y, int x, char *str)
{
	t_3d_pos	tmp;

	tmp.y = y * 10;
	tmp.n_y = y * 10;
	tmp.x = x * 10;
	tmp.n_x = x * 10;
	tmp.z = ft_atoi(str) * 2;
	tmp.n_z = ft_atoi(str) * 2;
	tmp.offset_y = 500;
	tmp.offset_x = 1000;
	return (tmp);
}

t_3d_pos	default_color(t_3d_pos og)
{
	if (og.z > 0)
		og.color = 0x0000FFFF;
	else
		og.color = 0xFF00FFFF;
	return (og);
}

int	hexa_base(char c)
{
	char	*str;
	char	*str2;
	int		i;

	i = 0;
	str = "0123456789ABCDEF";
	str2 = "0123456789abcdef";
	while (str[i])
	{
		if (str[i] == c || str2[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

unsigned int	ft_atoi_hexa(char *str)
{
	long	my_nbr;
	int		i;
	int		multi;

	my_nbr = 0;
	i = -1;
	multi = 1;
	while (str[++i])
		;
	i--;
	while (i >= 0)
	{
		my_nbr += (hexa_base(str[i]) * multi);
		multi *= 16;
		i--;
	}
	return (my_nbr);
}
