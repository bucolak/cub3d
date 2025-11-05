/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bucolak <bucolak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 22:29:58 by buket             #+#    #+#             */
/*   Updated: 2025/11/05 11:09:37 by bucolak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_new(char *buffer);
char	*f_read(int fd, char *buffer);
size_t	gnl_strlen(char *x);
int		new_check(const char *s, int prmtr);
char	*f_swap(char *buffer);
char	*gnl_strjoin(char *line, char *buff);

#endif
