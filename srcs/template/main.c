/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:02:13 by tiboitel          #+#    #+#             */
/*   Updated: 2017/11/17 13:45:20 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

int				main(int argc, char **argv, char const **env)
{
	size_t	ciphered_content_size;
	char	*binary = NULL;
	char	*binary_path = NULL;
	
	(void)argc;
	dprintf(1, "... WOODY ...");
	ciphered_content_size = 0;
	if (!(binary = unpack_binary(argv[0], &ciphered_content_size)))
		return (-1);
	printf("Unpacked binary: %s\n", binary);
	(void)binary_path;
	(void)env;
	free(binary);
}
