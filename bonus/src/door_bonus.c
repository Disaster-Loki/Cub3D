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

t_door	*door_coordinates(char **map)
{
	int		x;
	int		y;
	int		i;
	t_door	*door;

	y = -1;
	i = 0;
	door = malloc(sizeof(t_door) * found_x(map));
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'X')
			{
				door[i].new_x = x;
				door[i].new_y = y;
				i++;
			}
		}
	}
	return (door);
}

void	hand_index(t_game *g, t_door *door)
{
	int	i;

	i = 0;
	printf("zzzzzz\n");
	if (g->doors.x == 0 && g->doors.y == 0)
		return ;
	while (i < found_x(g->sett->map))
	{
		door[i].open = 0;
		if ((g->doors.x == door[i].new_x)
			&& (g->doors.y == door[i].new_y))
			{
				g->index = i;
				return ;
			}
	}
}

void	open_door(t_game *g, int index)
{
	if (g->doors.x == 0 && g->doors.y == 0)
		return ;
	if (g->sett->map[g->doors.y][g->doors.x] == 'X' && g->door[index].open == 0)
	{
		printf("Open the door\n");
		g->door[index].open = 1;
		g->door[index].is_open = current_time();
		g->sett->map[g->door[index].new_y][g->door[index].new_x] = '0';
	}
}

void	close_door(t_game *g, int index)
{
	if (g->doors.x == 0 && g->doors.y == 0)
		return ;
	g->door[index].is_closed =  current_time() - g->door[index].is_open;
	if (g->sett->map[g->doors.y][g->doors.x] != '0')
		return ;
	if (g->door[index].open == 1 && g->door[index].is_closed >= 7000)
	{
		printf("Close the door\n");
		g->door[index].open = 0;
		g->sett->map[g->door[index].new_y][g->door[index].new_x] = 'X';
	}
}