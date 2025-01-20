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

t_point_d	pos(char **map)
{
	int		i;
	int		j;
	t_point_d	pos;

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
				pos.y = i;
				pos.x = j;
				return (pos);
			}
		}
	}
	return (pos);
}
