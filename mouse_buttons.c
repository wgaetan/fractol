/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   mouse_buttons.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 16:47:27 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 16:26:34 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_mouse_fract_selec(t_mem *mem, int x, int y)
{
	if (x >= 10 && x <= 200 && y >= 840 && y <= 860 && mem->menu_tgl == 1)
		mem->fract_selec = 0;
	if (x >= 10 && x <= 200 && y >= 880 && y <= 900 && mem->menu_tgl == 1)
		mem->fract_selec = 1;
	if (x >= 10 && x <= 200 && y >= 920 && y <= 940 && mem->menu_tgl == 1)
		mem->fract_selec = 2;
}

int			ft_mouse(int key, int x, int y, t_mem *mem)
{
	float	diffx;
	float	diffy;
	float	factx;
	float	facty;
	int		correct;

	diffx = (mem->x2 - mem->x1);
	diffy = (mem->y2 - mem->y1);
	factx = (float)x / mem->img_x;
	facty = (float)y / mem->img_y;
	if (key == 5 || key == 4)
	{
		correct = (key == 5) ? 1 : -1;
		mem->x1 += (diffx / mem->zoom) * factx * correct;
		mem->x2 -= (diffx / mem->zoom) * (1 - factx) * correct;
		mem->y1 += (diffy / mem->zoom) * facty * correct;
		mem->y2 -= (diffy / mem->zoom) * (1 - facty) * correct;
	}
	if (key == 2)
		mem->menu_tgl = (mem->menu_tgl == 1 ? 0 : 1);
	if (key == 1)
		ft_mouse_fract_selec(mem, x, y);
	mlx_destroy_image(mem->mlx_ptr, mem->img.ptr);
	ft_print_loop(mem);
	return (0);
}
