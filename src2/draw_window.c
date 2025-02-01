/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:54:02 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/22 15:54:07 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	create_image(t_game *g, t_img *img)
{
	img->ptr = mlx_new_image(g->mlx, g->width, g->height);
	img->addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->line_length, &img->endian);
}

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	draw_background(t_game *g)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	y = -1;
	while (++y < g->height)
	{
		x = -1;
		while (++x < g->width)
		{
			if (y < g->height / 2)
				color = g->sett->c_roof;
			else
				color = g->sett->c_floor;
			draw_pixel(&g->img, x, y, color);
		}
	}
}

void	clear_window(t_game *g)
{
	int	x;
	int	y;
	int	color;

	x = -1;
	y = -1;
	color = 0x000000;
	while (++y < g->height)
	{
		x = -1;
		while (++x < g->width)
			draw_pixel(&g->img, x, y, color);
	}
}
