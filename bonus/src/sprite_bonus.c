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

void	stop_sprite(t_sprite *sp)
{
	if (sp->frame == 1 && sp->time > 0)
		sp->time--;
	else
		sp->frame = 0;
}

double	cal_scales(t_game *g, int index)
{
	double	scale_x;
	double	scale_y;
	double	scale;

	scale_x = g->width / g->spt.width[index];
	scale_y = g->height / g->spt.height[index];
	scale = (fmin(scale_x, scale_y) / 2.4);
	return (scale);
}

void	init_vars_sprite(t_game *g, t_sprite *sp, int index)
{
	sp->scale = cal_scales(g, index);
	sp->new_width = sp->width[index] * sp->scale;
	sp->new_height = sp->height[index] * sp->scale + sp->offset_y;
	sp->screen_x = (g->width - sp->new_width) / 2;
	sp->screen_y = g->height - sp->new_height;
	sp->texture = (char *)sp->s_textr[index];
}

void	draw_sprites(t_game *g, t_sprite *sp)
{
	int	x;
	int	y;
	int	index;
	int	color;

	index = sp->frame;
	init_vars_sprite(g, sp, index);
	y = -1;
	while (++y < sp->new_height)
	{
		x = -1;
		sp->tex_y = (y * sp->height[index]) / sp->new_height;
		while (++x < sp->new_width)
		{
			sp->tex_x = (x * sp->width[index]) / sp->new_width;
			color = *(int *)(sp->texture
					+ (sp->tex_y * sp->width[index] + sp->tex_x)
					* (g->img.bpp / 8));
			if ((color & 0xFFFFFF) != 0x000000)
				draw_pixel(&g->img, sp->screen_x + x, sp->screen_y + y, color);
		}
	}
}
