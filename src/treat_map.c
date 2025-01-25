/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 21:50:19 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/01/25 05:47:04 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
	empty_line(str, max);
	forbiden_char(get_map(max), max);
	player_in_map(get_map(max), max);
	more_players(get_map(max), max);
	has_player(get_map(max), max);
	walls_at_edges(get_map(max), max);
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
	(void)str;
	validate_map(str, max);
}
