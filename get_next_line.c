/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 10:43:11 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/02/06 15:08:52 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*char	*buff_allocate_check(char *p, size_t size)
{
	p = malloc(size);
	if (!p)
		return (NULL);
	return (p);
}*/

char	*fill_the_stash(int fd, char *stash)
{
	char	*buff;
	char	*found;
	char	*temp;
	ssize_t	bytes_read;

	found = ft_strchr(stash, '\n');
	if (!found)
	{
		buff = malloc(BUFFER_SIZE + 1);
		if (!buff)
			return ( NULL);
		bytes_read = 1;
		while (bytes_read > 0 && !found)
		{
			bytes_read = read(fd, buff, BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(buff), free(stash), NULL);
			buff[bytes_read] = '\0';
			temp = ft_strjoin(stash, buff);
			if (!temp)
				return (free(buff), free(stash), NULL);
			free(stash);
			stash = temp;
			found = ft_strchr(stash, '\n');
		}
		//with or without
		if (bytes_read == 0)
			return (free(buff), stash);
		free(buff);
	}
	return (stash);
}

char	*find_the_line(char *stash)
{
	char	*found;

	if (!stash || stash[0] == '\0')
		return (NULL);
	found = ft_strchr(stash, '\n');
	if (!found)
		return (ft_substr(stash, 0, ft_strlen(stash)));
	return (ft_substr(stash, 0, (found - stash) + 1));
}

char	*check_free_stash(char *stash)
{
	char	*found;
	char	*new_stash;
	size_t	start;

	if (!stash || stash[0] == '\0')
	{
		free(stash);
		return (NULL);
	}
	found = ft_strchr(stash, '\n');
	if (!found)
	{
		free(stash);
		return (NULL);
	}
	start = (found - stash) + 1;
	new_stash = ft_substr(stash, start, ft_strlen(stash) - start);
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!stash)
	{
		stash = malloc(1);
		if (!stash)
			return (NULL);
		stash[0] = '\0';
	}
	stash = fill_the_stash(fd, stash);
/*	if (!stash)
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}*/
	line = find_the_line(stash);
	if (!line && stash && stash[0] != '\0')
	{
		free(stash);
		stash = NULL;
		return (NULL);
	}
	stash = check_free_stash(stash);
	return (line);
}
