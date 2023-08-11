/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_movement.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 16:16:43 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/11 14:34:41 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

/*int	sl_move_is_valid(t_game *g, int row, int col)
{
	if (g->map[row][col] == '1')
	{
		return (0);
	}
	return (1);
}
*/
void	sl_player_mov_up(t_game *g)
{
	//if (sl_move_is_valid(g, g->p_col, g->p_row - 1))
	//{ 
		char **map;
		int row;
		int col;
		row = g->p_row;
		col = g->p_col;
		map = g->map;
		ft_printf("INFO: Player position in mov	(%d,%d)\n", g->p_row, g->p_col);
		ft_printf("VALUES ACT: ROW=%d COL=%d VAL=%c\n",row,col,map[row][col]);
		ft_printf("VALUES NEXT: ROW=%d COL=%d VAL=%c\n",row - 1,col,map[row - 1][col]);
		g->map[((g->p_row) - 1)][(g->p_col)] = 'P';
		ft_printf("VALUES ACT: ROW=%d COL=%d VAL=%c\n",row - 1,col,map[row - 1][col]);
		g->map[g->p_row][g->p_col] = g->map[((g->p_row) - 1)][(g->p_col)];
		ft_printf("Player move %d\n", g->mov);
		g->mov = g->mov + 1;
		g->map[g->p_row + 1][g->p_col] = '0';
		ft_printf("VALUES ACT: ROW=%d COL=%d VAL=%c\n",row,col,map[row][col]);
		mlx_put_image_to_window(g->mlx, g->win, g->img[4].img_ptr, \
					g->p_col * 32, g->p_row - 1 * 32);
		mlx_put_image_to_window(g->mlx, g->win, g->img[2].img_ptr, \
					g->p_col * 32, g->p_row  * 32);
	//}
}

/*int	sl_player_movements(int key_pressed, t_game *g)
{
	g->mov = 0;
	if (key_pressed == ARROW_UP || key_pressed == W)
		sl_player_mov_up(g);
	else if (key_pressed == ARROW_LEFT || key_pressed == A)
		return ('A');
	else if (key_pressed == ARROW_DOWN || key_pressed == S)
		return ('S');
	else if (key_pressed == ARROW_RIGHT || key_pressed == D)
		return ('D');
	return (0);
}*/
