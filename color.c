/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:45:35 by jhermon-          #+#    #+#             */
/*   Updated: 2021/12/22 11:31:45 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_sample.h"

// return a color
t_color	new_color(int r, int g, int b, int a)
{
	t_color	color;

	color.r	= (char)r;
	color.g = (char)g;
	color.b = (char)b;
	color.a = (char)a;
	return (color);
}

// turns the 4 1st char of pixel to the representing color
void	turn_pixel_to_color(char *pixel, t_color color)
{
	pixel[0] = color.b;
	pixel[1] = color.g;
	pixel[2] = color.r;
	pixel[3] = color.a;
}

// turns all pixels of image to color
void turn_img_to_color(t_image *image, t_color color)
{
	int	x;
	int	y;

	// loops that repeat for each pixel of the image as it was a 2D table
	y = 0;
	while (y < image->size.y)
	{
		x = 0;
		while (x < image->size.x)
		{
			//we apply the formula to get the pixel
			//in that x, y position of the pixels char array 
			turn_pixel_to_color(
					&image->pixels[x * 4 + image->line_size * y], color);
			x++;
		}
		y++;
	}
}
