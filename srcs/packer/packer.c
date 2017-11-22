/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   packer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 12:28:29 by tiboitel          #+#    #+#             */
/*   Updated: 2017/11/22 17:16:36 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

char	*pack_binary(const char *path)
{
	(void)path;
	return (NULL);
}

char	*unpack_binary(char *path, size_t *ciphered_content_length)
{
	uint32_t		private_key;
	struct stat		binary_stat;
	char			*binary;
	const char		*index;
	void			*ciphered_content;

	ciphered_content = NULL;
	if (!(binary = load_binary(path, &binary_stat)))
		return (NULL);
	if (!(index = ft_memscan(binary, binary_stat.st_size,
					PACKER_SEPARATOR, sizeof(PACKER_SEPARATOR))))
	{
		dprintf(2, "Unable to find packer separator.\n");
		return (NULL);
	}
	index += sizeof(PACKER_SEPARATOR);
	if (!(index = ft_memscan(index, index - binary,
					PACKER_SEPARATOR, sizeof(PACKER_SEPARATOR)) + sizeof(PACKER_SEPARATOR)))
		return (NULL);
	ft_memcpy(&private_key, index, sizeof(private_key));
	dprintf(1, "Private key: %d\n", private_key);
	index += sizeof(private_key);
	*ciphered_content_length = binary_stat.st_size - (index - binary);
	dprintf(1, "Ciphered content length: %zu\nContent:%s\n", *ciphered_content_length, index);
	ciphered_content = decrypt_binary(index, (*(unsigned int *)ciphered_content_length), &private_key);
	return (ciphered_content);
}
