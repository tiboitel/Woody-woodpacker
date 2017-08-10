/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encryption.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:57:40 by tiboitel          #+#    #+#             */
/*   Updated: 2017/08/10 23:55:03 by tiboitel         ###   ########.fr       */
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

char		*encrypt_binary(void *binary, uint32_t *size, uint32_t *key)
{
	uint32_t			i;
	char			*bytes;
	char			buffer[9];
	
	bytes = NULL;
	ft_bzero(buffer, 8);
	buffer[8] = '\0';
	if (!(bytes = ((char *)ft_memalloc(sizeof(char) * *size))))
		return (NULL);
	i = 0;
	while (i < *size)
	{
		ft_strncpy(buffer, binary + i, 8);	
		printf("%s", buffer);
		tea_encrypt((void *)(buffer), key);
		strncpy(bytes + i, buffer, 8);
		i += 8;
	}
	return (bytes);
}

char		*decrypt_binary(char *data, uint32_t size, uint32_t *key)
{
	uint32_t		i;
	char			*bytes;
	char			buffer[8];

	ft_bzero(buffer, 8);
	bytes = NULL;
	if (!(bytes = ((char *)ft_memalloc(sizeof(char) * size))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		ft_strncpy(buffer, data + i, 8);
		tea_decrypt((void *)(buffer), key);
		ft_strncpy(bytes + i, buffer, 8);
		i += 8;
	}
	// Strip null char if it was added
	return (bytes);
}
