/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irdzhupy <irdzhupy@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 13:28:28 by irdzhupy          #+#    #+#             */
/*   Updated: 2026/01/27 18:06:29 by irdzhupy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	fd;
	char	*new_line;
	if (argc != 2)
	{
		printf("Not less arguments");
		return (1);
	}
	fd = open(argv[1], O_RDONLY);
	new_line = get_next_line(fd);
	printf("%s", new_line);
	return (0);
	/*new_line = get_next_line(fd);
	printf("%s", new_line);
	while (new_line)
	{
		new_line = get_next_line(fd);
		if (new_line)
			printf("%s", new_line);
	}
	free(new_line);
	close(fd);*/
}
