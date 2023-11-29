/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freeman.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 10:38:11 by adenord           #+#    #+#             */
/*   Updated: 2023/11/29 10:39:14 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

void	freeman(t_hook_pos *hook)
{
	free(hook->og);
	free(hook);
}