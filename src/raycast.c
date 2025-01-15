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

t_point_d	create_point(double x, double y)
{
	t_point_d point;

	point.x = x;
	point.y = y;
	return (point);
}

void	p_direction(t_raycast *ray, char c)
{
	if (c == 'N')
	{
		ray->dir = create_point(0, -1);
		ray->plane = create_point(0.66, 0.0);
	}
	else if (c == 'S')
	{
		ray->dir = create_point(0, 1);
		ray->plane = create_point(-0.66, 0.0);
	}
	else if (c == 'E')
	{
		ray->dir = create_point(1, 0);
		ray->plane = create_point(0.0, 0.66);
	}
	else if (c == 'W')
	{
		ray->dir = create_point(-1, 0);
		ray->plane = create_point(0.0, -0.66);
	}
}

void draw_column(t_game *g, int x, int start, int end, void *image, double wallX, int side, double rayDirX, double rayDirY)
{
    int texWidth = g->img.width;
    int texHeight = g->img.height;
    int texX, texY;
    double step, texPos;

    texX = (int)(wallX * texWidth);
    if (side == 0 && rayDirX > 0)
        texX = texWidth - texX - 1;
    if (side == 1 && rayDirY < 0)
        texX = texWidth - texX - 1;
    step = 1.0 * texHeight / (end - start);
    texPos = (start - g->pos.y / 2 + (end - start) / 2) * step;
    for (int y = start; y < end; y++)
    {
        texY = (int)texPos;
        if (texY < 0) texY = 0;
        if (texY >= texHeight) texY = texHeight - 1;
        texPos += step;
        unsigned int color = *(unsigned int *)(image + (texY * texWidth + texX) * 4);
        *(unsigned int *)(g->img.addr + (y * g->img.line_length + x * (g->img.bpp / 8))) = color;
    }
}

void raycasting(t_game *g, char c)
{
    t_raycast ray;
    ray.pos = (t_point_d){g->ply.x + 0.5, g->ply.y + 0.5};
    p_direction(&ray, c);
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

        int hit = 0;
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

        double wallX;
        if (side == 0)
            wallX = ray.pos.y + perpWallDist * rayDirY;
        else
            wallX = ray.pos.x + perpWallDist * rayDirX;
        wallX -= floor(wallX);

        void *wall;
        if (side == 0 && rayDirX > 0)
            wall = g->img.ea; // EA
        else if (side == 0 && rayDirX < 0)
            wall = g->img.we; // WE
        else if (side == 1 && rayDirY > 0)
            wall = g->img.so; // SO
        else
            wall = g->img.no; // NO

        draw_column(g, x, drawStart, drawEnd, wall, wallX, side, rayDirX, rayDirY);
    }

    mlx_put_image_to_window(g->mlx, g->win, g->img.ptr, 0, 0);
}

void render_window(t_game *g)
{
    g->img.ptr = mlx_new_image(g->mlx, g->pos.x, g->pos.y);
    g->img.addr = mlx_get_data_addr(g->img.ptr, &g->img.bpp, &g->img.line_length, &g->img.endian);
    mlx_clear_window(g->mlx, g->win);
    for (int y = 0; y < g->pos.y; y++) {
        for (int x = 0; x < g->pos.x; x++) {
            if (y < g->pos.y / 2)
                *(unsigned int *)(g->img.addr + (y * g->img.line_length + x * (g->img.bpp / 8))) = g->sett->c_roof;
            else
                *(unsigned int *)(g->img.addr + (y * g->img.line_length + x * (g->img.bpp / 8))) = g->sett->c_floor;
        }
    }
    raycasting(g, g->cht);
    print_matrix(g->sett->map);
}
