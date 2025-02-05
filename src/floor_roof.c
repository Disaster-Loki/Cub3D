/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_roof.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 22:33:35 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/02/05 14:10:08 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	big_floor_nbr(char *floor, char *roof, char **max)
{
	char	**res_floor;
	int		i;
	int		j;

	res_floor = split_color(floor);
	i = -1;
	while (res_floor[++i])
	{
		j = 0;
		while (res_floor[i][j])
			j++;
		if (j > 3 || ft_atoi(res_floor[i]) > 255 || ft_atoi(res_floor[i]) < 0)
		{
			free(floor);
			free(roof);
			free_max(res_floor);
			free_max(max);
			error("Error\nInvalid Number to floor\n");
		}
	}
	free_max(res_floor);
}

void	big_roof_nbr(char *floor, char *roof, char **max)
{
	char	**res_roof;
	int		i;
	int		j;

	res_roof = split_color(roof);
	i = -1;
	while (res_roof[++i])
	{
		j = 0;
		while (res_roof[i][j])
			j++;
		if (j > 3 || ft_atoi(res_roof[i]) > 255 || ft_atoi(res_roof[i]) < 0)
		{
			free(floor);
			free(roof);
			free_max(res_roof);
			free_max(max);
			error("Error\nInvalid Number to roof\n");
		}
	}
	free_max(res_roof);
}

void	many_colon(char *floor, char *roof, char **max)
{
	int	i;
	int	flag_floor;
	int	flag_roof;

	i = -1;
	flag_floor = 0;
	while (floor[++i])
	{
		if (floor[i] == ',')
			flag_floor++;
	}
	i = -1;
	flag_roof = 0;
	while (roof[++i])
	{
		if (roof[i] == ',')
			flag_roof++;
	}
	if (flag_floor != 2 || flag_roof != 2)
	{
		free(floor);
		free(roof);
		free_max(max);
		error("Error\nIs missing color\n");
	}
}

void	roof_weird_char(char *fl, char *rf, char **max)
{
	int	i;

	i = 0;
	while (rf[++i])
	{
		if (rf[i] == ',' || rf[i] == ' ' || ft_isdigit(rf[i]) || rf[i] == '-')
			continue ;
		else
		{
			free(fl);
			free(rf);
			free_max(max);
			error("Error\nInvalid element in roof\n");
		}
	}
}

void	floor_weird_char(char *fl, char *rf, char **max)
{
	int	i;

	i = 0;
	while (fl[++i])
	{
		if (fl[i] == ',' || fl[i] == ' ' || ft_isdigit(fl[i]) || fl[i] == '-')
			continue ;
		else
		{
			free(fl);
			free(rf);
			free_max(max);
			error("Error\nInvalid element in floor\n");
		}
	}
}
