/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:03:31 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/07 13:03:35 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	close_img(void *mlx, t_img *img)
{
	if (img->no)
		mlx_destroy_image(mlx, img->no);
	if (img->so)
		mlx_destroy_image(mlx, img->so);
	if (img->we)
		mlx_destroy_image(mlx, img->we);
	if (img->ea)
		mlx_destroy_image(mlx, img->ea);
}

int	win_close(t_game *game)
{
	//free_max(game->map);
	close_img(game->mlx, &game->img);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	return (0);
}

int	close_game(t_game *game)
{
	if (!win_close(game))
		exit(0);
	return (0);
}
