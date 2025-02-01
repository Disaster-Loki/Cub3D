/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_in_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:02:30 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/01/16 10:59:06 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	only_n(char **map, int i, int j, char **max)
{
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
			{
				free_max(map);
				free_max(max);
				error("Error\nOnly one character for the player\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	only_s(char **map, int i, int j, char **max)
{
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'E')
			{
				free_max(map);
				free_max(max);
				error("Error\nOnly one character for the player\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	only_w(char **map, int i, int j, char **max)
{
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E')
			{
				free_max(map);
				free_max(max);
				error("Error\nOnly one character for the player\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	only_e(char **map, int i, int j, char **max)
{
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'W' || map[i][j] == 'S')
			{
				free_max(map);
				free_max(max);
				error("Error\nOnly one character for the player\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	player_in_map(char **map, char **max)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
				only_n(map, i, j, max);
			else if (map[i][j] == 'S')
				only_s(map, i, j, max);
			else if (map[i][j] == 'W')
				only_w(map, i, j, max);
			else if (map[i][j] == 'E')
				only_e(map, i, j, max);
			j++;
		}
		i++;
	}
	free_max(map);
}
