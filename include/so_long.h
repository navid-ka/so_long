/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:22:31 by bifrost           #+#    #+#             */
/*   Updated: 2023/07/31 12:48:07 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <libft.h>
# include <mlx.h>
# include <stdint.h>
# include <fcntl.h>
# include "defines.h"
# include "struct.h"

// mlx main loop
void	sl_mlx_init();

//map
void	sl_map_load();
void	sl_map_create();
int		sl_destroy(void *ptr);
void	sl_map_init(char **argv);


//player
void	sl_player_load();	
void	sl_player_create();	
void	solong_player_destroy();

//entity 
void	sl_entity_load();	
void	sl_entity_create();	
void	sl_entity_destroy();

#endif