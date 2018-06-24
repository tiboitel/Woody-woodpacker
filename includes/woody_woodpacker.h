/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody_woodpacker.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:33:02 by tiboitel          #+#    #+#             */
/*   Updated: 2018/06/02 20:07:09 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WOODY_WOODPACKER_H
# define FT_WOODY_WOODPACKER_H

# include <unistd.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/mman.h>
# include <sys/syscall.h>
# include <unistd.h>
# include <errno.h>
# include <string.h>
# include <sys/resource.h>
#if __linux__
# include <elf.h>
#elif __APPLE__
# include <mach-o/loader.h>
#endif
# define DELTA 0x9e3779b9
# define SUM 0xC6EF3720
# define PACKER_SEPARATOR "__PACKERSEPARATOR__"

/*
 ** Elf
 **/
typedef struct		elf64_header
{
	unsigned char   e_ident[16];
	uint16_t        e_type;
	uint16_t        e_machine;
	uint32_t        e_version;
	uint64_t        e_entry;
	uint64_t        e_phoff;
	uint64_t        e_shoff;
	uint32_t        e_flags;
	uint16_t        e_ehsize;
	uint16_t        e_phentsize;
	uint16_t        e_phnum;
	uint16_t        e_shentsize;
	uint16_t        e_shnum;
	uint16_t        e_shstrndx;
}					t_elf64_header;

/*
 ** 2. Encryption section.
 **
 */
void	tea_encrypt(uint32_t *value, uint32_t *key);
void	tea_decrypt(uint32_t *value, uint32_t *key);
void	*encrypt_binary(void *binary, uint32_t size, uint32_t *key);
void	*decrypt_binary(const void *data, uint32_t size, uint32_t *key);
/*
 ** 3. Loader section.
 **
 */
void	*load_binary(char *binary_path, struct stat *binary_stat);
/*
 **
 ** 4. Packer section.
 **
 */
char	*unpack_binary(char *path, size_t *ciphered_content_length);
/*
 **
 ** 5. Utils
 **
 */
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
const char 	*ft_memscan(const char *ptr, size_t size, const char *target, size_t target_size);
void		*ft_memalloc(size_t size);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			elf64_check_file(void *elffile);
int			mach_check_file(void *mach_file);

/*
 **
 ** 6. Syscall
 **
 */
int			sys_unlink(const char *pathname);
int			sys_fstat(int fd, struct stat *buffer);
int			sys_execve(const char *path, char * const *argv, char * const *envp);
int			sys_getrandom(void *buffer, size_t buffer_length, unsigned int flags);
#endif
