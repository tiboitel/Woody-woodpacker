/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:36:27 by tiboitel          #+#    #+#             */
/*   Updated: 2017/08/10 19:13:48 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

void	*load_binary(char *binary_path, struct stat *binary_stat)
{
	int				fd;
	void			*binary;
	int 			padding;

	binary = NULL;
	padding = 0;
	if 	((fd = open(binary_path, O_RDONLY)) < 0)
	{
		perror("woody_woodpacker: ");
		return (NULL);
	}
	if (fstat(fd, binary_stat) < 0)
	{
		perror("woody_woodpacker: ");
		return (NULL);
	}
	if (binary_stat->st_size % 2)
		binary_stat->st_size++;
	if ((binary = mmap(0, binary_stat->st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		perror("woody_woodpacker: ");
		return (NULL);
	}
	close(fd);
	return (binary);
}
