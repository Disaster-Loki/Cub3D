/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:15:49 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/08 12:17:48 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d_bonus.h"

void	print_matrix(char **mt)
{
	while (*mt)
		printf("%s\n", *(mt++));
}

int	main(int av, char **args)
{
	char	**cub;

	if (av == 1)
		return (1);
	cub = get_file(args[1]);
	//validate_file(cub, args[1]);
	free_max(cub);
	win_init(args);
	return (0);
}
