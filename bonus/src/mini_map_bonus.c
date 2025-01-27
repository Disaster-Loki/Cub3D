/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:54:02 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/22 15:54:07 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"
#define TILE_SIZE 10
#define PLAYER_COLOR 0xFF0000
#define WALL_COLOR 0x0000FF
#define DOOR_COLOR 0xFFFF00
#define FLOOR_COLOR 0x808080
#define SPACE_BETWEEN_TILES 0

void	draw_square(t_img *img, int x, int y, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < TILE_SIZE - SPACE_BETWEEN_TILES)
	{
		j = 0;
		while (j < TILE_SIZE - SPACE_BETWEEN_TILES)
		{
			draw_pixel(img, x + i, y + j, color);
			j++;
		}
		i++;
	}
}

void	draw_player(t_img *img, double player_x, double player_y)
{
	int	radius;
	int	center_x;
	int	center_y;
	int	x;
	int	y;

	radius = TILE_SIZE / 3;
	center_x = (int)(player_x);
	center_y = (int)(player_y);
	x = -radius;
	while (x <= radius)
	{
		y = -radius;
		while (y <= radius)
		{
			if (x * x + y * y <= radius * radius)
				draw_pixel(img, center_x + x, center_y + y, PLAYER_COLOR);
			y++;
		}
		x++;
	}
}

int	valid_min_map(t_game *g, int map_x, int map_y)
{
	return (g->sett->map[map_y][map_x]
			&& map_x < (int)(g->width / TILE_SIZE));
}

void	mini_map(t_game *g)
{
	int	map_x;
	int	map_y;
	int	screen_x;
	int	screen_y;

	map_y = -1;
	screen_y = 0;
	while (g->sett->map[++map_y] && map_y < (int)(g->height / TILE_SIZE))
	{
		map_x = 0;
		screen_x = 0;
		while (valid_min_map(g, map_x, map_y))
		{
			if (g->sett->map[map_y][map_x] == '1')
				draw_square(&g->img, screen_x, screen_y, WALL_COLOR);
			else if (g->sett->map[map_y][map_x] == '0')
				draw_square(&g->img, screen_x, screen_y, FLOOR_COLOR);
			else if (g->sett->map[map_y][map_x] == 'X')
				draw_square(&g->img, screen_x, screen_y, DOOR_COLOR);
			map_x++;
			screen_x += TILE_SIZE;
		}
		screen_y += TILE_SIZE;
	}
	draw_player(&g->img, g->pos.x * TILE_SIZE, g->pos.y * TILE_SIZE);
}
