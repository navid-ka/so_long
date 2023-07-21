/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:22:31 by bifrost           #+#    #+#             */
/*   Updated: 2023/07/21 14:02:38 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <libft.h>
# include <mlx.h>
# include <stdint.h>

typedef struct s_map
{
	uint16_t	x;
	uint16_t	y;
}	t_map;

typedef struct s_entity
{
	uint16_t	x;
	uint16_t	y;
	//struct		*s_map;
}	t_entity;


typedef struct s_player
{
	uint16_t	x;
	uint16_t	y;
	//struct		*s_map;
}	t_player;

// mlx main loop
void	solong_mlx_init();

//map
void	solong_map_load();
void	solong_map_create();
int		solong_map_destroy(void *ptr);


//player
void	solong_player_load();	
void	solong_player_create();	
void	solong_player_destroy();

//entity 
void	solong_entity_load();	
void	solong_entity_create();	
void	solong_entity_destroy();

#endif