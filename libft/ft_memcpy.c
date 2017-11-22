/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 18:29:55 by tiboitel          #+#    #+#             */
/*   Updated: 2017/11/22 16:50:21 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

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
