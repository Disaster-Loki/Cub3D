/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_draw.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 12:44:13 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/24 12:44:18 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	get_texture_id(t_raycast *ray)
{
	if (ray->side == 0 && ray->ray_dir_x > 0)
		return (0);
	if (ray->side == 0 && ray->ray_dir_x < 0)
		return (1);
	if (ray->side == 1 && ray->ray_dir_y > 0)
		return (2);
	return (3);
}

void	draw_textr(t_game *g, t_raycast *ray, int x)
{
	int		i;
	int		color;
	double	step;
	double	tex_pos;
	int		border_size;

	ray->tex_x = (int)(ray->wall_x * (double)g->img.width);
	if ((ray->side == 0 && ray->ray_dir_x > 0)
		|| (ray->side == 1 && ray->ray_dir_y < 0))
		ray->tex_x = g->img.width - ray->tex_x - 1;
	border_size = ray->line_height / 10;
	step = 1.0 * g->img.height / ray->line_height;
	tex_pos = (ray->draw_start - g->height / 2 + ray->line_height / 2) * step;
	i = ray->draw_start - 1;
	while (++i < ray->draw_end)
	{
		ray->tex_y = (int)tex_pos & (g->img.height - 1);
		tex_pos += step;
		if (ray->hit == 2)
		{
			if (i < ray->draw_start + border_size || i > ray->draw_end - border_size)
				color = 0x1E90FF; // Borda da porta (azul claro)
			else
				color = 0x00008B; // Porta (azul escuro)
		}
		else
			color = g->textr[ray->tex_id][g->img.height * ray->tex_y + ray->tex_x];
		draw_pixel(&g->img, x, i, color);
	}
}