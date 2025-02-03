/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:50:19 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/02/03 15:35:48 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	empty_line(char *str, char **max)
{
	int		i;
	int		fd;
	char	*file;

	fd = open_file(str);
	file = read_file(fd);
	i = -1;
	while (file[++i])
	{
		if (file[i] == '\n' && (file[i + 1] == ' ' || file[i + 1] == '1'))
		{
			while (file[i++])
			{
				if (file[i] == '\n' && file[i + 1] == '\n')
				{
					free(file);
					free_max(max);
					error("Error\nEmpty line in the map\n");
				}
			}
			free(file);
			return ;
		}
	}
	free(file);
}

void	validate_map(char *str, char **max)
{
	char	**map;
	char	**new_map;

	empty_line(str, max);
	map = get_map(max);
	new_map = change_tabs_by_space(map);
	free_max(map);
	forbiden_char(new_map, max);
	player_in_map(new_map, max);
	treat_door(new_map, max);
	more_players(new_map, max);
	has_player(new_map, max);
	walls_at_edges(new_map, max);
	verify_door_path(new_map, max);
	free_max(new_map);
	neighbor_door(get_map(max), max);
}

void	treat_map(char **max, char *str)
{
	int	i;
	int	j;

	i = 6;
	if (!max[i])
	{
		free_max(max);
		error("Error\nThe file should have map\n");
	}
	j = 0;
	while (max[i][j])
	{
		if (max[i][j] != ' ' && max[i][j] != '\t' && max[i][j] != '1')
		{
			free_max(max);
			error("Error\nThe map should be sorrounded by walls\n");
		}
		j++;
	}
	validate_map(str, max);
}
