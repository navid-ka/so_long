/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:22:31 by bifrost           #+#    #+#             */
/*   Updated: 2023/08/10 15:47:39 by nkeyani-         ###   ########.fr       */
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

// mlx main loop
void	sl_mlx_init();

//Image and drawing

void	sl_image_init(t_game *g);
void	sl_draw_player(t_game *g);
void	sl_draw_map(t_game *g);

//map

void	sl_map_init(char **argv, t_game *g);
void	sl_game_dimension(t_game *g);

//map parse

int		sl_map_parse_rect(t_game *g);
int		sl_map_parse_walls(t_game *g);
int		sl_map_parse_char(t_game *g);
int		sl_map_parse_incorrect_chars(t_game *g);
void	sl_map_backtracking(t_game *g);

// Error handling

void	sl_map_exit(char **map, int enum_msg, char *error_msg);
void	sl_free(char **map);

#endif