/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 11:47:40 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/02/02 22:20:58 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*fill_the_stash(char *stash, int fd)
{
	char	*buff;
	char	*temp;
	ssize_t	bytes_read;

	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	// bytes_read = read(fd, buff, BUFFER_SIZE);
	while (!ft_strchr(stash, '\n') && (bytes_read = read(fd, buff,
				BUFFER_SIZE)) > 0)
	{
		buff[bytes_read] = '\0';
		temp = ft_strjoin(stash, buff);
		if (!temp)
			return (free(buff), free(stash), NULL);
		free(stash);
		stash = temp;
		// bytes_read = read(fd, buff, BUFFER_SIZE);
	}
	if (bytes_read < 0)
		return (free(buff), free(stash), NULL);
	else if (bytes_read == 0)
	{
		if (stash[0] == '\0')
			return (free(buff), NULL);
		else
			return (free(buff), stash);
	}
	free(buff);
	return (stash);
}

// gets stash with or without '\n' inside
// part before '\n' separates and send to main
// another part stores
// if stash is here it means there is '\n' or read == 0;
char	*detach_the_line(char *stash)
{
	char	*found;

	if (!stash || stash[0] == '\0')
		return (NULL);
	found = ft_strchr(stash, '\n');
	if (!found)
		return (ft_substr(stash, 0, ft_strlen(stash)));
	return (ft_substr(stash, 0, (found - stash) + 1));
}

char	*trim_stash_after_line(char *stash)
{
	char	*new_stash;
	int		i;
	int		j;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
		return (free(stash), NULL);
	i++;
	new_stash = malloc(ft_strlen(stash + i) + 1);
	if (!new_stash)
		return (free(stash), NULL);
	j = 0;
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

// if read == 0 and stash[0]== '\0' FREE(STASH) when !(NEW_LINE)
char	*get_next_line(int fd)
{
	static char	*stash;
	char		*found;
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
	found = ft_strchr(stash, '\n');
	if (!found)
	{
		stash = fill_the_stash(stash, fd);
		if (!stash)
			return (stash = NULL, NULL);
	}
	line = detach_the_line(stash);
	if (!line)
		return (free(stash), stash = NULL, NULL);
	stash = trim_stash_after_line(stash);
	return (line);
}
