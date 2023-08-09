/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_image_loader.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 18:39:02 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/09 18:43:38 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_image_init(t_game g*)
{
	int		height;
	int		width;

	game->img[0].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/wall.xpm", &width, &height);
	game->img[0].data = (int *)mlx_get_data_addr(game->img[0].img_ptr,
			&game->img[0].bpp, &game->img[0].size_l, &game->img[0].endian);
	game->img[1].img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/wall.xpm", &width, &height);
	game->img[1].data = (int *)mlx_get_data_addr(game->img[1].img_ptr,
			&game->img[1].bpp, &game->img[1].size_l, &game->img[1].endian);
}