/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   julia_factor_rep.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.42.fr>            +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 17:54:15 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 20:55:41 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_jf_rep(t_mem *mem)
{
	int		x;
	int		y;
	t_color	color;

	color = ft_create_color(240, 0, 0, 0);
	x = (100.0 / mem->pt_x) * 50.0 + 550;
	y = (100.0 / mem->pt_y) * 30.0 + 865;
	ft_put_pixel(mem, color, x, y);
	ft_put_pixel(mem, color, x + 1, y + 1);
	ft_put_pixel(mem, color, x + 1, y - 1);
	ft_put_pixel(mem, color, x - 1, y + 1);
	ft_put_pixel(mem, color, x - 1, y - 1);
}

void	ft_draw_jf_axis(t_mem *mem)
{
	t_color		color;
	t_sqrvar	shape;
	int			x;
	int			y;

	x = (100.0 / mem->pt_x) * 50.0 + 550;
	y = (100.0 / mem->pt_y) * 30.0 + 865;
	color = ft_create_color(240, 240, 240, 0);
	shape = ft_create_rectangle(450, 865, 650, 865);
	ft_draw_rectangle(mem, color, shape);
	shape = ft_create_rectangle(550, 805, 550, 925);
	ft_draw_rectangle(mem, color, shape);
	shape = ft_create_rectangle(500, 863, 500, 867);
	ft_draw_rectangle(mem, color, shape);
	shape = ft_create_rectangle(600, 863, 600, 867);
	ft_draw_rectangle(mem, color, shape);
	shape = ft_create_rectangle(548, 835, 552, 835);
	ft_draw_rectangle(mem, color, shape);
	shape = ft_create_rectangle(548, 895, 552, 895);
	ft_draw_rectangle(mem, color, shape);
	shape = ft_create_rectangle(550, y, x, y);
	ft_draw_hptline(mem, color, shape);
	shape = ft_create_rectangle(x, 865, x, y);
	ft_draw_vptline(mem, color, shape);
	ft_jf_rep(mem);
}
