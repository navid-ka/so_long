/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_image_loader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bifrost <nkeyani-@student.42barcelona.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:39:02 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/15 09:45:59 by bifrost          ###   ########.fr       */
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
	g->img[5].data = (int *)mlx_get_data_addr(g->img[5].img_ptr,
			&g->img[5].bpp, &g->img[5].size_l, &g->img[5].endian);
	g->img[6].data = (int *)mlx_get_data_addr(g->img[6].img_ptr,
			&g->img[6].bpp, &g->img[6].size_l, &g->img[6].endian);
}

void	sl_image_init(t_game *g)
{
	g->h = 32;
	g->w = 32;
	g->img = malloc(sizeof(t_img) * (7 + 1));
	WALL = mlx_xpm_file_to_image(g->mlx,
			"assets/wall.xpm", &g->w, &g->h);
	COIN = mlx_xpm_file_to_image(g->mlx,
			"assets/coin.xpm", &g->w, &g->h);
	PATH = mlx_xpm_file_to_image(g->mlx,
			"assets/path.xpm", &g->w, &g->h);
	DOOR = mlx_xpm_file_to_image(g->mlx,
			"assets/door.xpm", &g->w, &g->h);
	PLAYER_R = mlx_xpm_file_to_image(g->mlx,
			"assets/player.xpm", &g->w, &g->h);
	PLAYER_L = mlx_xpm_file_to_image(g->mlx,
			"assets/player_left.xpm", &g->w, &g->h);
	g->img[6].img_ptr = mlx_xpm_file_to_image(g->mlx,
			"assets/door_open.xpm", &g->w, &g->h);
	sl_image_data(g);
}
