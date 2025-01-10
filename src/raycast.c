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

void p_direction(t_raycast *ray, char c) {
    if (c == 'N') {
        ray->dir.x = 0;
        ray->dir.y = -1;
        ray->plane.x = 0.66;
        ray->plane.y = 0.0;
    } else if (c == 'S') {
        ray->dir.x = 0;
        ray->dir.y = 1;
        ray->plane.x = -0.66;
        ray->plane.y = 0.0;
    } else if (c == 'E') {
        ray->dir.x = 1;
        ray->dir.y = 0;
        ray->plane.x = 0.0;
        ray->plane.y = 0.66;
    } else if (c == 'W') {
        ray->dir.x = -1;
        ray->dir.y = 0;
        ray->plane.x = 0.0;
        ray->plane.y = -0.66;
    }
}

t_point_d find_player_position(char **map)
{
    t_point_d pos;
    pos.x = 0;
    pos.y = 0;
    for (int y = 0; map[y]; y++) {
        for (int x = 0; map[y][x]; x++) {
            if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W') {
                pos.x = x + 0.5;
                pos.y = y + 0.5;
                return pos;
            }
        }
    }
    return pos;
}

void draw_column(t_game *g, int x, int start, int end, void *img) {
    for (int y = 0; y < g->pos.y; y++) {
        if (y >= start && y <= end) {
            mlx_put_image_to_window(g->mlx, g->win, img, x, y);
        }
    }
}

void raycasting(t_game *g) {
    t_raycast ray;
    ray.pos = find_player_position(g->sett->map);
    p_direction(&ray, g->sett->map[(int)ray.pos.y][(int)ray.pos.x]);

    for (int x = 0; x < g->pos.x; x++) {
        double cameraX = 2 * x / (double)g->pos.x - 1;
        double rayDirX = ray.dir.x + ray.plane.x * cameraX;
        double rayDirY = ray.dir.y + ray.plane.y * cameraX;

        int mapX = (int)ray.pos.x;
        int mapY = (int)ray.pos.y;

        double sideDistX;
        double sideDistY;

        double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double perpWallDist;

        int stepX;
        int stepY;
        int hit = 0;
        int side;

        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (ray.pos.x - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - ray.pos.x) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (ray.pos.y - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - ray.pos.y) * deltaDistY;
        }

        while (!hit) {
            if (sideDistX < sideDistY) {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            } else {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }
            if (g->sett->map[mapY][mapX] == '1')
                hit = 1;
        }
        if (side == 0)
            perpWallDist = (mapX - ray.pos.x + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - ray.pos.y + (1 - stepY) / 2) / rayDirY;

        int lineHeight = (int)(g->pos.y / perpWallDist);

        int drawStart = -lineHeight / 2 + g->pos.y / 2;
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = lineHeight / 2 + g->pos.y / 2;
        if (drawEnd >= g->pos.y)
            drawEnd = g->pos.y - 1;

        void *wallImage;
        if (side == 0 && rayDirX > 0)
            wallImage = g->img.ea;
        else if (side == 0 && rayDirX < 0)
            wallImage = g->img.we;
        else if (side == 1 && rayDirY > 0)
            wallImage = g->img.so;
        else
            wallImage = g->img.no;
        draw_column(g, x, drawStart, drawEnd, wallImage);
    }
}

void render_window(t_game *g)
{
	int		bpp;
	char	*addr;
	int		endian;
	int		line_length;

	g->img.ptr = mlx_new_image(g->mlx, g->pos.x, g->pos.y);
	addr = mlx_get_data_addr(g->img.ptr, &bpp, &line_length, &endian);
	for (int y = 0; y < g->pos.y; y++)
	{
		for (int x = 0; x < g->pos.x; x++)
		{
			if (y < (g->pos.y / 2))
				*(unsigned int *)(addr + (y * line_length + x * (bpp / 8))) = g->sett->c_floor;
			else
				*(unsigned int *)(addr + (y * line_length + x * (bpp / 8))) = g->sett->c_roof;
		}
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img.ptr, 0, 0);
	raycasting(g);
}