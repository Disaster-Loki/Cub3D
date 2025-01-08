/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:30:25 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/27 08:59:29 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*read_file(int fd)
{
	int		size;
	int		offset;
	char	*content;

	size = 0;
	offset = 0;
	content = malloc(sizeof(char) * 70000);
	if (!content)
		error("Error - Memory allocation failed !!\n");
	size = read(fd, content, 1024);
	if (size == 0)
		error_str("Error - File empty !!\n", content);
	while (size > 0)
	{
		offset += size;
		size = read(fd, content + offset, 1024);
	}
	content[offset] = '\0';
	return (content);
}

char	**get_file(char *str)
{
	int		fd;
	char	**max;
	char	*content;

	fd = open_file(str);
	content = read_file(fd);
	close(fd);
	max = ft_split(content, '\n');
	free(content);
	return (max);
}
