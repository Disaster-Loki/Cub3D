/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neighbor_door.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 12:59:44 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/02/03 15:41:01 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	error_position_door(char **map, char **max)
{
	free_max(map);
	free_max(max);
	error("Error\nThere is no space to pass after the door\n");
}

void	help_neighbor_door(char **map, char **max, int i, int j)
{
	if (map[i - 1][j] == '1')
	{
		if (map[i + 1][j] != '1')
			error_position_door(map, max);
		if (map[i][j + 1] != '0' && !character(map[i][j + 1]))
			error_position_door(map, max);
		if (map[i][j - 1] != '0' && !character(map[i][j - 1]))
			error_position_door(map, max);
	}
	if (map[i - 1][j] == '0' || character(map[i - 1][j]))
	{
		if (map[i + 1][j] != '0' && !character(map[i + 1][j]))
			error_position_door(map, max);
		if (map[i][j + 1] != '1')
			error_position_door(map, max);
		if (map[i][j - 1] != '1')
			error_position_door(map, max);
	}
}

void	neighbor_door(char **map, char **max)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'X')
			{
				help_neighbor_door(map, max, i, j);
			}
			j++;
		}
		i++;
	}
	free_max(map);
}
