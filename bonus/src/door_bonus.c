/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:44:13 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/24 12:44:18 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	valid_move_door(t_game *g, int new_x, int new_y)
{
	if (g->sett->map[(int)g->pos.y][new_x] == 'X')
	{
		g->doors.x = new_x;
		g->doors.y = g->pos.y;
		return (0);
	}
	if (g->sett->map[new_y][(int)g->pos.x] == 'X')
	{
		g->doors.x = g->pos.x;
		g->doors.y = new_y;
		return (0);
	}
	if (g->sett->map[new_y][new_x] == 'X')
	{
		g->doors.x = new_x;
		g->doors.y = new_y;
		return (0);
	}
	return (1);
}

int	found_x(char **map)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	len = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == 'X')
				++len;
		}
	}
	return (len);
}

t_door	*door_coordinates(t_game *g, char **map)
{
	int		x;
	int		y;
	int		i;
	t_door	*door;

	i = -1;
	y = -1;
	door = malloc(sizeof(t_door) * g->dr_count);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'X')
			{
				door[++i].new_x = x;
				door[i].new_y = y;
				door[i].open = 0;
				door[i].is_open = 0;
			}
		}
	}
	return (door);
}

void	open_door(t_game *g)
{
	int	i;

	i = -1;
	while (++i < g->dr_count)
	{
		if (g->doors.x == g->door[i].new_x
			&& g->doors.y == g->door[i].new_y
			&& g->door[i].open == 0)
		{
			g->door[i].open = 1;
			g->door[i].is_open = current_time();
			g->sett->map[g->door[i].new_y][g->door[i].new_x] = '0';
			return ;
		}
	}
}

void	close_door(t_game *g)
{
	int	i;

	i = -1;
	while (++i < g->dr_count)
	{
		if (g->door[i].open == 1)
		{
			g->door[i].is_closed = current_time() - g->door[i].is_open;
			if ((int)g->pos.x == g->door[i].new_x
				&& (int)g->pos.y == g->door[i].new_y)
				continue ;
			if (g->ray.map_x == g->door[i].new_x
				&& g->ray.map_y == g->door[i].new_y)
				continue ;
			if (g->door[i].is_closed >= 7000
				&& g->sett->map[g->door[i].new_y][g->door[i].new_x] == '0')
			{
				g->door[i].open = 0;
				g->sett->map[g->door[i].new_y][g->door[i].new_x] = 'X';
			}
		}
	}
}
