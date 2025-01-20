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

void move_player(int direction, t_game *g) {
    double new_x = g->pos.x;
    double new_y = g->pos.y;

    if (direction == UP) {
    	print_matrix(g->sett->map);
        double temp_x = g->pos.x + g->ray.dir.x * g->ray.move_speed;
        double temp_y = g->pos.y + g->ray.dir.y * g->ray.move_speed;
        if (g->sett->map[(int)temp_x][(int)g->pos.y] != '1') {
            new_x = temp_x;
    		printf("Moved X UP: %f\n", temp_x);
        }
        if (g->sett->map[(int)g->pos.x][(int)temp_y] != '1') {
            new_y = temp_y;
    		printf("Moved Y UP: %f\n", temp_y);
        }
    } 
    else if (direction == DOWN)
    {
        double temp_x = g->pos.x - g->ray.dir.x * g->ray.move_speed;
        double temp_y = g->pos.y - g->ray.dir.y * g->ray.move_speed;
        if (g->sett->map[(int)temp_x][(int)g->pos.y] != '1') {
            new_x = temp_x;
    		printf("Moved X DOWN: %f\n", temp_x);
        }
        if (g->sett->map[(int)g->pos.x][(int)temp_y] != '1') {
            new_y = temp_y;
    		printf("Moved Y DOWN: %f\n", temp_y);
        }
    }
    g->pos.x = new_x;
    g->pos.y = new_y;
	render_window(g);
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
