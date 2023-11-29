/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_validator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 10:14:18 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 12:45:41 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int	check_dot_fdf(char *file)
{
	int	i;

	i = 0;
	while (file[i] && file[i] != '.')
		i++;
	if (file[i + 1] != 'f')
		return (0);
	if (file[i + 2] != 'd')
		return (0);
	if (file[i + 3] != 'f')
		return (0);
	if (file[i + 4] != 0)
		return (0);
	return (1);
}

int	arg_validator(int argc, char *file, t_hook_pos *hook)
{
	if (argc != 2)
	{
		ft_printf("Error : Invalid number of argument\nUsage : fdf takes one\
 argument\nExample : \"./fdf map.fdf\"\n");
		return (0);
	}
	if (!check_dot_fdf(file))
	{
		ft_printf("Error : map isn't a .fdf file\n\
Example : \"./fdf map.fdf\"\n");
		return (0);
	}
	if (open(file, O_RDONLY) < 0)
	{
		ft_printf("Error : The file \"%s\" doesn't exist or can't\
 be read.\n", file);
		if (hook)
			free(hook);
		return (0);
	}
	return (1);
}
