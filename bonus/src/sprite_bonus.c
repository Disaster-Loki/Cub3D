/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:39:50 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/08 12:44:17 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void    load_textures_sprite(t_game *g, t_sprite *sp)
{
    int x;
    int y;

    x = 0;
    y = 0;
    sp->sprite[0] = mlx_xpm_file_to_image(g->mlx, "textures/sprite.xmp", &x, &y);
    sp->sprite[1] = mlx_xpm_file_to_image(g->mlx, "textures/sprite.xmp", &x, &y);
    sp->sprite[2] = mlx_xpm_file_to_image(g->mlx, "textures/sprite.xmp", &x, &y);
}

void    init_textr_sprite(t_game *g, t_sprite *sp, t_img *img)
{
    sp->s_textr = malloc(sizeof(int *) * 3);
    sp->s_textr[0] = (int *)mlx_get_data_addr(sp->sprite[0], &img->bpp,
			&img->line_length, &img->endian);
	sp->s_textr[1] = (int *)mlx_get_data_addr(sp->sprite[0], &img->bpp,
			&img->line_length, &img->endian);
	sp->s_textr[2] = (int *)mlx_get_data_addr(sp->sprite[0], &img->bpp,
			&img->line_length, &img->endian);
}

void    sprite_player()
{
    
}