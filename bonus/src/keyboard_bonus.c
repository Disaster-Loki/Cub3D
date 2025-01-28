/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:35:24 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/08 15:35:27 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	rotate_view(t_game *g, t_raycast *ray, double speed)
{
	double	old_dir_x;
	double	old_plane_x;

	g->flag = 1;
	old_dir_x = ray->dir.x;
	ray->dir.y = old_dir_x * sin(speed) + ray->dir.y * cos(speed);
	ray->dir.x = ray->dir.x * cos(speed) - ray->dir.y * sin(speed);
	old_plane_x = ray->plane.x;
	ray->plane.y = old_plane_x * sin(speed) + ray->plane.y * cos(speed);
	ray->plane.x = ray->plane.x * cos(speed) - ray->plane.y * sin(speed);
}

int	valid_move(t_game *g, int new_x, int new_y)
{
	if (new_x < 0 || new_x >= g->width || new_y < 0 || new_y >= g->height)
		return (0);
	if (g->sett->map[(int)g->pos.y][new_x] == '1')
		return (0);
	if (g->sett->map[new_y][(int)g->pos.x] == '1')
		return (0);
	if (g->sett->map[new_y][new_x] == '1')
		return (0);
	if (!valid_move_door(g, new_x, new_y))
		return (0);
	return (1);
}

int	keypress(int key, t_game *g)
{
	if (key == UP)
		move_up(g); 
	if (key == DOWN)
		move_down(g);
	if (key == LEFT)
		move_left(g);
	if (key == RIGHT)
		move_right(g);
	if (key == S_RIGHT)
		rotate_view(g, &g->ray, -g->ray.rot_speed);
	if (key == S_LEFT)
		rotate_view(g, &g->ray, g->ray.rot_speed);
	if (key == SPACE)
		open_door(g, g->index);
	if (key == ESC)
		close_game(g);
	return (1);
}
