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

void p_direction(t_raycast *ray, char c)
{
    if (c == 'N')
    {
        ray->dir.x = 0.0;
        ray->dir.y = -1.0;
        ray->plane.x = 0.66;
        ray->plane.y = 0.0;
    }
    else if (c == 'S')
    {
    	ray->dir.x = 0.0;
        ray->dir.y = 1.0;
        ray->plane.x = 0.66;
        ray->plane.y = 0.0;
    }
    else if (c == 'E')
    {
    	ray->dir.x = 1.0;
        ray->dir.y = 0.0;
        ray->plane.x = 0.00;
        ray->plane.y = 0.66;
    }
    else if (c == 'W')
    {
    	ray->dir.x = -1.0;
        ray->dir.y = 0.0;
        ray->plane.x = 0.0;
        ray->plane.y = -0.66;
    }
}

void	print_image(t_game *g, char c, int w, int h)
{
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.no, w, h);
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.so, w, h);
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.we, w, h);
	if (c == '1')
		mlx_put_image_to_window(g->mlx, g->win, g->img.ea, w, h);
}

void	print_map_window(t_game *g)
{
	int		i;
	int		j;
	int		wid;
	int		hei;

	i = -1;
	hei = 0;
	while (g->sett->map[++i])
	{
		j = -1;
		wid = 0;
		while (g->sett->map[i][++j])
		{	
			print_image(g, g->sett->map[i][j], wid, hei);
			wid += 32;
		}
		hei += 32;
	}
}

void	raycast(t_game *g)
{
	int	i;
	t_raycast	ray;

	i = 0;
	ray.pos = pos(g->sett->map);
	player_direction(&ray, map[pos.y][pos.x]);
	while (i < g->pos->x)
	{
		double cameraX = 2 * x / (double)g->pos->x - 1;
		double rayDirX = ray.dir.x + ray.plane.x * cameraX;
		double rayDirY = ray.dir.y + ray.plane.y * cameraX;

		int mapX = ray.pos.x;
        int mapY = ray.pos.y;

		double sideDistX, sideDistY;

		double deltaDistX = fabs(1 / rayDirX);
        double deltaDistY = fabs(1 / rayDirY);
        double perpWallDist;

        int stepX, stepY;
        if (rayDirX < 0) {
            stepX = -1;
            sideDistX = (posX - mapX) * deltaDistX;
        } else {
            stepX = 1;
            sideDistX = (mapX + 1.0 - posX) * deltaDistX;
        }
        if (rayDirY < 0) {
            stepY = -1;
            sideDistY = (posY - mapY) * deltaDistY;
        } else {
            stepY = 1;
            sideDistY = (mapY + 1.0 - posY) * deltaDistY;
        }

        // DDA
        int hit = 0, side;
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
            if (map[mapX][mapY] > 0) hit = 1;
        }

        // Distância perpendicular
        if (side == 0)
            perpWallDist = (mapX - posX + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - posY + (1 - stepY) / 2) / rayDirY;

        // Altura da parede
        int lineHeight = (int)(HEIGHT / perpWallDist);

        // Posição para desenhar
        int drawStart = -lineHeight / 2 + g->pos->y / 2;
        if (drawStart < 0) drawStart = 0;
        int drawEnd = lineHeight / 2 + g->pos->y / 2;
        if (drawEnd >= g->pos->y)
        	drawEnd = g->pos->y - 1;
		i++;
	}

}
