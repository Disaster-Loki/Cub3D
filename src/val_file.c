/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:13:41 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/06 13:13:43 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	open_file(char *file)
{
	int		fd;
	int		len;
	char	*ext;

	ext = ".cub";
	len = (int) ft_strlen(file);
	if (len < 4 || ft_strncmp(file + len - 4, ext, 4) != 0)
		error("Error - Invalid extension !!\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("Error - Openning the file !!\n");
	return (fd);
}
