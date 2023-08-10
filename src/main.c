/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:21:56 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/10 12:50:41 by nkeyani-         ###   ########.fr       */
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

void	sl_game_dimension(t_game *g)
{
	int	i;

	i = 0;
	while (g->map[i])
		i++;
	g->w_w = i;
	g->h_w = ft_strlen(g->map[0]);
}

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
	g->h = 64;
	g->w = 64;
	g->p = mlx_xpm_file_to_image(g->mlx, "assets/player.xpm", &g->w, &g->h);
	printf("Player loaded in:		%p\n", g->p);
	g->bg = mlx_xpm_file_to_image(g->mlx, "assets/bg.xpm", &g->w_w, &g->h_w);
	printf("Background loaded in:		%p\n", g->bg);
}

void	sl_game_start(t_game *g)
{
	sl_game_load_assets(g);
	mlx_put_image_to_window(g->mlx, g->win, g->bg, 0, 0);
	//mlx_put_image_to_window(g->mlx, g->win, g->p, \
					//W_W / 2, W_H / 2);
	//mlx_string_put(g->mlx, g->win, W_W / 2 - 10, W_H / 2 + 50, \
					//0x00AACCFF, "Player");
	mlx_key_hook(g->win, sl_game_read_keys, g);
	mlx_hook(g->win, 17, 0, sl_game_destroy, g);
}

int	main(int argc, char **argv)
{
	t_game	*g;

	(void)argc;
	printf("LOADING\n");
	g = (t_game *)malloc(sizeof (t_game));

	sl_map_init(argv, g);
	g->mlx = mlx_init();
	sl_game_dimension(g);
	g->win = mlx_new_window(g->mlx, g->w_w * 64, g->h_w * 64, TITLE);
	sl_game_start(g);
	sl_image_init(g);
	sl_draw_map(g);
	mlx_loop(g->mlx);
	mlx_destroy(g->mlx);
	sl_free(g->map);
	free(g);
	return (0);
}