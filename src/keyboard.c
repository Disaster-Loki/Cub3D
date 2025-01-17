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

int	round_to_integer(double value)
{
	int		integer;
	double	decimal;

	integer = (int)value;
	decimal = value - integer;
	if (value >= 0)
	{
		if ((int)(decimal * 10) >= 5)
			return integer + 1;
	}
	else
	{
		if ((int)(decimal * 10) <= -5)
			return (integer - 1);
	}
	return (integer);
}

void	move_player(int direction, t_game *g)
{
	int	new_x;
	int	new_y;


    printf("before: X = %i Y = %i\n", g->pos.x, g->pos.y);
    printf("before: move_speed = %f\n", g->ray.move_speed);
    printf("before: rayX = %f rayY = %f\n\n", g->ray.dir.x, g->ray.dir.y);
	if (direction == UP)
	{
		new_x = round_to_integer(g->pos.x + g->ray.dir.x * g->ray.move_speed);
		new_y = round_to_integer(g->pos.y + g->ray.dir.y * g->ray.move_speed);
		if (g->sett->map[(int)new_x][g->pos.y] == '0')
			g->pos.x = new_x;

		if (g->sett->map[g->pos.x][(int)new_y] == '0')
			g->pos.y = new_y;
	}
	if (direction == DOWN)
	{

		new_x = round_to_integer(g->pos.x - g->ray.dir.x * g->ray.move_speed);
		new_y = round_to_integer(g->pos.y - g->ray.dir.y * g->ray.move_speed);
		if (g->sett->map[(int)new_x][g->pos.y] == '0')
			g->pos.x = new_x;
		if (g->sett->map[g->pos.x][(int)new_y] == '0')
			g->pos.y = new_y;
	}
	render_window(g);
	printf("new_x = %d new_y = %d\n", new_x, new_y);
    printf("after: X = %i Y = %i\n", g->pos.x, g->pos.y);
    printf("after: move_speed = %f\n", g->ray.move_speed);
    printf("after: rayX = %f rayY = %f\n", g->ray.dir.x, g->ray.dir.y);
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
