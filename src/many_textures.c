/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   many_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:14:54 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/01/16 11:32:17 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	north(char **max)
{
	char	*temp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (max[++i])
	{
		temp = ft_strtrim(max[i], " ");
		if ((!ft_strncmp(temp, "NO ", 3)) && (temp[2] == ' '
				|| temp[2] == '\t'))
			j++;
		free(temp);
	}
	if (j != 1)
	{
		free_max(max);
		error("Error\nShould have 1 NO\n");
	}
}

void	south(char **max)
{
	char	*temp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (max[++i])
	{
		temp = ft_strtrim(max[i], " ");
		if (!ft_strncmp(temp, "SO ", 3) && (temp[2] == ' ' || temp[2] == '\t'))
			j++;
		free(temp);
	}
	if (j != 1)
	{
		free_max(max);
		error("Error\nShould have 1 SO\n");
	}
}

void	east(char **max)
{
	char	*temp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (max[++i])
	{
		temp = ft_strtrim(max[i], " ");
		if (!ft_strncmp(temp, "EA ", 3) && (temp[2] == ' ' || temp[2] == '\t'))
			j++;
		free(temp);
	}
	if (j != 1)
	{
		free_max(max);
		error("Error\nShould have 1 EA\n");
	}
}

void	west(char **max)
{
	char	*temp;
	int		i;
	int		j;

	i = -1;
	j = 0;
	while (max[++i])
	{
		temp = ft_strtrim(max[i], " ");
		if (!ft_strncmp(temp, "WE ", 3) && (temp[2] == ' ' || temp[2] == '\t'))
			j++;
		free(temp);
	}
	if (j != 1)
	{
		free_max(max);
		error("Error\nShould have 1 WE\n");
	}
}

void	many_textures(char **max)
{
	north(max);
	south(max);
	east(max);
	west(max);
}
