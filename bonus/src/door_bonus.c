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
		g->door.new_x = new_x;
		g->door.new_y = g->pos.y;
		return (0);
	}
	if (g->sett->map[new_y][(int)g->pos.x] == 'X')
	{
		g->door.new_x = g->pos.x;
		g->door.new_y = new_y;
		return (0);
	}
	if (g->sett->map[new_y][new_x] == 'X')
	{
		g->door.new_x = new_x;
		g->door.new_y = new_y;
		return (0);
	}
	return (1);
}

void	open_door(t_game *g)
{
	if (g->door.new_x == 0 && !g->door.new_y == 0)
		return ;
	if (g->sett->map[g->door.new_y][g->door.new_x] == 'X' && g->door.open == 0)
	{
		printf("Open the door\n");
		g->door.open = 1;
		g->door.is_open = current_time();
		g->sett->map[g->door.new_y][g->door.new_x] = '0';
		//g->sett->map[g->door.new_y][g->door.new_x + 1] = 'X';
	}
}

void	close_door(t_game *g)
{
	g->door.is_closed =  current_time() - g->door.is_open;
	if (g->sett->map[g->door.new_y][g->door.new_x] != '0')
		return ;
	if (g->door.open == 1 && g->door.is_closed >= 7000)
	{
		printf("Close the door\n");
		g->door.open = 0;
		g->sett->map[g->door.new_y][g->door.new_x] = 'X';
		//g->sett->map[g->door.new_y][g->door.new_x + 1] = '1';
	}
}