/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:41:03 by siyu              #+#    #+#             */
/*   Updated: 2024/06/04 14:08:21 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 6
# endif

char	*get_next_line(int fd);
size_t	strlen_to(const char *str, char c);
char	*gnl_free(char **str);
char	*ft_strchr(const char *s, int c);
char	*gnl_strjoin(char *s1, char const *s2);
char	*gnl_substr(const char *s, size_t start, size_t len);
#endif