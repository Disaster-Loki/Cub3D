/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sde-carv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:57:16 by sde-carv          #+#    #+#             */
/*   Updated: 2025/01/24 11:57:34 by sde-carv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

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
char	**split_color(char *str);

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

// help_sorround_by_1.c
void	last_line(char **mat, char **max);
void	middle_lines(char **map, char **max);

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

#endif