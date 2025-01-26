/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:03:31 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/08 12:43:51 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	free_sett(t_sett *sett)
{
	free(sett->no);
	free(sett->so);
	free(sett->we);
	free(sett->ea);
	free_max(sett->map);
}

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
	if (img->ptr)
		mlx_destroy_image(mlx, img->ptr);
}

int	close_game(t_game *game)
{
	free(game->textr);
	free_sett(game->sett);
	close_img(game->mlx, &game->img);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
