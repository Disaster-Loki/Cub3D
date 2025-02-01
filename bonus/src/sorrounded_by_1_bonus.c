/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorrounded_by_1_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:28:04 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/01/31 09:30:43 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

int	bigger_line(char **mat)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (mat[++i])
	{
		if (len < (int)ft_strlen(mat[i]))
			len = ft_strlen(mat[i]);
	}
	free_max(mat);
	return (len);
}

void	last_char(char **map, char **max)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (map[i])
	{
		str = ft_strtrim(map[i], " ");
		j = 0;
		while (str[j + 1])
			j++;
		if (str[j] != ' ' && str[j] != '\t' && str[j] != '1')
		{
			free(str);
			free_max(map);
			free_max(max);
			error("Error\nThe map should be sorrorunded by 1!\n");
		}
		free(str);
		i++;
	}
}

void	char_by_char(char **map2, char **map, char **max)
{
	int	i;
	int	j;

	i = 0;
	while (map2[i])
	{
		j = 0;
		while (map2[i][j])
		{
			if (map2[i][j] == '0' && (map2[i - 1][j] == ' '
				|| map2[i + 1][j] == ' '))
			{
				free_max(map2);
				free_max(map);
				free_max(max);
				error("Error\nThe map should be sorrounded by 1!!\n");
			}
			j++;
		}
		i++;
	}
	free_max(map2);
}

void	inside_map(char **map, char **max)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0' && ((map[i - 1][j] == ' '
				|| map[i + 1][j] == '\0')
				|| (map[i - 1][j] == '\0'
				|| map[i + 1][j] == '\0')))
			{
				free_max(map);
				free_max(max);
				error("Error\nThe map should be sorrounded by 1!!\n");
			}
			j++;
		}
		i++;
	}
}

void	walls_at_edges(char **map, char **max)
{
	last_line(map, max);
	middle_lines(map, max);
	last_char(map, max);
	inside_map(map, max);
}
