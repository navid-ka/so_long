/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:21:56 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/08 12:57:09 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

int	sl_game_destroy(t_game *g)
{
	//mlx_destroy_window(g->mlx, g->mlx_win);
	free(g);
	exit(0);
}

/*void	sl_game_struct_init(t_game *g)
{
	g->mlx = mlx_init();
	g->win = mlx_new_window(g->mlx, W_W, W_H, TITLE);
	g->img;
	g->p;
	g->map;
	g->bg;
	g->asset;
	g->h;
	g->w;
	g->e;
	g->c;
	g->pl;
	g->h_w;
	g->w_w;
	g->col;
	g->row;
}*/

int	sl_game_read_keys(int key_pressed, t_game *g)
{
	if (key_pressed == ESC)
	{
		ft_printf("KEY PRESSED:		%d\n", ESC);
		sl_game_destroy(g);
	}
	write(1, "\n", 1);
	return (0);
}

void	sl_game_load_assets(t_game *g)
{
	g->h = 32;
	g->w = 32;
	g->w_w = W_W;
	g->h_w = W_H;
	g->p = mlx_xpm_file_to_image(g->mlx, "assets/player.xpm", &g->w, &g->h);
	printf("Player loaded in:		%p\n", g->p);
	g->bg = mlx_xpm_file_to_image(g->mlx, "assets/bg.xpm", &g->w_w, &g->h_w);
	printf("Background loaded in:		%p\n", g->bg);
}

void	sl_game_start(t_game *g)
{
	sl_game_load_assets(g);
	mlx_put_image_to_window(g->mlx, g->win, g->bg, 0, 0);
	mlx_put_image_to_window(g->mlx, g->win, g->p, \
					W_W / 2, W_H / 2);
	mlx_string_put(g->mlx, g->win, W_W / 2 - 10, W_H / 2 + 50, \
					0x00AACCFF, "Player");
	mlx_key_hook(g->win, sl_game_read_keys, g);
	mlx_hook(g->win, 17, 0, sl_game_destroy, g);
}

int	main(int argc, char **argv)
{
	t_game	*g;

	(void)argc;
	printf("LOADING\n");
	g = (t_game *)malloc(sizeof (t_game));

	//sl_game_start(g);
	sl_map_init(argv, g);
	//g->win = ;
	//sl_game_start(g);
	//sl_map_init(argv, g);
	//mlx_loop(g->mlx);
	//mlx_destroy(g->mlx);
	free(g);
	return (0);
}