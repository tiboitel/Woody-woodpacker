/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:19:40 by tiboitel          #+#    #+#             */
/*   Updated: 2017/08/29 18:17:56 by tiboitel         ###   ########.fr       */
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
	munmap(binary, binary_stat.st_size + 1);
	return (0);
}
