/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   woody_woodpacker.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/10 17:33:02 by tiboitel          #+#    #+#             */
/*   Updated: 2017/11/11 19:59:32 by tiboitel         ###   ########.fr       */
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
# include "libft.h"
# define DELTA 0x9e3779b9
# define SUM 0xC6EF3720
# define PACKER_SEPARATOR ".packer"

/*
** 2. Encryption section.
**
*/
void	tea_encrypt(uint32_t *value, uint32_t *key);
void	tea_decrypt(uint32_t *value, uint32_t *key);
void	*encrypt_binary(void *binary, uint32_t size, uint32_t *key);
void	*decrypt_binary(void *data, uint32_t size, uint32_t *key);
/*
** 3. Loader section.
**
*/
void	*load_binary(char *binary_path, struct stat *binary_stat);
#endif
