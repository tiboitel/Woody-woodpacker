/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:19:40 by tiboitel          #+#    #+#             */
/*   Updated: 2018/06/02 20:08:58 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

int		generate_private_key(uint32_t *key)
{
	int		fd;

	if ((fd = open("/dev/urandom", O_RDONLY)) == -1)
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
	extern unsigned char	template[];
	extern unsigned int		template_len;
	void					*binary;
	void					*packed_binary;
	struct stat				binary_stat;
	int						packed_binary_fd;
	const char				packer_separator[] = PACKER_SEPARATOR;
	uint32_t				private_key;
	
	if (argc != 2)
		return (EXIT_FAILURE);
	binary = NULL;
	packed_binary = NULL;
	if (!(binary = load_binary(argv[1], &binary_stat)))
	{
		perror("woody_woodpacker: ");
		return (-1);
	}
	#if __LINUX__
	if (elf64_check_file(binary) < 0)
	{
		perror("woody_woodpacker: Not an Elf64.");
		return (EXIT_FAILURE);
	}
	#elif __APPLE__
	if (mach_check_file(binary) < 0)
	{
		perror("woody_woodpacker: Not an Mach-O files.");
		return (EXIT_FAILURE);
	}
	#endif
	if ((packed_binary_fd = open("woody", O_CREAT | O_TRUNC | O_RDWR, 0744)) == -1)
	{
		perror("woody_woodpacker: Unable to open the Woody file: ");
		return (EXIT_FAILURE);
	}
	// Rename to woody xxd dump
	write(packed_binary_fd, template, template_len);
	write(packed_binary_fd, packer_separator, sizeof(packer_separator));
	if (generate_private_key(&private_key) == -1)
	{
		perror("woody_woodpacker: canno't generate the private key.\n");
		return (EXIT_FAILURE);
	}
	// Encrypt binary en write him here.
	// free encrypted binary
	// close packed_binary_fd
	write(packed_binary_fd, &private_key, sizeof(private_key));
	printf("Private key: %d\n", private_key);
	packed_binary = encrypt_binary(binary, (uint32_t)(binary_stat.st_size), &private_key);
	write(packed_binary_fd, packed_binary, binary_stat.st_size);
	free(packed_binary);
	close(packed_binary_fd);
	munmap(binary, binary_stat.st_size + 1);
	return (EXIT_SUCCESS);
}
