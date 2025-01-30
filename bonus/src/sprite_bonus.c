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

void get_img_sprite(t_game *g, t_sprite *sp)
{
    int x = 0, y = 0;
    sp->sprite[0] = mlx_xpm_file_to_image(g->mlx, "textures/gun1.xpm", &x, &y);
    if (!sp->sprite[0])
    {
        printf("Erro: Falha ao carregar a textura!\n");
        exit(1);
    }
    sp->width[0] = x;
    sp->height[0] = y;
}

void init_textures_sprite(t_sprite *sp, t_img *img)
{
    sp->s_textr = malloc(sizeof(int *) * 2);
    if (!sp->s_textr)
    {
        printf("Erro: Falha ao alocar memória para a textura!\n");
        exit(1);
    }
    sp->s_textr[0] = (int *)mlx_get_data_addr(sp->sprite[0], &img->bpp, &img->line_length, &img->endian);
    if (!sp->s_textr[0])
    {
        printf("Erro: Falha ao obter dados da textura!\n");
        exit(1);
    }
    printf("Textura obtida: bpp=%d, line_length=%d, endian=%d\n", img->bpp, img->line_length, img->endian);
}

int enhance_black(int color, float factor)
{
    int r = (color >> 16) & 0xFF;
    int g = (color >> 8) & 0xFF;
    int b = color & 0xFF;

    if (r < 50 && g < 50 && b < 50) // Se for escuro, escurece mais
    {
        r *= factor;
        g *= factor;
        b *= factor;
    }

    if (r < 0) r = 0;
    if (g < 0) g = 0;
    if (b < 0) b = 0;

    return (r << 16) | (g << 8) | b;
}

int adjust_brightness(int color, float factor)
{
    int r = ((color >> 16) & 0xFF) * factor;
    int g = ((color >> 8) & 0xFF) * factor;
    int b = (color & 0xFF) * factor;

    if (r > 255) r = 255;
    if (g > 255) g = 255;
    if (b > 255) b = 255;

    return (r << 16) | (g << 8) | b;
}

void	stop_offset(t_sprite *sp)
{
	usleep(1000);
	sp->offset_y = 0;
}

void draw_sprites(t_game *g, t_sprite *sp)
{
    float scale = 1.6;
    int x, y, tex_x, tex_y, color;
    int new_width = sp->width[0] * scale;
    int new_height = sp->height[0] * scale + sp->offset_y;
    int screen_x = (g->width - new_width) / 2;
    int screen_y = g->height - new_height;
    char *texture_data = (char *)sp->s_textr[0];

    y = 0;
    while (y < new_height)
    {
        tex_y = (y * sp->height[0]) / new_height;
        x = 0;
        while (x < new_width)
        {
            tex_x = (x * sp->width[0]) / new_width;
            color = *(int *)(texture_data + (tex_y * sp->width[0] + tex_x) * (g->img.bpp / 8));

            if ((color & 0xFFFFFF) != 0x000000)
            {
                float brightness = 1.0;
                if (tex_x < 5 || tex_x > sp->width[0] - 5 || tex_y < 5 || tex_y > sp->height[0] - 5)
                    brightness = 1.5;
                color = adjust_brightness(color, brightness);
                color = enhance_black(color, 0.9);
                draw_pixel(&g->img, screen_x + x, screen_y + y, color);
            }
            x++;
        }
        y++;
    }
}


