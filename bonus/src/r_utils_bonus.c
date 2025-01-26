/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 11:03:09 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/17 11:03:11 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

t_point_d	create_point(double x, double y)
{
	t_point_d	point;

	point.x = x;
	point.y = y;
	return (point);
}

void	player_dir_plane(t_raycast *ray, char c)
{
	if (c == 'N')
	{
		ray->dir = create_point(0, -1);
		ray->plane = create_point(0.66, 0.0);
	}
	else if (c == 'S')
	{
		ray->dir = create_point(0, 1);
		ray->plane = create_point(-0.66, 0.0);
	}
	else if (c == 'E')
	{
		ray->dir = create_point(1, 0);
		ray->plane = create_point(0.0, 0.66);
	}
	else if (c == 'W')
	{
		ray->dir = create_point(-1, 0);
		ray->plane = create_point(0.0, -0.66);
	}
}
