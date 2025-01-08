/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:54:27 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/08 15:54:29 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	character(char c)
{
	return (c == 'N' || c == 'S' || c == 'W' || c == 'E');
}

t_point	pos(char **map)
{
	int		i;
	int		j;
	t_point	pos;

	i = -1;
	pos.x = 0;
	pos.y = 0;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (character(map[i][j]))
			{
				pos.x = i;
				pos.y = j;
				return (pos);
			}
		}
	}
	return (pos);
}

void player_direction(t_raycast *ray, char c)
{
    if (c == 'N')
    {
        ray->dir.x = 0.0;
        ray->dir.y = -1.0;
        ray->plane.x = 0.66;
        ray->plane.y = 0.0;
    }
    else if (c == 'S')
    {
    	ray->dir.x = 0.0;
        ray->dir.y = 1.0;
        ray->plane.x = 0.66;
        ray->plane.y = 0.0;
    }
    else if (c == 'E')
    {
    	ray->dir.x = 1.0;
        ray->dir.y = 0.0;
        ray->plane.x = 0.00;
        ray->plane.y = 0.66;
    }
    else if (c == 'W')
    {
    	ray->dir.x = -1.0;
        ray->dir.y = 0.0;
        ray->plane.x = 0.0;
        ray->plane.y = -0.66;
    }
}