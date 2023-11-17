/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adenord <alexandre.denord@gmail.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 15:11:56 by adenord           #+#    #+#             */
/*   Updated: 2023/07/26 11:36:29 by adenord          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* ******************** */
/*                      */
/*  zero a byte string  */
/*                      */
/* ******************** */

void	ft_bzero(void *s, size_t n)
{
	while (n > 0)
	{
		if (*(char *)s != 0)
			*(char *)s = 0;
		s += 1;
		n--;
	}
}
