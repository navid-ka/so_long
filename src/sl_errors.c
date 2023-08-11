/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 10:49:18 by nkeyani-          #+#    #+#             */
/*   Updated: 2023/08/11 20:55:50 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	sl_free(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
	map = NULL;
}

void	sl_free_msg(char **map, char *error_msg)
{
	sl_free(map);
	ft_printf("%s", error_msg);
	exit(EXIT_FAILURE);
}

void	sl_map_exit(char **map, int enum_msg, char *error_msg)
{
	if (enum_msg == NOT_BER)
	{
		ft_printf("Error .ber extension not found");
		exit(EXIT_FAILURE);
	}
	if (enum_msg == NOT_RECT)
		sl_free_msg(map, error_msg);
	if (enum_msg == NOT_WALLS)
		sl_free_msg(map, error_msg);
	if (enum_msg == NOT_CHARS)
		sl_free_msg(map, error_msg);
	if (enum_msg == BAD_CHARS)
		sl_free_msg(map, error_msg);
	if (enum_msg == NO_PATH)
		sl_free_msg(map, error_msg);
	if (enum_msg == FINISH)
		sl_free_msg(map, error_msg);
}
