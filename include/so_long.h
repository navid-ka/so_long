/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:22:31 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/14 11:41:43 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <libft.h>
# include <mlx.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdbool.h>
# include "defines.h"
# include "struct.h"
# include "errors.h"

// var init

void    sl_var_init(t_game *g);

//Image and drawing

void	sl_image_init(t_game *g);
void	sl_draw_entities(t_game *g);
void	sl_draw_map(t_game *g);
void	sl_draw_finish(t_game *g);

//map

void	sl_map_init(char **argv, t_game *g);
void	sl_game_dimension(t_game *g);

//map parse

int		sl_map_parse_rect(t_game *g);
int		sl_map_parse_walls(t_game *g);
int		sl_map_parse_char(t_game *g);
int		sl_map_parse_incorrect_chars(t_game *g);
void	sl_map_backtracking(t_game *g);


//Player movements

void	sl_player_mov_up(t_game *g);
void	sl_player_mov_down(t_game *g);
void	sl_player_mov_right(t_game *g);
void	sl_player_mov_left(t_game *g);
int     sl_game_read_keys(int key_pressed, t_game *g);
void	sl_game_finish(t_game *g, int row, int col);
int	    sl_game_read_keys_finish(int key_pressed, t_game *g);
void	sl_take_coin(t_game *g, int row, int col);
int     sl_move_is_valid(t_game *g, int row, int col);

// Error handling

void	sl_map_exit(char **map, int enum_msg, char *error_msg);
void	sl_free(char **map);
int		sl_game_destroy(t_game *g);
void	sl_exit_nw(void);

#endif