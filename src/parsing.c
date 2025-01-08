/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 09:42:08 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/08 09:42:29 by sde-carv         ###   ########.fr       */
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

t_sett	parsing(char *str)
{
	t_sett	sett;
	char	**max;

	max = get_file(str);
	sett.c_floor = ft_strtrim(get_value(max, "F"), " ");
	sett.c_roof = ft_strtrim(get_value(max, "C"), " ");
	sett.no = ft_strtrim(get_value(max, "NO"), " ");
	sett.so = ft_strtrim(get_value(max, "SO"), " ");
	sett.we = ft_strtrim(get_value(max, "WE"), " ");
	sett.ea = ft_strtrim(get_value(max, "EA"), " ");
	printf("roof = %s\n", sett.c_roof);
	printf("floor = %s\n", sett.c_floor);
	printf("no = %s\n", sett.no);
	printf("so = %s\n", sett.so);
	printf("we = %s\n", sett.we);
	printf("ea = %s\n", sett.ea);
	return (sett);
}
