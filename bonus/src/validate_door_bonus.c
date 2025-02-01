/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_door_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 09:39:15 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/01/31 09:51:35 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	character2(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

t_cur	found_player(char **map)
{
	int		i;
	int		j;
	t_cur	cur;

	i = -1;
	cur.x = 0;
	cur.y = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (character(map[i][j]))
			{
				cur.y = i;
				cur.x = j;
				return (cur);
			}
		}
	}
	return (cur);
}

int	bigger_line2(char **map)
{
	int		i;
	size_t	res;

	i = -1;
	res = 0;
	while (map[++i])
	{
		if (ft_strlen(map[i]) > res)
			res = ft_strlen(map[i]);
	}
	return (res);
}

int	has_door(char **map)
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
	return (flag);
}

void	verify_door_path(char **map, char **max)
{
	t_size	size;
	t_cur	cur;

	size.y = matrix_len(map);
	size.x = bigger_line2(map);
	cur = found_player(map);
	flood_fill(map, size, cur);
	if (has_door(map) != 0)
	{
		free_max(map);
		free_max(max);
		error("Error\nthere is no way to access the door\n");
	}
}
