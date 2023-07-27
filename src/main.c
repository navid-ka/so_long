/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:21:56 by bifrost           #+#    #+#             */
/*   Updated: 2023/07/27 11:22:35 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

int	solong_game_destroy(t_game *g)
{
	//mlx_destroy_window(g->mlx, g->mlx_win);
	free(g);
	exit(0);
}

int	solong_game_read_keys(int key_pressed, t_game *g)
{
	if (key_pressed == ESC)
	{
		printf("KEY PRESSED:		%d\n", ESC);
		solong_game_destroy(g);
	}
	write(1, "\n", 1);
	return (0);
}

int	main(void)
{
	t_game	*g;
	t_game	player;
	t_game	bg;

	printf("LOADING\n");
	g = malloc(sizeof (t_game));
	g->h = 32;
	g->w = 32;
	g->w_win = WIN_WIDTH;
	g->h_win = WIN_HEIGHT;
	player.asset = "assets/player.xpm";
	bg.asset = "assets/bg.xpm";
	g->mlx = mlx_init();
	printf("Game init in:			%p\n", g->mlx);
	g->mlx_win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	g->player = mlx_xpm_file_to_image(g->mlx, player.asset, &g->w, &g->h);
	printf("Player loaded in:		%p\n", g->player);
	g->bg = mlx_xpm_file_to_image(g->mlx, bg.asset, &g->w_win, &g->h_win);
	printf("Map loaded in:			%p\n", g->bg);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->bg , 0, 0);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->player, \
			WIN_WIDTH/2, WIN_HEIGHT/2);
	mlx_string_put(g->mlx, g->mlx_win, WIN_WIDTH/2 - 10, \
				WIN_HEIGHT/2 + 50, 0x00AACCFF, "Player");
	mlx_key_hook(g->mlx_win, solong_game_read_keys, g);
	mlx_hook(g->mlx_win, 17, 0, solong_game_destroy, g);
	mlx_loop(g->mlx);
	mlx_destroy(g->mlx);
	free(g);
	return (0);
}