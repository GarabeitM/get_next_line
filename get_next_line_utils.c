/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgarabei <mgarabei@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 20:42:08 by mgarabei          #+#    #+#             */
/*   Updated: 2023/06/28 17:54:15 by mgarabei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

static size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return (i);
	}
	while (dst[j] && j < size)
		j++;
	while (src[i] && (j + i) < size - 1)
	{
		dst[j + i] = src[i];
		i++;
	}
	if (j < size)
		dst[i + j] = '\0';
	return (j + ft_strlen(src));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*new_str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 && s2)
		return ((char *)s2);
	if (s1 && !s2)
		return ((char *)s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new_str = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, s1, len1 + 1);
	ft_strlcat(new_str, s2, len1 + len2 + 1);
	return (new_str);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
		i++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s + i);
	return (0);
}

char	*ft_strdup(const char *s)
{
	size_t		i;
	size_t		len;
	char		*new_str;

	i = 0;
	len = ft_strlen(s);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	while (i < len)
	{
		new_str[i] = s[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

static size_t	ft_len(char const *s, unsigned int start, size_t len)
{
	size_t	l;

	if (start >= ft_strlen(s))
		return (0);
	l = 0;
	while (s[start + l] && l < len)
		l++;
	return (l);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	l;
	char	*sub_string;

	l = ft_len(s, start, len);
	sub_string = malloc((l + 1) * sizeof(char));
	if (!sub_string)
		return (NULL);
	i = 0;
	while (i < l)
	{
		sub_string[i] = s[start + i];
		i++;
	}
	sub_string[i] = '\0';
	return (sub_string);
}


