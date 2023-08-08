/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_draw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:58:14 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/08 18:31:16 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_draw_map(t_game *g)
{
	int	i;
	int	j;

	i = 0;
	
	while (g->map[i])
	{
		(g->map[0][0] && mlx_put_image_to_window(g->mlx, g->win, g->p, \
					W_W / 2, W_H / 2));
		(g->map[ft_strlen(g->map[i])][0] \
		&& mlx_put_image_to_window(g->mlx, g->win, g->p, W_W / 2, W_H / 2));
	}
}