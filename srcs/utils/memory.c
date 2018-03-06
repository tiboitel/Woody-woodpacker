/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:23:10 by tiboitel          #+#    #+#             */
/*   Updated: 2018/03/06 14:33:31 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

void	ft_bzero(void *s, size_t n)
{
	while (n != 0)
	{
		*((char *)s++) = '\0';
		n--;
	}
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && (src + i))
	{
		(*(unsigned char *)dst) = (*(unsigned char *)src);
		dst++;
		src++;
		i++;
	}
	return ((void *)dst - n);
}

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


void	*ft_memalloc(size_t size)
{
	char	*area;

	area = (void *)malloc(sizeof(char) * size);
	if (area == NULL)
		return (NULL);
	ft_bzero(area, size);
	return ((void *)area);
}

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	while (n != 0)
	{
		if (*((unsigned char *)s1) != *((unsigned char *)s2))
			return (*((unsigned char *)s1) - *((unsigned char *)s2));
		s1++;
		s2++;
		n--;
	}
	return (0);
}
