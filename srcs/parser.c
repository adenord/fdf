/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 09:59:42 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 13:03:26 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static void	sizer(char *file, int *x, int *y)
{
	int		fd;
	char	*line;
	char	**tmp;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	tmp = ft_split(line, ' ');
	while (tmp[*x])
	{
		free(tmp[*x]);
		(*x)++;
	}
	while (line)
	{
		(*y)++;
		free(line);
		line = get_next_line(fd);
	}
	free(tmp);
	close(fd);
}

t_3d_pos	color_parser(t_3d_pos og, char *str)
{
	char	*tmp;
	int		i;

	i = 1;
	tmp = ft_strchr(str, 'x');
	if (!tmp)
		return (default_color(og));
	og.color = ft_atoi_hexa(&tmp[i]);
	og.color = (og.color << 8) | 0xFF;
	return (og);
}

static void	filler(t_3d_pos *og_pos, char *file, int v, int i)
{
	int		fd;
	char	**tmp;
	char	*str;
	int		x;
	int		y;

	fd = open(file, O_RDONLY);
	y = -1;
	while (++y < v)
	{
		x = -1;
		str = get_next_line(fd);
		tmp = ft_split(str, ' ');
		free(str);
		while (tmp[++x])
		{
			og_pos[i] = help_filler(y, x, tmp[x]);
			og_pos[i] = color_parser(og_pos[i], tmp[x]);
			free(tmp[x]);
			i++;
		}
		free(tmp);
	}
}

t_3d_pos	*parser(char *file, int *size, int *x_og)
{
	t_3d_pos	*og_pos;
	int			x;
	int			y;
	int			i;

	x = 0;
	y = 0;
	i = 0;
	sizer(file, &x, &y);
	*x_og = x;
	og_pos = malloc((x * y) * sizeof(t_3d_pos));
	*size = (x * y);
	filler(og_pos, file, y, i);
	return (og_pos);
}
