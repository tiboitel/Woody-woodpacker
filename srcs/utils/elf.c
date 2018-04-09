/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:33:43 by tiboitel          #+#    #+#             */
/*   Updated: 2018/04/03 21:12:50 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

int		elf64_check_file(void *elffile)
{
	t_elf64_header *file_hdr = (t_elf64_header *)elffile;
	
	if (file_hdr->e_ident[EI_MAG0] != ELFMAG0
			|| file_hdr->e_ident[EI_MAG1] != ELFMAG1
			|| file_hdr->e_ident[EI_MAG2] != ELFMAG2
			|| file_hdr->e_ident[EI_MAG3] != ELFMAG3)
		return (-1);	/* not an elf file */
	return (1);
}

int		mach_check_file(void *mach_file)
{
	unsigned int magic_number = *(int *)(mach_file);
	
	if (magic_number != MH_MAGIC && magic_number !=MH_MAGIC_64
			&& magic_number != MH_CIGAM &&
				magic_number != MH_CIGAM_64)
		return (-1);
	return (1);
}
