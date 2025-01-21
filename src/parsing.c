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

char	*get_value2(char **max, char *str)
{
	int		i;
	int		len;
	char	*tmp;

	i = -1;
	len = ft_strlen(str);
	while (max[++i])
	{
		tmp = ft_strtrim(max[i], " ");
		if (!ft_strncmp(tmp, str, len) && tmp[len] == ' ')
			return (tmp + len);
		free(tmp);
	}
	return (NULL);
}

char	*get_value(char **max, char *str)
{
	char	*temp;
	int		i;
	int		len;

	i = -1;
	len = ft_strlen(str);
	while (max[++i])
	{
		temp = ft_strtrim(max[i], " ");
		if (!ft_strncmp(temp, str, len) && temp[len] == ' ')
			return (temp);
		free(temp);
	}
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
	floor = get_value2(max, "F");
	roof = get_value2(max, "C");
	sett.c_floor = rgb_to_hex(floor);
	sett.c_roof = rgb_to_hex(roof);
	sett.no = get_value2(max, "NO");
	sett.so = get_value2(max, "SO");
	sett.we = get_value2(max, "WE");
	sett.ea = get_value2(max, "EA");
	sett.map = get_map(max);
	free_max(max);
	return (sett);
}
