/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:42:08 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/08 12:28:04 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	*get_value(char **max, char *str)
{
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(str);
	while (max[++i])
		if (!ft_strncmp(max[i], str, len) && max[i][len] == ' ')
			return (max[i] + len);
	return (NULL);
}

unsigned int	rgb_to_hex(char *rgb)
{
	int		r;
	int		g;
	int		b;
	char	**sp;

	sp = ft_split(rgb, ',');
	r = ft_atoi(sp[0]);
	g = ft_atoi(sp[1]);
	b = ft_atoi(sp[2]);
	free_max(sp);
	return ((r << 16) | (g << 8) | b);
}

char	**get_map(char **max)
{
	char	**map;
	int	i;
	int	j;

	i = 6;
	while (max[i])
		i++;
	map = malloc(sizeof(char *) * (i - 5));
	if (!map)
		return (NULL);
	i = 6;
	j = 0;
	while (max[i])
	{
		map[j++] = ft_strdup(max[i]);
		i++;
	}
	map[j] = NULL;
	return (map);
}

t_sett	parsing(char *str)
{
	t_sett	sett;
	char	**max;
	char	*roof;
	char	*floor;

	max = get_file(str);
	floor = ft_strtrim(get_value(max, "F"), " ");
	roof = ft_strtrim(get_value(max, "C"), " ");
	sett.c_floor = rgb_to_hex(floor);
	sett.c_roof = rgb_to_hex(roof);
	sett.no = ft_strtrim(get_value(max, "NO"), " ");
	sett.so = ft_strtrim(get_value(max, "SO"), " ");
	sett.we = ft_strtrim(get_value(max, "WE"), " ");
	sett.ea = ft_strtrim(get_value(max, "EA"), " ");
	sett.map = get_map(max);
	return (sett);
}
