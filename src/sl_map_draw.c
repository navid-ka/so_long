/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:58:14 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/16 16:13:53 by nkeyani-         ###   ########.fr       */
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
				mlx_put_image_to_window(g->mlx, g->win, g->img[0].img_ptr, \
					j * 32, i * 32);
			if (g->map[i][j] == '0' || g->map[i][j] == 'P' ||
				g->map[i][j] == 'E' || g->map[i][j] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->img[2].img_ptr, \
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
				mlx_put_image_to_window(g->mlx, g->win, g->img[4].img_ptr, \
					j * 32, i * 32);
			if (g->map[i][j] == 'C')
			{
				mlx_put_image_to_window(g->mlx, g->win, g->img[1].img_ptr, \
					j * 32, i * 32);
				g->coin++;
			}
			if (g->map[i][j] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->img[3].img_ptr, \
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
			mlx_put_image_to_window(g->mlx, g->win, g->img[0].img_ptr, \
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
