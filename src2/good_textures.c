/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   good_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 07:44:44 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/01/16 11:30:41 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	good_no(char **mat, char *str)
{
	char	**mat2;
	int		i;

	mat2 = ft_split(str, ' ');
	i = 0;
	while (mat2[i])
		i++;
	if (i != 2)
	{
		free(str);
		free_max(mat);
		free_max(mat2);
		error("Error\nNO ex: NO assets/NO.xpm\n");
	}
	free_max(mat2);
}

void	good_so(char **mat, char *str)
{
	char	**mat2;
	int		i;

	mat2 = ft_split(str, ' ');
	i = 0;
	while (mat2[i])
		i++;
	if (i != 2)
	{
		free(str);
		free_max(mat);
		free_max(mat2);
		error("Error\nSO ex: SO assets/SO.xpm\n");
	}
	free_max(mat2);
}

void	good_we(char **mat, char *str)
{
	char	**mat2;
	int		i;

	mat2 = ft_split(str, ' ');
	i = 0;
	while (mat2[i])
		i++;
	if (i != 2)
	{
		free(str);
		free_max(mat);
		free_max(mat2);
		error("Error\nWE ex: WE assets/WE.xpm\n");
	}
	free_max(mat2);
}

void	good_ea(char **mat, char *str)
{
	char	**mat2;
	int		i;

	mat2 = ft_split(str, ' ');
	i = 0;
	while (mat2[i])
		i++;
	if (i != 2)
	{
		free(str);
		free_max(mat);
		free_max(mat2);
		error("Error\nEA ex: EA assets/EA.xpm\n");
	}
	free_max(mat2);
}

void	good_textures(char **max)
{
	char	*temp;
	int		i;

	i = 0;
	while (i < 6)
	{
		temp = ft_strtrim(max[i], " ");
		if (!ft_strncmp(temp, "NO ", 3))
			good_no(max, temp);
		else if (!ft_strncmp(temp, "SO ", 3))
			good_so(max, temp);
		else if (!ft_strncmp(temp, "WE ", 3))
			good_we(max, temp);
		else if (!ft_strncmp(temp, "EA ", 3))
			good_ea(max, temp);
		free(temp);
		i++;
	}
}
