/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:21:56 by bifrost           #+#    #+#             */
/*   Updated: 2023/07/24 17:39:30 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

int     solong_game_exit(t_game *g)
{
	if (g)
	{
		if (g->mlx_win)
			free(g);
		mlx_destroy_window(g->mlx, g->mlx_win);
	}
	exit(EXIT_SUCCESS);
}

int		solong_game_read_keys(t_game *g, int key_pressed)
{
	if (key_pressed == ESC)
		solong_game_exit(g);
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
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->player, WIN_WIDTH/2, WIN_HEIGHT/2);
	mlx_string_put(g->mlx, g->mlx_win, WIN_WIDTH/2 - 10, WIN_HEIGHT/2 + 35, 0x00FFFFFFF, "Player");
	mlx_hook(g->mlx_win, 17, 0, solong_game_exit, g);
	mlx_key_hook(g->mlx_win, solong_game_read_keys, g);
	mlx_loop(g->mlx);
	free(g);
	return (0);
}