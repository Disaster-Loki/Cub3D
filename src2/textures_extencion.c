/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_extencion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 10:40:25 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/01/16 11:34:36 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	extencion_no(char *str, char **max)
{
	char	temp[5];
	int		i;
	int		j;

	i = 0;
	while (str[i])
		i++;
	i -= 4;
	j = 0;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	if (ft_strncmp(temp, ".xpm", 4))
	{
		free(str);
		free_max(max);
		error("Error\nInvalid extencion for North\n");
	}
}

void	extencion_so(char *str, char **max)
{
	char	temp[5];
	int		i;
	int		j;

	i = 0;
	while (str[i])
		i++;
	i -= 4;
	j = 0;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	if (ft_strncmp(temp, ".xpm", 4))
	{
		free(str);
		free_max(max);
		error("Error\nInvalid extencion for South\n");
	}
}

void	extencion_we(char *str, char **max)
{
	char	temp[5];
	int		i;
	int		j;

	i = 0;
	while (str[i])
		i++;
	i -= 4;
	j = 0;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	if (ft_strncmp(temp, ".xpm", 4))
	{
		free(str);
		free_max(max);
		error("Error\nInvalid extencion for West\n");
	}
}

void	extencion_ea(char *str, char **max)
{
	char	temp[5];
	int		i;
	int		j;

	i = 0;
	while (str[i])
		i++;
	i -= 4;
	j = 0;
	while (str[i])
		temp[j++] = str[i++];
	temp[j] = '\0';
	if (ft_strncmp(temp, ".xpm", 4))
	{
		free(str);
		free_max(max);
		error("Error\nInvalid extencion for East\n");
	}
}

void	textures_extencion(char **max)
{
	char	*temp;
	int		i;

	i = 0;
	while (i < 6)
	{
		temp = ft_strtrim(max[i], " ");
		if (!ft_strncmp(temp, "NO ", 3))
			extencion_no(temp, max);
		else if (!ft_strncmp(temp, "SO ", 3))
			extencion_so(temp, max);
		else if (!ft_strncmp(temp, "WE ", 3))
			extencion_we(temp, max);
		else if (!ft_strncmp(temp, "EA ", 3))
			extencion_ea(temp, max);
		free(temp);
		i++;
	}
}
