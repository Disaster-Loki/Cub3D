/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:47:53 by sde-carv          #+#    #+#             */
/*   Updated: 2024/08/20 09:48:06 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/inc/libft.h"
# include "../minilibx-linux/mlx.h"

# define ESC 65307

typedef struct s_point
{
	int	x;
	int	y;
};

typedef struct s_img
{
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
	int		wid;
	int		hei;
}			t_img;

typedef struct s_game
{
	t_img	img;
	void	*mlx;
	void	*win;
}

void	error(char *msg);
char	**get_file(char *str);
int		open_file(char *file);
char	*read_map_content(int fd);
void	error_str(char *msg, char *str);

#endif
