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

#include "../inc/cub3d.h"

void	rotate_camera(t_game *g, t_raycast *ray, double speed)
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
	render_window(g);
}

int	valid_move(t_game *g, double new_y, double new_x)
{
	if (g->sett->map[(int)new_y][(int)new_x] == '1')
		return (0);
	return (1);
}

void	set_direction(t_game *g, int direc, double *y, double *x)
{
	if (direc == UP)
	{
		*x = g->pos.x + g->ray.dir.x * g->ray.move_speed;
		*y = g->pos.y + g->ray.dir.y * g->ray.move_speed;
	}
	if (direc == DOWN)
	{
		*x = g->pos.x - g->ray.dir.x * g->ray.move_speed;
		*y = g->pos.y - g->ray.dir.y * g->ray.move_speed;
	}
}

void	move_player(int direc, t_game *g)
{
	double	new_x;
	double	new_y;
	double	temp_x;
	double	temp_y;

	new_x = g->pos.x;
	new_y = g->pos.y;
	set_direction(g, direc, &temp_y, &temp_x);
	if (g->sett->map[(int)g->pos.y][(int)temp_x] != '1')
		new_x = temp_x;
	if (g->sett->map[(int)temp_y][(int)g->pos.x] != '1')
		new_y = temp_y;
	if (valid_move(g, new_y, new_x))
	{
		g->pos.x = new_x;
		g->pos.y = new_y;
		render_window(g);
	}
}

int	keypress(int key, t_game *g)
{
	if (key == UP || key == DOWN)
		move_player(key, g);
	if (key == S_RIGHT)
		rotate_camera(g, &g->ray, -g->ray.rot_speed);
	if (key == S_LEFT)
		rotate_camera(g, &g->ray, g->ray.rot_speed);
	if (key == ESC)
		close_game(g);
	return (1);
}
