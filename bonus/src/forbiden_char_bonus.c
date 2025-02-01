/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forbiden_char_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:59:07 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/01/31 09:43:08 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	treat_door(char **map, char **max)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'X')
				flag++;
		}
	}
	if (flag < 1)
	{
		free_max(map);
		free_max(max);
		error("The map should have etleast one door\n");
	}
}

void	has_player(char **map, char **max)
{
	int	i;
	int	j;
	int	flag;

	i = -1;
	flag = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
				flag++;
		}
	}
	if (flag != 1)
	{
		free_max(map);
		free_max(max);
		error("Error\nThere is no player in the map\n");
	}
}

void	forbiden_char(char **map, char **max)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != ' ' && map[i][j] != '\t'
				&& map[i][j] != 'N' && map[i][j] != 'S'
				&& map[i][j] != 'W' && map[i][j] != 'E'
				&& map[i][j] != '1' && map[i][j] != '0'
				&& map[i][j] != '\n' && map[i][j] != 'X')
			{
				free_max(map);
				free_max(max);
				error("Error\nThere is forbiden character in the map\n");
			}
			j++;
		}
		i++;
	}
}
