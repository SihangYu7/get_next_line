/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:14:01 by siyu              #+#    #+#             */
/*   Updated: 2024/06/06 11:14:05 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>

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
