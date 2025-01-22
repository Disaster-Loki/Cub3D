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
	while (++i < end)
	{
		pixel = (char *)g->img.addr
			+ (i * g->img.line_length + x * (g->img.bpp / 8));
		*(unsigned int *)pixel = color;
		pixel += g->img.line_length;
	}
}

int	get_wall_color(t_raycast *ray)
{
	if (ray->side == 0 && ray->ray_dir_x > 0)
		return (0xFF0000);
	if (ray->side == 0 && ray->ray_dir_x < 0)
		return (0x0000FF);
	if (ray->side == 1 && ray->ray_dir_y > 0)
		return (0x00FF00);
	return (0xFFFF00);
}

void	raycasting(t_game *g, t_raycast *ray)
{
	int	x;
	int	color;

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

int	render_window(t_game *g)
{
	clear_window(g);
	draw_background(g);
	raycasting(g, &g->ray);
	return (0);
}
