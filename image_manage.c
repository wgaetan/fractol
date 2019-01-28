/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   image_manage.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/06 15:27:19 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 17:50:21 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

void	ft_display(t_mem *mem, t_mvar var)
{
	int		t;

	t = (100.0 / var.a);
	if (var.err != 0)
	{
		var.color = ft_create_color(mem->color.r * t,
			mem->color.g * t, mem->color.b * t, mem->color.t);
		ft_put_pixel(mem, var.color, var.x, var.y);
	}
}

void	ft_create_img(t_mem *mem)
{
	mem->img.ptr = mlx_new_image(mem->mlx_ptr,
		(int)mem->img_x, (int)mem->img_y);
	mem->img.data = mlx_get_data_addr(mem->img.ptr, &mem->img.bpp,
		&mem->img.sizeline, &mem->img.endian);
}

void	ft_put_pixel(t_mem *mem, t_color color, int x, int y)
{
	unsigned char	a;
	int				bpp;

	bpp = mem->img.bpp / 8;
	a = 0;
	if ((x > 0 && x < mem->img_x) && (y > 0 && y < mem->img_y))
	{
		mem->img.data[(x * bpp) + (mem->img.sizeline * y)] = a + color.b;
		mem->img.data[(x * bpp) + (mem->img.sizeline * y) + 1] = a + color.g;
		mem->img.data[(x * bpp) + (mem->img.sizeline * y) + 2] = a + color.r;
		mem->img.data[(x * bpp) + (mem->img.sizeline * y) + 3] = a + color.t;
	}
}
