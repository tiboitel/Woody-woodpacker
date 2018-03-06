/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 14:33:43 by tiboitel          #+#    #+#             */
/*   Updated: 2018/03/06 17:41:47 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

int		elf64_check_file(void *elffile)
{
	struct Elf64_Header *file_hdr = (struct Elf64_Header *) elffile;
	
	if (file_hdr->e_ident[EI_MAG0] != ELFMAG0
			|| file_hdr->e_ident[EI_MAG1] != ELFMAG1
			|| file_hdr->e_ident[EI_MAG2] != ELFMAG2
			|| file_hdr->e_ident[EI_MAG3] != ELFMAG3)
		return (-1);	/* not an elf file */
	return (1);
}

int		mach_check_file(void *mach_file)
{
	struct mach_header	*mach_header = (struct mach_header *)mach_file;

	if (mach_header->magic != MH_MAGIC || mach_header != MH_MAGIC_64
			|| mach_header->magic != MH_CIGAM ||
				mach_headeir->magic != MH_CIGAM_64)
		return (-1);
	return (1);
}
