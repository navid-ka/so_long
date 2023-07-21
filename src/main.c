/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkeyani- < nkeyani-@student.42barcelona    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 23:21:56 by bifrost           #+#    #+#             */
/*   Updated: 2023/07/21 14:03:25 by nkeyani-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"


int	solong_map_destroy(void *ptr)
{
	mlx_destroy_window (ptr, ptr);
	exit(EXIT_SUCCESS);
}

int	main(void)
{
	void *init = mlx_init ();
	ft_printf("Soooo long");
	void *load = mlx_new_window(init, 800, 400, "So long");
	mlx_loop(init);
	mlx_clear_window(init, load);
	mlx_destroy_window(init, load);
	mlx_hook(init, 17, 1L<<0, &solong_map_destroy, &load);	

	return 0;
}