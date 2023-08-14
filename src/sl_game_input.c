/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_game_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 23:22:39 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/14 13:03:50 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	sl_game_read_keys(int key_pressed, t_game *g)
{
	if (key_pressed == ESC)
		sl_game_destroy(g);
	if (key_pressed == ARROW_UP || key_pressed == W)
		sl_player_mov_up(g);
	else if (key_pressed == ARROW_LEFT || key_pressed == A)
		sl_player_mov_left(g);
	else if (key_pressed == ARROW_DOWN || key_pressed == S)
		sl_player_mov_down(g);
	else if (key_pressed == ARROW_RIGHT || key_pressed == D)
		sl_player_mov_right(g);
	return (0);
}
