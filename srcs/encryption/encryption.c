/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encryption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:57:40 by tiboitel          #+#    #+#             */
/*   Updated: 2017/08/23 16:21:52 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

void		tea_encrypt(uint32_t *value, uint32_t *key)
{
	uint32_t	v0;
	uint32_t	v1;
	uint32_t	sum;
	uint32_t	i;
	uint32_t	k0;
	uint32_t	k1;
	uint32_t	k2;
	uint32_t	k3;

	sum = 0;
	v0 = value[0];
	v1 = value[1];
	k0 = key[0];
	k1 = key[1];
	k2 = key[2];
	k3 = key[3];
	i = 0;
	while (i++ < 32)
	{
		sum += DELTA;
		v0 += ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
		v1 += ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
	}
	value[0] = v0;
	value[1] = v1;
}

void		tea_decrypt(uint32_t *value, uint32_t *key)
{
	uint32_t	v0;
	uint32_t	v1;
	uint32_t	i;
	uint32_t	k0;
	uint32_t	k1;
	uint32_t	k2;
	uint32_t	k3;
	uint32_t	sum;

	v0 = value[0];
	v1 = value[1];
	k0 = key[0];
	k1 = key[1];
	k2 = key[2];
	k3 = key[3];
	sum = SUM;
	i = 0;
	while (i++ < 32)
	{
		v1 -= ((v0 << 4) + k2) ^ (v0 + sum) ^ ((v0 >> 5) + k3);
		v0 -= ((v1 << 4) + k0) ^ (v1 + sum) ^ ((v1 >> 5) + k1);
		sum -= DELTA;
	}	
	value[0] = v0;
	value[1] = v1;
}

void		*encrypt_binary(void *binary, uint32_t *size, uint32_t *key)
{
	uint32_t			i;
	void			*bytes;
	uint8_t			buffer[8];
	
	bytes = NULL;
	ft_bzero(buffer, 8);
	if (!(bytes = ((char *)ft_memalloc(sizeof(char) * *size))))
		return (NULL);
	i = 0;
	while (i < *size)
	{
		ft_memcpy(buffer, binary + i, 8);	
		tea_encrypt((uint32_t *)(buffer), key);
		ft_memcpy(bytes + i, buffer, 8);
		i += 8;
	}
	return (bytes);
}

void		*decrypt_binary(void *data, uint32_t size, uint32_t *key)
{
	uint32_t		i;
	void			*bytes;
	uint8_t			buffer[8];

	bytes = NULL;
	ft_bzero(buffer, 8);
	if (!(bytes = ((char *)ft_memalloc(sizeof(char) * size))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_memcpy(buffer, data + i, 8);
		tea_decrypt((uint32_t *)(buffer), key);
		ft_memcpy(bytes + i, buffer, 8);
		i += 8;
	}
	// Strip null char if it was added
	return (bytes);
}
