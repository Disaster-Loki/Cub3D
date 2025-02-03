/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:57:16 by sde-carv          #+#    #+#             */
/*   Updated: 2025/02/03 15:26:06 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_BONUS_H
# define FILE_BONUS_H

typedef struct s_size
{
	int	y;
	int	x;
}	t_size;

typedef struct s_cur
{
	int	y;
	int	x;
}	t_cur;

// many_textures.c
void	west(char **max);
void	east(char **max);
void	south(char **max);
void	north(char **max);
void	many_textures(char **max);

// many_colors.c
void	one_roof(char **max);
void	one_floor(char **max);
void	many_colors(char **max);

// char	*dell_spaces(char *str);
void	validate_elements(char **max);

// good_textures.c
void	good_textures(char **max);
void	good_we(char **mat, char *str);
void	good_ea(char **mat, char *str);
void	good_so(char **mat, char *str);
void	good_no(char **mat, char *str);

// textures_path.c
void	textures_path(char **max);
void	path_we(char *path, char **max);
void	path_ea(char *path, char **max);
void	path_so(char *path, char **max);
void	path_no(char *path, char **max);

// textures_extencion.c
void	textures_extencion(char **max);
void	extencion_we(char *str, char **max);
void	extencion_ea(char *str, char **max);
void	extencion_so(char *str, char **max);
void	extencion_no(char *str, char **max);

// Validate
int		open_file(char *file);
void	validate_file(char **max, char *str);

// forbiden_char.c
void	has_player(char **map, char **max);
void	forbiden_char(char **map, char **max);
void	treat_door(char **map, char **max);

// flood_fill.c
void	flood_fill(char **tab, t_size size, t_cur cur);

// help_sorround_by_1.c
void	last_line(char **mat, char **max);
void	middle_lines(char **map, char **max);
void	first_position(char **map, char **max);

// treat_map.c.c
void	treat_map(char **max, char *str);
void	map_new_line(char *str, char **max);
void	validate_map(char *str, char **max);
void	get_map_to_validate(char *file, int i);
void	help_new_line(char *file, int i, char **max);

// player_in_map.c
void	player_in_map(char **map, char **max);
void	only_n(char **map, int i, int j, char **max);
void	only_s(char **map, int i, int j, char **max);
void	only_w(char **map, int i, int j, char **max);
void	only_e(char **map, int i, int j, char **max);

// more_players.c
void	more_players(char **map, char **max);
void	more_n(char **map, int i, int j, char **max);
void	more_s(char **map, int i, int j, char **max);
void	more_w(char **map, int i, int j, char **max);
void	more_e(char **map, int i, int j, char **max);

// floor_roof.c
void	floor_roof(char **max);
char	**split_color(char *str);
void	big_nbr_color(char *floor, char *roof);
void	floor_roof_one_space(char *floor, char *roof);
void	floor_roof_weird_char(char *floor, char *roof, char **max);

// sorrounded_by_1.c
int		bigger_line(char **mat);
void	last_char(char **map, char **max);
void	inside_map(char **map, char **max);
void	walls_at_edges(char **map, char **max);
void	char_by_char(char **map2, char **map, char **max);

// changetabsbyspace_bonus.c
char	**change_tabs_by_space(char **map);
char	*dup_with_tab(char *str);
void	help_dup_with_tab(char *str, char *res);

// neighbor_door.c
void	neighbor_door(char **map, char **max);
void	help_neighbor_door(char **map, char **max, int i, int j);
void	error_position_door(char **map, char **max);

// validate_door_bonus.c
void	verify_door_path(char **map, char **max);
int		character2(char c);
int		bigger_line2(char **map);
int		has_door(char **map);
t_cur	found_player(char **map);

#endif
