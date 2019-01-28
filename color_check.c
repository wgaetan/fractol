/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   color_check.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/17 19:10:12 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 17:39:06 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_color	ft_create_color(int r, int g, int b, int t)
{
	t_color color;

	color.r = r;
	color.g = g;
	color.b = b;
	color.t = t;
	return (color);
}

void	ft_color_check(t_mem *mem)
{
	mem->color.b = mem->color.b < 0 ? 0 : mem->color.b;
	mem->color.b = mem->color.b > 255 ? 255 : mem->color.b;
	mem->color.g = mem->color.g < 0 ? 0 : mem->color.g;
	mem->color.g = mem->color.g > 255 ? 255 : mem->color.g;
	mem->color.r = mem->color.r < 0 ? 0 : mem->color.r;
	mem->color.r = mem->color.r > 255 ? 255 : mem->color.r;
	mem->color.t = mem->color.t < 0 ? 0 : mem->color.t;
	mem->color.t = mem->color.t > 255 ? 255 : mem->color.t;
}
