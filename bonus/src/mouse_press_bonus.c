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

#include "../inc/cub3d_bonus.h"

int	mouse_hook(int button, int x, int y, t_game *g)
{
	(void)x;
	(void)y;
	if (button == LEFT_BUTTON_MOUSE)
	{
		g->spt.frame = 1;
		g->spt.time = 10;
	}
	return (0);
}

int	mouse_move(int x, int y, t_game *g)
{
	static int	prev_x = 0;

	(void)y;
	if (prev_x == 0)
		prev_x = g->width / 2;
	if (x > prev_x)
		rotate_view(&g->ray, g->ray.rot_speed);
	else if (x < prev_x)
		rotate_view(&g->ray, -g->ray.rot_speed);
	prev_x = x;
	return (0);
}
