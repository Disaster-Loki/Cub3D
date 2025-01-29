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

#include "../inc/cub3d_bonus.h"

void	set_tex_wall_x(t_raycast *ray)
{
	ray->tex_id = get_texture_id(ray);
	if (ray->side == 0)
		ray->wall_x = ray->pos.y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = ray->pos.x + ray->perp_wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor((ray->wall_x));
}

void	raycasting(t_game *g, t_raycast *ray)
{
	int	x;

	x = -1;
	ray->time = current_time();
	ray->pos = g->pos;
	while (++x < g->width)
	{
		init_ray(g, ray, x);
		set_steps_and_sidedist(ray);
		ray->hit = 0;
		while (!ray->hit)
			check_hit(g, ray);
		cal_perp_wall_dist(ray);
		set_draw_limits(g, ray);
		set_tex_wall_x(ray);
		draw_textr(g, ray, x);
	}
	update_frame_time(ray);
}

int	render_window(t_game *g)
{
	clear_window(g);
	draw_background(g);
	close_door(g);
	raycasting(g, &g->ray);
	mini_map(g);
	draw_sprites(g, &g->sprite);
	mlx_put_image_to_window(g->mlx, g->win, g->img.ptr, 0, 0);
	return (0);
}
