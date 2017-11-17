/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:23:10 by tiboitel          #+#    #+#             */
/*   Updated: 2017/11/17 13:05:00 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

const char *ft_memscan(const char *ptr, size_t size, const char *target, size_t 
		target_size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (ft_memcmp(ptr + i, target, target_size) == 0)
			return (ptr + i);
		i++;
	}
	return (NULL);
}
