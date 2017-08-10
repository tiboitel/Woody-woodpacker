/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:19:40 by tiboitel          #+#    #+#             */
/*   Updated: 2017/08/10 23:45:14 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

int		main(int argc, char **argv)
{
	void			*binary;
	struct stat		binary_stat;

	if (argc != 2)
		return (-1);
	binary = NULL;
	if (!(binary = load_binary(argv[1], &binary_stat)))
	{
		perror("woody_woodpacker: ");
		return (-1);
	}
	printf("[WOODY_WOODPACKER] Binary successfully loaded !\n");
	uint32_t	binary_size;
	uint32_t 	key[4];
	char		*cipher;
	char		*binary2;
	
	binary2 = NULL;
	key[0] = 7493;
	key[1] = 43494;
	key[2] = 94349;
	key[3] = 49394;
	binary_size = (uint32_t)binary_stat.st_size;
	cipher = encrypt_binary(binary, &binary_size, key);
	if (!cipher)
		return (-1);
	printf("[WOODY_WOODPACKER] Binary successfully encrypted !\n");
	if (!(binary2 = decrypt_binary(cipher, binary_size, key)))
		return (-1);	
	printf("[WOODY_WOODPACKER] Binary successfully decrypted !\n");
	printf("[WOODY_WOODPACKER] Sanity check started.\n");
	unsigned int i = 0;
	while (i < binary_stat.st_size)
	{
		if (*((char *)(binary) + i) != binary2[i])
			printf("Fuck off! Test: %c != %c\n", *((char *)(binary) + i), binary2[i]);
		i++;
	}
	printf("[WOODY_WOODPACKER] Sanity check passed ! \\o/\n");
	free(cipher);
	cipher = NULL;
	munmap(binary, binary_stat.st_size + 1);
	return (0);
}
