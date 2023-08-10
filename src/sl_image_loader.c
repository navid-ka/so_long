/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_image_loader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:39:02 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/10 19:01:40 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	sl_image_data(t_game *g)
{
	g->img[0].data = (int *)mlx_get_data_addr(g->img[0].img_ptr,
			&g->img[0].bpp, &g->img[0].size_l, &g->img[0].endian);
	g->img[1].data = (int *)mlx_get_data_addr(g->img[1].img_ptr,
			&g->img[1].bpp, &g->img[1].size_l, &g->img[1].endian);
	g->img[2].data = (int *)mlx_get_data_addr(g->img[2].img_ptr,
			&g->img[2].bpp, &g->img[2].size_l, &g->img[2].endian);
	g->img[3].data = (int *)mlx_get_data_addr(g->img[3].img_ptr,
			&g->img[3].bpp, &g->img[3].size_l, &g->img[3].endian);
	g->img[4].data = (int *)mlx_get_data_addr(g->img[4].img_ptr,
			&g->img[4].bpp, &g->img[4].size_l, &g->img[4].endian);
}

void	sl_image_init(t_game *g)
{
	g->h = 32;
	g->w = 32;
	g->img = malloc(sizeof(t_img) * (5 + 1));
	g->img[0].img_ptr = mlx_xpm_file_to_image(g->mlx,
			"assets/wall.xpm", &g->w, &g->h);
	g->img[1].img_ptr = mlx_xpm_file_to_image(g->mlx,
			"assets/coin.xpm", &g->w, &g->h);
	g->img[2].img_ptr = mlx_xpm_file_to_image(g->mlx,
			"assets/path.xpm", &g->w, &g->h);
	g->img[3].img_ptr = mlx_xpm_file_to_image(g->mlx,
			"assets/door.xpm", &g->w, &g->h);
	g->img[4].img_ptr = mlx_xpm_file_to_image(g->mlx,
			"assets/player.xpm", &g->w, &g->h);
	sl_image_data(g);
}
