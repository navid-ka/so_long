/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:58:14 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/10 15:46:59 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_draw_map(t_game *g)
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
					i * 32, j * 32);
			if (g->map[i][j] == '0' && g->map[i][j] == 'P')
				mlx_put_image_to_window(g->mlx, g->win, g->img[2].img_ptr, \
					i * 32, j * 32);
			if (g->map[i][j] == 'C')
				mlx_put_image_to_window(g->mlx, g->win, g->img[1].img_ptr, \
					i * 32, j * 32);
			if (g->map[i][j] == 'E')
				mlx_put_image_to_window(g->mlx, g->win, g->img[3].img_ptr, \
					i * 32, j * 32);
			j++;
		}
		j = 0;
	}
}

void	sl_draw_player(t_game *g)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (g->map[++i])
	{
		while (g->map[i][j])
		{
			if (g->map[i][j] == 'P')
				mlx_put_image_to_window(g->mlx, g->win, g->img[4].img_ptr, \
					i * 32, j * 32);
			j++;
		}
		j = 0;
	}
}
