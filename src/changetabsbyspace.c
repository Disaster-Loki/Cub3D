/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   changetabsbyspace_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptchipoc <ptchipoc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 09:05:58 by ptchipoc          #+#    #+#             */
/*   Updated: 2025/02/03 13:09:33 by ptchipoc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	help_dup_with_tab(char *str, char *res)
{
	int	i;
	int	j;
	int	f;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\t')
		{
			f = 0;
			while (f < 4)
			{
				res[j] = ' ';
				f++;
				j++;
			}
		}
		else
		{
			res[j++] = str[i];
		}
		i++;
	}
	res[j] = '\0';
}

char	*dup_with_tab(char *str)
{
	int		i;
	int		len;
	char	*res;

	i = 0;
	len = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			len += 4;
		else
			len += 1;
		i++;
	}
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	help_dup_with_tab(str, res);
	return (res);
}

char	**change_tabs_by_space(char **map)
{
	char	**new_map;
	int		i;

	i = 0;
	while (map[i])
		i++;
	new_map = malloc(sizeof(char *) * (i + 1));
	i = -1;
	while (map[++i])
	{
		new_map[i] = dup_with_tab(map[i]);
	}
	new_map[i] = NULL;
	return (new_map);
}
