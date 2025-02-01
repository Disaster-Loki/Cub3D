/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   more_players_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:05:31 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/01/31 09:30:11 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	more_n(char **map, int i, int j, char **max)
{
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'N')
			{
				free_max(map);
				free_max(max);
				error("Error\nMany players\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	more_s(char **map, int i, int j, char **max)
{
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'S')
			{
				free_max(map);
				free_max(max);
				error("Error\nMany players\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	more_w(char **map, int i, int j, char **max)
{
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'W')
			{
				free_max(map);
				free_max(max);
				error("Error\nMany players\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	more_e(char **map, int i, int j, char **max)
{
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == 'E')
			{
				free_max(map);
				free_max(max);
				error("Error\nMany players\n");
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	more_players(char **map, char **max)
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
				more_n(map, i, j + 1, max);
			else if (map[i][j] == 'S')
				more_s(map, i, j + 1, max);
			else if (map[i][j] == 'W')
				more_w(map, i, j + 1, max);
			else if (map[i][j] == 'E')
				more_e(map, i, j + 1, max);
			j++;
		}
		i++;
	}
}
