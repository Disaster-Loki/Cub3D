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

void	close_img_sprite(void *mlx, t_sprite *sp)
{
	if (sp->sprite[0])
		mlx_destroy_image(mlx, sp->sprite[0]);
	if (sp->sprite[1])
		mlx_destroy_image(mlx, sp->sprite[1]);
}

int	close_game(t_game *game)
{
	free(game->door);
	free(game->textr);
	free(game->spt.s_textr);
	free_sett(game->sett);
	close_img(game->mlx, &game->img);
	close_img_sprite(game->mlx, &game->spt);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
	return (0);
}
