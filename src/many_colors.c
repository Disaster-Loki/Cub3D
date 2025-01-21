/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:27:32 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/01/16 10:55:59 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	**split_color(char *str)
{
	char	**res;
	char	**res2;

	res = ft_split(str, ' ');
	res2 = ft_split(res[1], ',');
	free_max(res);
	return (res2);
}

void	one_roof(char **max)
{
	char	*temp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (max[++i])
	{
		temp = ft_strtrim(max[i], " ");
		if (!ft_strncmp(temp, "C ", 2) && (temp[1] == ' ' || temp[1] == '\t'))
			j++;
		free(temp);
	}
	if (j != 1)
	{
		free_max(max);
		error("Error\nShould have 1 C\n");
	}
}

void	one_floor(char **max)
{
	char	*temp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (max[++i])
	{
		temp = ft_strtrim(max[i], " ");
		if (!ft_strncmp(temp, "F ", 2) && (temp[1] == ' ' || temp[1] == '\t'))
			j++;
		free(temp);
	}
	if (j != 1)
	{
		free_max(max);
		error("Error\nShould have 1 F!\n");
	}
}

void	many_colors(char **max)
{
	one_roof(max);
	one_floor(max);
}
