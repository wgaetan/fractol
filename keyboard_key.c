/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   keyboard_key.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/20 17:29:00 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 16:26:10 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

static void	ft_color_keys(t_mem *mem, int key)
{
	if (key == TOUCH_NUMPAD_1)
		mem->color.b -= 30;
	if (key == TOUCH_NUMPAD_2)
		mem->color.b += 30;
	if (key == TOUCH_NUMPAD_4)
		mem->color.g -= 30;
	if (key == TOUCH_NUMPAD_5)
		mem->color.g += 30;
	if (key == TOUCH_NUMPAD_7)
		mem->color.r -= 30;
	if (key == TOUCH_NUMPAD_8)
		mem->color.r += 30;
}

static void	ft_cross_keys(t_mem *mem, int key)
{
	float	diffx;
	float	diffy;

	diffx = (mem->x2 - mem->x1);
	diffy = (mem->y2 - mem->y1);
	if (key == TOUCH_RIGHT)
	{
		mem->x1 += 0.1 * diffx;
		mem->x2 += 0.1 * diffx;
	}
	if (key == TOUCH_LEFT)
	{
		mem->x1 -= 0.1 * diffx;
		mem->x2 -= 0.1 * diffx;
	}
	if (key == TOUCH_DOWN)
	{
		mem->y1 += 0.1 * diffy;
		mem->y2 += 0.1 * diffy;
	}
	if (key == TOUCH_UP)
	{
		mem->y1 -= 0.1 * diffy;
		mem->y2 -= 0.1 * diffy;
	}
}

int			ft_key(int key, t_mem *mem)
{
	if (key == TOUCH_ECHAP)
	{
		mlx_destroy_image(mem->mlx_ptr, mem->img.ptr);
		free(mem);
		exit(1);
	}
	if (key >= TOUCH_LEFT && key <= TOUCH_UP)
		ft_cross_keys(mem, key);
	if (key == TOUCH_NUMPAD_PLUS)
		mem->iter_max *= 2;
	if (key == TOUCH_NUMPAD_MINUS && mem->iter_max >= 2)
		mem->iter_max /= 2;
	if (key >= TOUCH_NUMPAD_1 && key <= TOUCH_NUMPAD_8)
		ft_color_keys(mem, key);
	if (key == TOUCH_D)
		mem->julia_dynam = mem->julia_dynam == 0 ? 1 : 0;
	if (key == TOUCH_S)
		mem->color_dynam = mem->color_dynam == 0 ? 1 : 0;
	mlx_destroy_image(mem->mlx_ptr, mem->img.ptr);
	ft_print_loop(mem);
	return (0);
}
