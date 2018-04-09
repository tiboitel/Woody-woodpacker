/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:36:27 by tiboitel          #+#    #+#             */
/*   Updated: 2018/04/09 23:52:52 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

void	*load_binary(char *binary_path, struct stat *binary_stat)
{
	int				fd;
	void			*binary;

	binary = NULL;
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
	if (!S_ISREG(binary_stat->st_mode) ||
			(binary = mmap(0, binary_stat->st_size, PROT_READ, MAP_PRIVATE, fd, 0)) == MAP_FAILED)
	{
		perror("woody_woodpacker: ");
		return (NULL);
	}
	close(fd);
	return (binary);
}
