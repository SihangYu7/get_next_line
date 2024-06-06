/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: siyu <siyu@student.hive.fi>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:13:46 by siyu              #+#    #+#             */
/*   Updated: 2024/06/06 11:20:37 by siyu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	strlen_to(const char *str, char c)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] && str[len] != c)
		len++;
	return (len);
}

char	*gnl_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

char	*gnl_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	l1;
	size_t	l2;
	size_t	l_total;

	if (!s1)
	{
		s1 = malloc(sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	l_total = strlen_to(s1, '\0') + strlen_to(s2, '\0');
	str = (char *)malloc(sizeof(char) * (l_total + 1));
	if (!str)
		return (gnl_free(&s1));
	l1 = -1;
	while (s1[++l1])
		str[l1] = s1[l1];
	l2 = -1;
	while (s2[++l2])
		str[l1 + l2] = s2[l2];
	str[l1 + l2] = '\0';
	free(s1);
	return (str);
}

char	*gnl_substr(const char *s, size_t start, size_t len)
{
	char	*str;
	size_t	max_len;

	if (!s)
		return (NULL);
	if (start > strlen_to(s, '\0'))
	{
		str = malloc(sizeof(char) * (1));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	if (strlen_to(s, '\0') - start < len)
		len = strlen_to(s, '\0') - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	max_len = 0;
	while (start < strlen_to(s, '\0') && max_len < len && s[start])
		str[max_len++] = s[start++];
	str[max_len] = '\0';
	return (str);
}
