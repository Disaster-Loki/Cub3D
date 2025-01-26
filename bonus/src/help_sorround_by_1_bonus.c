/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_sorround_by_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:21:22 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/01/16 11:21:25 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	last_line(char **mat, char **max)
{
	int	i;
	int	j;

	i = 0;
	while (mat[i + 1])
		i++;
	j = 0;
	while (mat[i][j])
	{
		if (mat[i][j] != ' ' && mat[i][j] != '\t' && mat[i][j] != '1')
		{
			free_max(mat);
			free_max(max);
			error("Error\nThe map should be sorrounded by 1\n");
		}
		j++;
	}
}

void	middle_lines(char **map, char **max)
{
	int	i;
	int	j;

	i = 0;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == ' ' && map[i][j + 1] != '1'
				&& map[i][j + 1] != ' '
				&& map[i][j + 1] != '\t'
				&& map[i][j + 1] != '\0')
			{
				free_max(map);
				free_max(max);
				error("Error\nThe map should be sorrounded by 1\n");
			}
			j++;
		}
	}
}
