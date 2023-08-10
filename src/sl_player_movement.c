/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:16:43 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/10 17:30:15 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_player_movements(int key_pressed, t_game *g)
{
	if (key_pressed == ARROW_UP || key_pressed == W)
		g->map[g->p_row][g->p_col] = g->map[g->p_row][g->p_col - 1];
	else if (key_pressed == ARROW_LEFT || key_pressed == A)
		return ('A');
	else if (key_pressed == ARROW_DOWN || key_pressed == S)
		return ('S');
	else if (key_pressed == ARROW_RIGHT || key_pressed == D)
		return ('D');
	return ('0');
}
