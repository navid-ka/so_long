/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:21:56 by bifrost           #+#    #+#             */
/*   Updated: 2023/07/24 15:34:44 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

/*typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
*/
int	main(void)
{
	t_game	*g;
	
	printf("LOADING\n");
	g = malloc(sizeof (t_game));
	g->h = 32;
	g->w = 32;
	g->w_win = WIN_WIDTH;
	g->h_win = WIN_HEIGHT;
	g->mlx = mlx_init();
	printf("Game init in:			%p\n", g->mlx);
	g->mlx_win = mlx_new_window(g->mlx, WIN_WIDTH, WIN_HEIGHT, TITLE);
	g->player = mlx_xpm_file_to_image(g->mlx, "assets/player.xpm", &g->w, &g->h);
	printf("Player loaded in:		%p\n", g->player);
	g->bg = mlx_xpm_file_to_image(g->mlx, "assets/bg.xpm", &g->w_win, &g->h_win);
	printf("Map loaded in:			%p\n", g->bg);
	mlx_put_image_to_window(g->mlx, g->mlx_win, g->bg , 0, 0);
	mlx_put_image_to_window (g->mlx, g->mlx_win, g->player, WIN_WIDTH/2, WIN_HEIGHT/2);
	mlx_string_put(g->mlx, g->mlx_win, WIN_WIDTH/2 - 10, WIN_HEIGHT/2 + 35, 0x00FFFFFFF, "Player");
	int i = 0; 
	i += mlx_loop(g->mlx);
	printf("Steps in mlx:			%d\n", i);
	free(g);
	return (0);
}