/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:15:49 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/06 13:15:53 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	print_matrix(char **mt)
{
	while (*mt)
		printf("%s\n", *(mt++));
}

int	main(int av, char **args)
{
	(void)av;
	print_matrix(get_file(args[1]));
	return (0);
}
