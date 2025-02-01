/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:12:39 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/06 13:12:41 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	error(char *msg)
{
	ft_putstr_fd(msg, 1);
	exit(1);
}

void	error_str(char *msg, char *str)
{
	free(str);
	ft_putstr_fd(msg, 1);
	exit(1);
}
