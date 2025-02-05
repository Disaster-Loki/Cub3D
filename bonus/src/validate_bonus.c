/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:38:09 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/02/05 14:14:52 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	floor_roof(char **max)
{
	char	*floor;
	char	*roof;

	floor = get_value(max, "F");
	roof = get_value(max, "C");
	roof_weird_char(floor, roof, max);
	floor_weird_char(floor, roof, max);
	many_colon(floor, roof, max);
	big_floor_nbr(floor, roof, max);
	big_roof_nbr(floor, roof, max);
	free(floor);
	free(roof);
}

void	validate_elements(char **max)
{
	char	*temp;
	int		i;

	i = 0;
	while (i < 6)
	{
		temp = ft_strtrim(max[i], " ");
		if (!ft_strncmp(temp, "NO ", 3) || !ft_strncmp(temp, "SO ", 3)
			|| !ft_strncmp(temp, "WE ", 3)
			|| !ft_strncmp(temp, "EA ", 3)
			|| !ft_strncmp(temp, "F ", 2)
			|| !ft_strncmp(temp, "C ", 2))
		{
			free(temp);
		}
		else
		{
			free(temp);
			free_max(max);
			error("Error\nMissing element or there is invalid element\n");
			exit(0);
		}
		i++;
	}
}

int	open_file(char *file)
{
	int		fd;
	int		len;
	char	*ext;

	ext = ".cub";
	len = (int) ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ext, 4) != 0)
		error("Error\nInvalid extension\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Error\nOpenning the file\n");
	return (fd);
}

void	validate_file(char **max, char *str)
{
	validate_elements(max);
	many_textures(max);
	good_textures(max);
	textures_extencion(max);
	textures_path(max);
	many_colors(max);
	floor_roof(max);
	treat_map(max, str);
}
