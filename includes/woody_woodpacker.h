/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody_woodpacker.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:33:02 by tiboitel          #+#    #+#             */
/*   Updated: 2017/11/22 18:46:12 by tiboitel         ###   ########.fr       */
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
#include <errno.h>
# define DELTA 0x9e3779b9
# define SUM 0xC6EF3720
# define PACKER_SEPARATOR "GYARADOSLAUNCHHYPERBEAM"

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
 ** 5/. Utils
 **
 */
void		ft_bzero(void *s, size_t n);
void		*ft_memcpy(void *dst, const void *src, size_t n);
const char 	*ft_memscan(const char *ptr, size_t size, const char *target, size_t target_size);
void		*ft_memalloc(size_t size);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
#endif
