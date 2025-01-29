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

void	get_img_sprite(t_game *g, t_sprite *sp)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	sp->sprite[0] = mlx_xpm_file_to_image(g->mlx, "textures/gun1.xpm", &x, &y);
	sp->sprite[1] = mlx_xpm_file_to_image(g->mlx, "textures/gun2.xpm", &x, &y);
	if (!sp->sprite[0] || !sp->sprite[1])
	{
		printf("Error: Failed to load sprite\n");
		exit(1);
	}
	sp->width = x;
	sp->height = y;
}

void	init_textures_sprinte(t_sprite *sp, t_img *img)
{
	sp->s_textr = malloc(sizeof(int *) * 2);
	if (!sp->s_textr)
	{
		printf("Error: Failed to allocate sprite textures\n");
		exit(1);
	}
	sp->s_textr[0] = (int *)mlx_get_data_addr(sp->sprite[0], &img->bpp, &img->line_length, &img->endian);
	sp->s_textr[1] = (int *)mlx_get_data_addr(sp->sprite[1], &img->bpp, &img->line_length, &img->endian);
	if (!sp->s_textr[0] || !sp->s_textr[1])
	{
		printf("Error: Failed to get sprite texture data\n");
		exit(1);
	}
}

void draw_sprites(t_game *g, t_sprite *sp)
{
    int x, y;
    int screen_x = (g->width - sp->width) / 2;
    int screen_y = g->height - sp->height;
    int *texture = sp->s_textr[0];
    int tex_x, tex_y;
    
    y = 0;
    while (y < sp->height)
    {
        tex_y = (y * sp->height) / sp->height;
        x = 0;
        while (x < sp->width)
        {
            tex_x = (x * sp->width) / sp->width;
            draw_pixel(&g->img, screen_x + x, screen_y + y, texture[tex_y * sp->width + tex_x]);
            x++;
        }
        y++;
    }
}