/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_parse_char.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <nkeyani-@student.42barcelona.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 10:22:51 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/07 20:51:03 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static int	sl_map_parse_chars(t_game *g, char a)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (g->map[i])
	{
		if (ft_strchr(g->map[i], a))
			flag++;
		i++;
	}
	if (a == 'E' || a == 'P')
	{
		if (flag == 0 || flag > 1)
			return (0);
	}
	else if (a == 'C')
	{
		if (flag == 0)
			return (0);
	}
	return (1);
}

int	sl_map_parse_incorrect_chars(t_game *g)
{
	int		i;
	int		j;
	char	*valid_chars;

	i = 0;
	valid_chars = "10CEP";
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (ft_strchr(valid_chars, g->map[i][j]) == NULL)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	sl_map_parse_char(t_game *g)
{
	int	i;

	i = 0;
	i = sl_map_parse_chars(g, 'C');
	if (i == 0)
		return (0);
	i = sl_map_parse_chars(g, 'P');
	if (i == 0)
		return (0);
	i = sl_map_parse_chars(g, 'E');
	if (i == 0)
		return (0);
	return (i);
}
