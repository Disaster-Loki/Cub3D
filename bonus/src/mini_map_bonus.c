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

#define TILE_SIZE 10 // Tamanho de cada bloco no mini-mapa
#define PLAYER_COLOR 0xFF0000 // Cor do jogador (vermelho)
#define WALL_COLOR 0x0000FF // Cor das paredes (azul)
#define FLOOR_COLOR 0x808080 // Cor do chão (cinza)
#define SPACE_BETWEEN_TILES 1 // Espaço entre os tiles

void	draw_square(t_img *img, int x, int y, int color)
{
	for (int i = 0; i < TILE_SIZE - SPACE_BETWEEN_TILES; i++)
	{
		for (int j = 0; j < TILE_SIZE - SPACE_BETWEEN_TILES; j++)
		{
			draw_pixel(img, x + i, y + j, color);
		}
	}
}

void	draw_player(t_img *img, int player_x, int player_y)
{
	int	radius = (TILE_SIZE - SPACE_BETWEEN_TILES) / 2;
	int	center_x = player_x + radius;
	int	center_y = player_y + radius;

	for (int i = -radius; i <= radius; i++)
	{
		for (int j = -radius; j <= radius; j++)
		{
			if (i * i + j * j <= radius * radius) // Dentro do círculo
				draw_pixel(img, center_x + i, center_y + j, PLAYER_COLOR);
		}
	}
}

void	mini_map(t_game *g)
{
	int	map_x, map_y;
	int	screen_x, screen_y;

	map_y = 0;
	screen_y = 0;
	while (g->sett->map[map_y] && map_y < (int)(g->height / TILE_SIZE))
	{
		map_x = 0;
		screen_x = 0;
		while (g->sett->map[map_y][map_x] && map_x < (int)(g->width / TILE_SIZE))
		{
			if (g->sett->map[map_y][map_x] == '1')
				draw_square(&g->img, screen_x, screen_y, WALL_COLOR);
			else if (g->sett->map[map_y][map_x] == '0')
				draw_square(&g->img, screen_x, screen_y, FLOOR_COLOR);
			map_x++;
			screen_x += TILE_SIZE;
		}
		map_y++;
		screen_y += TILE_SIZE;
	}

	// Desenha o jogador com base na posição real (g->pos.x, g->pos.y)
	int	player_screen_x = (int)(g->pos.x * TILE_SIZE);
	int	player_screen_y = (int)(g->pos.y * TILE_SIZE);
	draw_player(&g->img, player_screen_x, player_screen_y);
}