/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:53:13 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/02/07 19:03:01 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	ch;

	if (!s)
		return (NULL);
	i = 0;
	ch = c;
	while (s[i])
	{
		if (s[i] == ch)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == ch)
		return ((char *)&s[i]);
	return (NULL);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*new;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	new = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		new[i + j] = s2[j];
		j++;
	}
	new[i + j] = '\0';
	return (new);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	s_len;
	size_t	copy;
	size_t	j;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		copy = 0;
	else if (len > s_len - start)
		copy = s_len - start;
	else
		copy = len;
	new = malloc(copy + 1);
	if (!new)
		return (NULL);
	j = 0;
	while (j < copy)
	{
		new[j] = s[start + j];
		j++;
	}
	new[j] = '\0';
	return (new);
}
