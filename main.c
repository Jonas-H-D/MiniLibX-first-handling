/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 13:32:06 by jhermon-          #+#    #+#             */
/*   Updated: 2021/12/22 14:33:25 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_sample.h"

int	main()
{
	// struct with all the info i need to run the program
	
	t_program	program;

	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, 1980, 1080, "sample 42");
	// -------------
	// create a new image/sprite
	program.sprite = ft_new_sprite(program.mlx, "idle.xpm");
	program.sprite_position.x = 100;
	program.sprite_position.y = 100;
	mlx_put_image_to_window(program.mlx, program.window.reference, program.sprite.reference, program.sprite_position.x, program.sprite_position.y);

	// create a new tile
	
	program.tile = ft_new_sprite(program.mlx, "tree.xpm");
	program.tile_position.x = 0;
	program.tile_position.y = 0;
	mlx_put_image_to_window(program.mlx, program.window.reference, program.tile.reference, program.tile_position.x, program.tile_position.y);

	// -------------
	// hook the input() function to the key pressed event
	mlx_key_hook(program.window.reference, *ft_input, &program);
	// hook a function to the loop (it will be call each frame)
	mlx_loop_hook(program.mlx, *ft_update, &program);
	// -------------
	// mlx constant loop
	mlx_loop(program.mlx);
}
