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

void	init_buffer(t_game *g)
{
	int	i;

	g->buffer = malloc(sizeof(int *) * g->height);
	if (!g->buffer)
		error("Error: Failed to allocate buffer memory.");
	i = -1;
	while (++i < g->height)
	{
		g->buffer[i] = malloc(sizeof(int) * g->width);
		if (!g->buffer[i])
			error("Error: Failed to allocate buffer row\n");
	}
}

void init_textures(t_game *g)
{
    g->textr = malloc(sizeof(int *) * 4);
    if (!g->textr)
        error("Error: Failed to allocate textures\n");

    g->textr[0] = (int *)mlx_get_data_addr(g->img.no, &g->img.bpp, &g->img.line_length, &g->img.endian);
    g->textr[1] = (int *)mlx_get_data_addr(g->img.so, &g->img.bpp, &g->img.line_length, &g->img.endian);
    g->textr[2] = (int *)mlx_get_data_addr(g->img.ea, &g->img.bpp, &g->img.line_length, &g->img.endian);
    g->textr[3] = (int *)mlx_get_data_addr(g->img.we, &g->img.bpp, &g->img.line_length, &g->img.endian);
}

int	get_texture_id(t_raycast *ray)
{
	if (ray->side == 0 && ray->ray_dir_x > 0)
		return (0); // Norte
	if (ray->side == 0 && ray->ray_dir_x < 0)
		return (1); // Sul
	if (ray->side == 1 && ray->ray_dir_y > 0)
		return (2); // Leste
	return (3); // Oeste
}

void	draw_textr(t_game *g, int x, int start, int end, t_raycast *ray)
{
	int		i;
	int		tex_x;
	int		tex_y;
	double	step;
	double	tex_pos;
	int		color;

	tex_x = (int)(ray->wall_x * (double)g->img.width);
	if ((ray->side == 0 && ray->ray_dir_x > 0) || (ray->side == 1 && ray->ray_dir_y < 0))
		tex_x = g->img.width - tex_x - 1;
	step = 1.0 * g->img.height / (ray->draw_end - ray->draw_start);
	tex_pos = (start - g->height / 2 + (ray->draw_end - ray->draw_start) / 2) * step;
	i = start - 1;
	while (++i < end)
	{
		tex_y = (int)tex_pos & (g->img.height - 1);
		tex_pos += step;
		color = g->textr[ray->tex_id][g->img.height * tex_y + tex_x];
		if ((color & 0x00FFFFFF) != 0)
			g->buffer[i][x] = color;
	}
}

void	raycasting(t_game *g, t_raycast *ray)
{
	int	x;

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
		ray->tex_id = get_texture_id(ray);
		draw_textr(g, x, ray->draw_start, ray->draw_end, ray);
	}
	update_frame_time(ray);
	mlx_put_image_to_window(g->mlx, g->win, g->img.ptr, 0, 0);
}

void	copy_buffer_to_image(t_game *g)
{
	int x;
	int y;

	y = 0;
	while (y < g->height)
	{
		x = 0;
		while (x < g->width)
		{
			((int *)(g->img.addr))[y * g->width + x] = g->buffer[y][x];
			x++;
		}
		y++;
	}
}

int	render_window(t_game *g)
{
	clear_window(g);
	draw_background(g);
	raycasting(g, &g->ray);
	copy_buffer_to_image(g);
	return (0);
}