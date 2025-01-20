/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:42:19 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/08 15:42:21 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_column(t_game *g, int x, int start, int end, int color)
{
	int		i;
	char	*pixel;

	i = start - 1;

	g->img.addr = mlx_get_data_addr(g->img.ptr, &g->img.bpp,
		&g->img.line_length, &g->img.endian);
    while (++i < end)
	{
        pixel = (char *)g->img.addr + (i * g->img.line_length + x * (g->img.bpp / 8));
		*(unsigned int *)pixel = color;
		pixel += g->img.line_length;
	}
}

void init_ray(t_game *g, t_raycast *ray, int x)
{
    ray->camera_x = 2 * x / (double)g->width - 1;
    ray->ray_dir_x = ray->dir.x + ray->plane.x * ray->camera_x;
    ray->ray_dir_y = ray->dir.y + ray->plane.y * ray->camera_x;
    ray->map_x = (int)ray->pos.x;
    ray->map_y = (int)ray->pos.y;
    ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
    ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
}

void cal_perp_wall_dist(t_raycast *ray)
{
    if (ray->side == 0)
        ray->perp_wall_dist = (ray->side_dist_x - ray->delta_dist_x);
    else
        ray->perp_wall_dist = (ray->side_dist_y - ray->delta_dist_y);
}

int get_wall_color(t_raycast *ray)
{
    if (ray->side == 0)
    {
        if (ray->ray_dir_x > 0)
            return (0xFF0000);
        else
            return (0x0000FF);
    }
    else
    {
        if (ray->ray_dir_y > 0)
            return (0x00FF00);
        else
            return (0xFFFF00);
    }
}
void set_steps_and_sidedist(t_raycast *ray)
{
    if (ray->ray_dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (ray->pos.x - ray->map_x) * ray->delta_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - ray->pos.x) * ray->delta_dist_x;
    }
    if (ray->ray_dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (ray->pos.y - ray->map_y) * ray->delta_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - ray->pos.y) * ray->delta_dist_y;
    }
}

void check_hit(t_game *g, t_raycast *ray)
{
    if (ray->side_dist_x < ray->side_dist_y)
    {
        ray->side_dist_x += ray->delta_dist_x;
        ray->map_x += ray->step_x;
        ray->side = 0;
    }
    else
    {
        ray->side_dist_y += ray->delta_dist_y;
        ray->map_y += ray->step_y;
        ray->side = 1;
    }
    if (g->sett->map[ray->map_y][ray->map_x] == '1')
        ray->hit = 1;
}

void set_draw_limits(t_game *g, t_raycast *ray)
{
    ray->line_height = (int)(g->height / ray->perp_wall_dist);
    ray->draw_start = -ray->line_height / 2 + g->height / 2;
    if (ray->draw_start < 0)
        ray->draw_start = 0;
    ray->draw_end = ray->line_height / 2 + g->height / 2;
    if (ray->draw_end >= g->height)
        ray->draw_end = g->height - 1;
}

void update_frame_time(t_raycast *ray)
{
    ray->old_time = ray->time;
    ray->time = current_time();
    ray->frame_time = (double)(ray->time - ray->old_time) / 1000.0;
    ray->move_speed = 0.08;
    ray->rot_speed = ray->frame_time * 20.0;
}

void raycasting(t_game *g, t_raycast *ray)
{
    int x;
    int color;

    x = -1;
    ray->time = current_time();
    if (!g->flag)
        player_dir_plane(ray, g->cht);
    ray->pos = create_point(g->pos.x + 0.5, g->pos.y + 0.5);
    while (++x < g->width)
    {
        init_ray(g, ray, x);
        set_steps_and_sidedist(ray);
        ray->hit = 0;
        while (!ray->hit)
            check_hit(g, ray);
        cal_perp_wall_dist(ray);
        set_draw_limits(g, ray);
        color = get_wall_color(ray);
        draw_column(g, x, ray->draw_start, ray->draw_end, color);
    }
    update_frame_time(ray);
    mlx_put_image_to_window(g->mlx, g->win, g->img.ptr, 0, 0);
}

void	draw_background(t_game *g)
{
	int	x;
	int	y;
	int	color;
	int	offset;

	x = -1;
	y = -1;
	g->img.ptr = mlx_new_image(g->mlx, g->width, g->height);
	g->img.addr = mlx_get_data_addr(g->img.ptr, &g->img.bpp,
			&g->img.line_length, &g->img.endian);
	mlx_clear_window(g->mlx, g->win);
	while (++y < g->height)
	{
		x = -1;
		while (++x < g->width)
		{
			offset = y * g->img.line_length + x * (g->img.bpp / 8);
			if (y < g->height / 2)
				color = g->sett->c_roof;
			else
				color = g->sett->c_floor;
			*(unsigned int *)(g->img.addr + offset) = color;
		}
	}
}

int	render_window(t_game *g)
{
	draw_background(g);
	raycasting(g, &g->ray);
    return (0);
}
