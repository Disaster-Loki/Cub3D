/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 13:13:47 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/08 12:45:56 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	matrix_len(char **max)
{
	int	len;

	len = 0;
	while (max[len])
		len++;
	return (len);
}

void	free_max(char **max)
{
	int	len;

	len = -1;
	while (max[++len])
		free(max[len]);
	free(max);
}

int	max_strlen(char **mtx)
{
	int	i;
	int	max;

	i = -1;
	max = 0;
	while (mtx[++i])
	{
		if ((int)ft_strlen(mtx[i]) > max)
			max = ft_strlen(mtx[i]);
	}
	return (max);
}

void	val_img_path(t_game *game, t_img *img)
{
	(void)game;
	if (!img->no || !img->so || !img->we || !img->ea)
		error("Error - Error loading the image !!\n");
}
