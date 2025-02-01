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

#include "../inc/cub3d_bonus.h"

void	valid_img(t_game *g)
{
	get_img(g, &g->img);
	get_img_sprite(g, &g->spt);
	if (!g->img.no || !g->img.so || !g->img.we || !g->img.ea
		|| !g->spt.sprite[0] || !g->spt.sprite[0])
	{
		free_sett(g->sett);
		close_img(g->mlx, &g->img);
		mlx_destroy_display(g->mlx);
		free(g->mlx);
		error("Error\nFailed to load texture !\n");
	}
	init_textures(g, &g->img);
	init_textures_sprite(&g->spt, &g->img);
}

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
}

void	get_img_sprite(t_game *g, t_sprite *sp)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	sp->sprite[0] = mlx_xpm_file_to_image(g->mlx, "textures/gun1.xpm", &x, &y);
	sp->width[0] = x;
	sp->height[0] = y;
	sp->sprite[1] = mlx_xpm_file_to_image(g->mlx, "textures/gun2.xpm", &x, &y);
	sp->width[1] = x;
	sp->height[1] = y;
	if (!sp->sprite[0] || !sp->sprite[1])
	{
		printf("Error\nFailed to load texture!\n");
		exit(1);
	}
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

void	init_textures_sprite(t_sprite *sp, t_img *img)
{
	sp->s_textr = malloc(sizeof(int *) * 2);
	if (!sp->s_textr)
	{
		printf("Error\nFalha ao alocar memória para a textura!\n");
		exit(1);
	}
	sp->s_textr[0] = (int *)mlx_get_data_addr(sp->sprite[0], &img->bpp,
			&img->line_length, &img->endian);
	sp->s_textr[1] = (int *)mlx_get_data_addr(sp->sprite[1], &img->bpp,
			&img->line_length, &img->endian);
	if (!sp->s_textr[0] || !sp->s_textr[1])
	{
		printf("Erro\nFalha ao obter dados da textura!\n");
		exit(1);
	}
}
