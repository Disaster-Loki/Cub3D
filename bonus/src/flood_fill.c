/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 16:22:45 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/01/31 09:53:45 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	fill(char **map, t_size size, t_cur cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0
		|| cur.x >= size.x || map[cur.y][cur.x] != to_fill)
	{
		if (map[cur.y][cur.x] == 'X' || map[cur.y][cur.x] == '0')
			map[cur.y][cur.x] = '-';
		else
			return ;
	}
	fill(map, size, (t_cur){cur.y + 1, cur.x}, to_fill);
	fill(map, size, (t_cur){cur.y - 1, cur.x}, to_fill);
	fill(map, size, (t_cur){cur.y, cur.x + 1}, to_fill);
	fill(map, size, (t_cur){cur.y, cur.x - 1}, to_fill);
}

void	flood_fill(char **map, t_size size, t_cur cur)
{
	fill(map, size, cur, map[cur.y][cur.x]);
}
