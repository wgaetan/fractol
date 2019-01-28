/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_cursor.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 17:08:35 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 17:10:48 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

int		ft_mouse_motion(int x, int y, t_mem *mem)
{
	if (x > 0 && x <= 1000 && y > 0 && y <= 1000)
	{
		if (mem->julia_dynam == 1)
		{
			mem->pt_x = x - 500;
			mem->pt_y = y - 500;
			mlx_destroy_image(mem->mlx_ptr, mem->img.ptr);
			ft_print_loop(mem);
		}
		if (mem->color_dynam == 1)
		{
			mem->color.r = (x * 255) / 1000;
			mem->color.b = (y * 255) / 1000;
			mlx_destroy_image(mem->mlx_ptr, mem->img.ptr);
			ft_print_loop(mem);
		}
	}
	return (0);
}
