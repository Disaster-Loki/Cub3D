/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:35:24 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/08 15:35:27 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	alter_position(t_game *game, t_point pos, int x, int y)
{
	char	ch;
	char	move;

	if (pos.x + x > game->pos.x || pos.y + y > game->pos.y)
		return ;
	ch = game->sett->map[pos.x][pos.y];
	move = game->sett->map[pos.x + x][pos.y + y];
	if (move != '1' && character(ch))
	{
		game->sett->map[pos.x][pos.y] = '0';
		game->sett->map[pos.x + x][pos.y + y] = ch;
		render_window(game);
	}
}

int	keypress(int key, t_game *game)
{
	game->ply = pos(game->sett->map);
	if (key == 'w' || key == 65362)
		alter_position(game, game->ply, -1, 0);
	if (key == 's' || key == 65364)
		alter_position(game, game->ply, 1, 0);
	if (key == 'd' || key == 65363)
		alter_position(game, game->ply, 0, 1);
	if (key == 'a' || key == 65361)
		alter_position(game, game->ply, 0, -1);
	if (key == ESC)
		close_game(game);
	return (1);
}