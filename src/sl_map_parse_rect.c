/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_parse_rect.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <nkeyani-@student.42barcelona.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 18:15:05 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/13 00:14:10 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	sl_map_parse_rect(t_game *g)
{
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(g->map[i]);
	i++;
	while (g->map[i])
	{
		if (len != ft_strlen(g->map[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	sl_map_count_rows_cols(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
		i++;
	g->row = i;
	g->col = ft_strlen(g->map[0]);
}

static int	sl_map_parse_walls_rows(t_game *g)
{
	int		i;

	i = 0;
	sl_map_count_rows_cols(g);
	while (g->map[0][i] == '1' )
	{
		if (g->map[0][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (g->map[g->row - 1][i])
	{
		if (g->map[g->row - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

static int	sl_map_parse_walls_cols(t_game *g)
{
	int		i;

	i = 0;
	sl_map_count_rows_cols(g);
	while (g->map[i])
	{
		if (g->map[i][0] != '1' && g->map[i][g->col - 1] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (g->map[i])
	{
		if (g->map[i][g->col - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	sl_map_parse_walls(t_game *g)
{
	int	i;

	i = 0;
	i += sl_map_parse_walls_rows(g);
	i += sl_map_parse_walls_cols(g);
	return (i);
}
