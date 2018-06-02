/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syscall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tiboitel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 23:52:27 by tiboitel          #+#    #+#             */
/*   Updated: 2018/04/10 00:28:45 by tiboitel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "woody_woodpacker.h"

int		sys_unlink(const char *pathname)
{
	return (syscall(SYS_unlink, pathname));
}

int		sys_fstat(int fd, struct stat *buffer)
{
	return fstat(fd, buffer);
}

int		sys_execve(const char *path, char * const *argv, char * const *envp)
{
	return (syscall(SYS_execve, path, argv, envp));
}

