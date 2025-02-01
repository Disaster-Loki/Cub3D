/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:46:22 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/24 12:46:26 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	get_img(t_game *g, t_img *img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	img->no = mlx_xpm_file_to_image(g->mlx, g->sett->no, &x, &y);
	img->so = mlx_xpm_file_to_image(g->mlx, g->sett->so, &x, &y);
	img->we = mlx_xpm_file_to_image(g->mlx, g->sett->we, &x, &y);
	img->ea = mlx_xpm_file_to_image(g->mlx, g->sett->ea, &x, &y);
	img->width = x;
	img->height = y;
	valid_img(g);
}

void	init_textures(t_game *g, t_img *img)
{
	g->textr = malloc(sizeof(int *) * 4);
	g->textr[0] = (int *)mlx_get_data_addr(img->no, &img->bpp,
			&img->line_length, &img->endian);
	g->textr[1] = (int *)mlx_get_data_addr(img->so, &img->bpp,
			&img->line_length, &img->endian);
	g->textr[2] = (int *)mlx_get_data_addr(img->ea, &img->bpp,
			&img->line_length, &img->endian);
	g->textr[3] = (int *)mlx_get_data_addr(img->we, &img->bpp,
			&img->line_length, &img->endian);
}

void	valid_img(t_game *g)
{
	if (!g->img.no || !g->img.so || !g->img.we || !g->img.ea)
	{
		free_sett(g->sett);
		close_img(g->mlx, &g->img);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		error("Error\nFailed to load texture!\n");
	}
}