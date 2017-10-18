/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:19:40 by tiboitel          #+#    #+#             */
/*   Updated: 2017/10/18 19:33:06 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

void	generate_private_key(uint32_t *key)
{
	int		fd;

	if ((fd = open("/dev/urandon/", O_RDONLY)) == -1)
	{
		perror("woody_woodpacker: ");
		return (-1);
	}
	// Add error handling err.
	read(fd, key, 4);
	close(fd);
	return (0);
}

int		main(int argc, char **argv)
{
	extern unsigned char	woody[];
	extern unsigned int		woody_len;
	void					*binary;
	struct stat				binary_stat;
	int						binary_packed_fd;
	const char				packer_separator[] = PACKER_SEPARATOR;
	uint32_t				private_key;

	if (argc != 2)
		return (EXIT_FAILURE);
	binary = NULL;
	if (!(binary = load_binary(argv[1], &binary_stat)))
	{
		perror("woody_woodpacker: ");
		return (-1);
	}
	if ((binary_packed_fd = open("woody", O_CREAT | O_TRUNC | 0744)) == -1)
	{
		perror("woody_woodpacker: ");
		return (EXIT_FAILURE);
	}
	// Rename to woody xxd dump
	write(binary_packed_fd, woody, woody_len);
	write(binary_packed_fd, packer_separator, sizeof(packer_separator));
	if (generate_private_key(private_key) == -1)
	{
		perror("woody_woodpacker: canno't generate the private key.\n");
		return (EXIT_FAILURE);
	}
	// Encrypt binary en write him here.
	// free encrypted binary
	// close binary_packed_fd

	write(binary_packed_fd, private_key, sizeof(key));
	munmap(binary, binary_stat.st_size + 1);
	return (0);
}
