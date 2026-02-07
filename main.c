/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:28:28 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/02/06 15:25:30 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		fd;
	char	*new_line;

	if (argc < 2)
	{
		return (printf("Not enough arguments"), 1);
	}
	fd = open(argv[1], O_RDONLY);
	while ((new_line = get_next_line(fd)))
	{
		if (!new_line)
			printf("File is empty");
		printf("%s", new_line);
		free(new_line);
	}
	close(fd);
	return (0);
}
