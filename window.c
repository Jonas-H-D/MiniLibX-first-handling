/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhermon- <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 16:07:56 by jhermon-          #+#    #+#             */
/*   Updated: 2021/12/22 11:36:00 by jhermon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_sample.h"
#include <stdlib.h>

int	ft_close ()
{
	exit(0);
}

t_window	ft_new_window(void	*mlx_ptr, int width, int height, char	*title)
{
	t_window	window;

	window.reference = mlx_new_window(mlx_ptr, width, height, title);
	window.size.x = width;
	window.size.y = height;
	mlx_hook(window.reference, 17, 0, ft_close, 0);

	return (window);
}


