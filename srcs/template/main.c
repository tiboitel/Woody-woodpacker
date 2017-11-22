/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:02:13 by tiboitel          #+#    #+#             */
/*   Updated: 2017/11/22 18:55:34 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

static int 		ft_getrandom(void *buf, size_t buflen, unsigned flags)
{
	int		fd = open("/dev/urandom", O_RDONLY);

	if (fd == -1)
		return (-1);
	(void) flags;
	read(fd, buf, buflen);
	close(fd);
	return (0);
}

char			*binary_image_create(const char *binary, size_t binary_size)
{
	char		*binary_path;
	int			binary_fd;
	size_t		i;

	i = 4;
	binary_fd = -1;
	binary_path = NULL;
	if (!(binary_path = (char *)ft_memalloc(sizeof(char) * 47)))
		return (NULL);
	ft_memcpy(binary_path, "/tmp/", 5);
	while (binary_fd == -1)
	{
		ft_getrandom(binary_path + 5, 42, 0);
		while (i++ < 47)
			binary_path[i] = (unsigned char)binary_path[i] % 26 + 'a';
		binary_fd = open(binary_path, O_CREAT | O_EXCL | O_WRONLY, 0700);
		if (binary_fd == -1 && errno != EACCES)
			exit(EXIT_FAILURE);
	}
	write(binary_fd, binary, binary_size);
	close(binary_fd);
	return (binary_path);
}

int				main(int argc, char **argv, char const **env)
{
	size_t	ciphered_content_size;
	char	*binary = NULL;
	char	*binary_path = NULL;
	
	(void)argc;
	dprintf(1, "... WOODY ...\n");
	ciphered_content_size = 0;
	if (!(binary = unpack_binary(argv[0], &ciphered_content_size)))
	{
		dprintf(2, "Woody: Unable to unpack binary.\n");
		return (-1);
	}
	binary_path = binary_image_create(binary, ciphered_content_size);
	printf("Binary path: %s\n", binary_path);
	free(binary);
	free(binary_path);
	(void)env;
}
