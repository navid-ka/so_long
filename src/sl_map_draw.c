/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <nkeyani-@student.42barcelona.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:58:14 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/15 09:50:13 by bifrost          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_draw_walls_and_path(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (g->map[++i])
	{
		while (g->map[i][j])
		{
			if (g->map[i][j] == '1')
				mlx_put_image_to_window(g->mlx, g->win, WALL, \
					j * 32, i * 32);
			if (g->map[i][j] == '0' || g->map[i][j] == 'P' ||
				g->map[i][j] == 'E' || g->map[i][j] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, PATH, \
					j * 32, i * 32);
			j++;
		}
		j = 0;
	}
}

void	sl_draw_entities(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P')
				mlx_put_image_to_window(g->mlx, g->win, PLAYER_R, \
					j * 32, i * 32);
			if (g->map[i][j] == 'C')
			{
				mlx_put_image_to_window(g->mlx, g->win, COIN, \
					j * 32, i * 32);
				g->coin++;
			}
			if (g->map[i][j] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, DOOR, \
					j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	sl_draw_finish(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	while (g->map[i])
	{
		j = 0;
		while (g->map[i][j])
		{
			mlx_put_image_to_window(g->mlx, g->win, WALL, \
					j * 32, i * 32);
			j++;
		}
		i++;
	}
}

void	sl_draw_map(t_game *g)
{
	sl_draw_walls_and_path(g);
	sl_draw_entities(g);
}
