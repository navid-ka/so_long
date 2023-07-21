/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:21:56 by bifrost           #+#    #+#             */
/*   Updated: 2023/07/21 20:18:53 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


typedef struct	s_data {
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
#define WIDTH 1920
#define HEIGHT 1080

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for (size_t i = 0; i < 100; i++)
		my_mlx_pixel_put(&img, i, 100, 0x0000FF00);
	for (size_t j = 0; j < 100; j++)
		my_mlx_pixel_put(&img, j + 1, j, 0x00FF0000);
	for (size_t k = 200; k < WIDTH/2; k++)
		my_mlx_pixel_put(&img, WIDTH/2, k, 0x00FF0000);
	for (size_t l = 200; l < HEIGHT/2; l++)
		my_mlx_pixel_put(&img, l + HEIGHT/2, HEIGHT/2, 0x00FF0000);
	mlx_string_put(mlx, mlx_win, WIDTH/2, HEIGHT/2, 0x00FF0000, "SO LONG");
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}