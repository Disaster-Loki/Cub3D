/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 09:49:02 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/01/16 11:35:59 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	path_no(char *path, char **max)
{
	char	**max_temp;
	int		fd;

	max_temp = ft_split(path, ' ');
	fd = open(max_temp[1], O_RDONLY);
	if (fd == -1)
	{
		free(path);
		free_max(max_temp);
		free_max(max);
		close(fd);
		error("Error\nInvalid path to North\n");
	}
	close(fd);
	free_max(max_temp);
}

void	path_so(char *path, char **max)
{
	char	**max_temp;
	int		fd;

	max_temp = ft_split(path, ' ');
	fd = open(max_temp[1], O_RDONLY);
	if (fd == -1)
	{
		free(path);
		free_max(max_temp);
		free_max(max);
		close(fd);
		error("Error\nInvalid path to South\n");
	}
	close(fd);
	free_max(max_temp);
}

void	path_we(char *path, char **max)
{
	char	**max_temp;
	int		fd;

	max_temp = ft_split(path, ' ');
	fd = open(max_temp[1], O_RDONLY);
	if (fd == -1)
	{
		free(path);
		free_max(max_temp);
		free_max(max);
		close(fd);
		error("Error\nInvalid path to West\n");
	}
	close(fd);
	free_max(max_temp);
}

void	path_ea(char *path, char **max)
{
	char	**max_temp;
	int		fd;

	max_temp = ft_split(path, ' ');
	fd = open(max_temp[1], O_RDONLY);
	if (fd == -1)
	{
		free(path);
		free_max(max_temp);
		free_max(max);
		close(fd);
		error("Error\nInvalid path to East\n");
	}
	close(fd);
	free_max(max_temp);
}

void	textures_path(char **max)
{
	char	*temp;
	int		i;

	i = 0;
	while (i < 6)
	{
		temp = ft_strtrim(max[i], " ");
		if (!ft_strncmp(temp, "NO ", 3))
			path_no(temp, max);
		else if (!ft_strncmp(temp, "SO ", 3))
			path_so(temp, max);
		else if (!ft_strncmp(temp, "WE ", 3))
			path_we(temp, max);
		else if (!ft_strncmp(temp, "EA ", 3))
			path_ea(temp, max);
		free(temp);
		i++;
	}
}
