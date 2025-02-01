/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:15:49 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/01 10:38:35 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_matrix(char **mt)
{
	while (*mt)
		printf("%s\n", *(mt++));
}

int	main(int ac, char **args)
{
	char	**cub;

	if (ac != 2)
		error("Error\n./exec_name map_path\n");
	cub = get_file(args[1]);
	validate_file(cub, args[1]);
	free_max(cub);
	win_init(args);
	return (0);
}
