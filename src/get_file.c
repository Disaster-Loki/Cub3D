/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/25 10:30:25 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/05 17:03:28 by ptchipoc         ###   ########.fr       */
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
		error("Error\nMemory allocation failed\n");
	size = read(fd, content, 1024);
	if (size == 0)
		error_str("Error\nFile empty\n", content);
	while (size > 0)
	{
		offset += size;
		size = read(fd, content + offset, 1024);
	}
	content[offset] = '\0';
	return (content);
}

void	last_position(char *str)
{
	size_t	i;

	i = ft_strlen(str);
	if (str[i] == '\0' && str[i - 1] == '\n')
	{
		error_str("Error\nThere is empty line\n", str);
	}
}

char	**get_file(char *str)
{
	int		fd;
	char	**max;
	char	*content;

	fd = open_file(str);
	content = read_file(fd);
	last_position(content);
	close(fd);
	max = ft_split(content, '\n');
	free(content);
	return (max);
}
