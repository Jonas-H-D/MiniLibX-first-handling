/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:07:14 by jhermon-          #+#    #+#             */
/*   Updated: 2021/12/22 11:35:46 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_sample.h"

// returns an image of width * height black pixels
t_image	ft_new_image(void *mlx_ptr, int width, int height)
{
	t_image	img;

	img.reference = mlx_new_image(mlx_ptr, width, height);
	img.size.x = width;
	img.size.y = height;
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);

	return (img);
}

// returns an image with the sprite found in path
t_image	ft_new_sprite(void *mlx_ptr, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx_ptr, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel, &img.line_size, &img.endian);

	return (img);
}
