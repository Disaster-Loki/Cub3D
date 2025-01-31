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

int	is_in_fov(t_game *g, int door_x, int door_y)
{
	double	dx;
	double	dy;
	double	dot;
	double	mag_door;

	dx = door_x + 0.5 - g->pos.x;
	dy = door_y + 0.5 - g->pos.y;
	mag_door = sqrt(dx * dx + dy * dy);
	dot = (dx * g->ray.dir.x + dy * g->ray.dir.y) / mag_door;
	return (dot > 0.7);
}
