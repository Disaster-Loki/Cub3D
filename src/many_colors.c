/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:27:32 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/01/25 10:28:11 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

char	**help_split_color(char **max, char *str)
{
	int	i;
	int	j;
	int	f;
	char	**res;

	i = 0;
	f = 0;
	while (max[++i])
	{
		j = -1;
		while (max[i][++j])
			str[f++] = max[i][j];
	}
	str[f] = '\0';
	res = ft_split(str, ',');
	free_max(max);
	free(str);
	return (res);
}

char	**split_color(char *str)
{
	char	**res;
	char	*str2;
	int	len;
	int	i;
	int	j;

	res = ft_split(str, ' ');
	i = 0;
	len = 0;
	while (res[++i])
	{
		j = 0;
		while (res[i][j])
			j++;
		len += j;
	}
	str2 = malloc(sizeof(char) * (len + 1));
	return (help_split_color(res, str2));
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
