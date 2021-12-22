/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:29:51 by jhermon-          #+#    #+#             */
/*   Updated: 2021/12/22 11:52:55 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_sample.h"
#include <stdio.h>

int	ft_input(int key, void *param)
{
	t_program	*program = (t_program *)param;

	// mlx function that clears the window
	mlx_clear_window(program->mlx, program->window.reference);
	// --------
	//  move in a direction based on the key
	if (key == 124)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 123)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 125)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 126)
		program->sprite_position.y -= program->sprite.size.y;
	// -------
	// change color based on key R, G, B
	else if (key == 15)
		turn_img_to_color(&program->sprite, new_color(255,0,0,0));
	else if (key == 5)
		turn_img_to_color(&program->sprite, new_color(0,255,0,0));
	else if (key ==11)
		turn_img_to_color(&program->sprite, new_color(0,0,255,0));

	//mlx function that puts an image in a window at a given position
	//position 0,0 is the upper left corner
	mlx_put_image_to_window(program->mlx, program->window.reference, program->sprite.reference, program->sprite_position.x, program->sprite_position.y);
	printf("key pressed -> %d\n", key);
	return (0);
}

int	ft_update(void *param)
{
	t_program	*program = (t_program *)param;
	// a static that saves how many frames have passed
	static int	frame;
	//add a frame and every x frames change the 
	//position by 1 pixel so it looks animated
	frame++;
	if (frame == ANIMATION_FRAMES)
		program->sprite_position.y +=1;
	// every x*2 frames go back to that pixel to 
	// loop the animation
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->sprite_position.y -= 1;
		frame = 0;
	}

	mlx_put_image_to_window(program->mlx, program->window.reference, program->sprite.reference, program->sprite_position.x, program->sprite_position.y);
	return (0);
}
