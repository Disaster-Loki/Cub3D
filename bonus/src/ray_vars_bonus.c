/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_vars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 09:55:13 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/22 09:55:18 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	init_ray(t_game *g, t_raycast *ray, int x)
{
	ray->camera_x = 2 * x / (double)g->width - 1;
	ray->ray_dir_x = ray->dir.x + ray->plane.x * ray->camera_x;
	ray->ray_dir_y = ray->dir.y + ray->plane.y * ray->camera_x;
	ray->map_x = (int)ray->pos.x;
	ray->map_y = (int)ray->pos.y;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void	cal_perp_wall_dist(t_raycast *ray)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
}

void	set_draw_limits(t_game *g, t_raycast *ray)
{
	ray->line_height = (int)(g->height / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + g->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + g->height / 2;
	if (ray->draw_end >= g->height)
		ray->draw_end = g->height - 1;
}

void	update_frame_time(t_raycast *ray)
{
	ray->old_time = ray->time;
	ray->time = current_time();
	ray->frame_time = (double)(ray->time - ray->old_time) / 1000.0;
	ray->move_speed = 0.09;
	ray->rot_speed = ray->frame_time * 20.0;
}
