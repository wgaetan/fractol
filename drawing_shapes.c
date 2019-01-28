/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   drawing_shapes.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 17:29:17 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/11 11:45:43 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "fractol.h"

t_sqrvar	ft_create_rectangle(int x0, int y0, int x1, int y1)
{
	t_sqrvar	rectangle;

	rectangle.x0 = x0;
	rectangle.x1 = x1;
	rectangle.y0 = y0;
	rectangle.y1 = y1;
	return (rectangle);
}

void		ft_verif_sqrvar(t_sqrvar *pt)
{
	int		i;

	if (pt->x0 > pt->x1)
	{
		i = pt->x0;
		pt->x0 = pt->x1;
		pt->x1 = i;
	}
	if (pt->y0 > pt->y1)
	{
		i = pt->y0;
		pt->y0 = pt->y1;
		pt->y1 = i;
	}
}

void		ft_draw_vptline(t_mem *mem, t_color color, t_sqrvar pt)
{
	int		i;
	int		j;

	ft_verif_sqrvar(&pt);
	i = pt.y0;
	j = pt.x0;
	while (i <= pt.y1)
	{
		if (i % 8 == 0)
		{
			ft_put_pixel(mem, color, j, i + 1);
			ft_put_pixel(mem, color, j, i);
		}
		i++;
	}
}

void		ft_draw_hptline(t_mem *mem, t_color color, t_sqrvar pt)
{
	int		i;
	int		j;

	ft_verif_sqrvar(&pt);
	i = pt.y0;
	j = pt.x0;
	while (j <= pt.x1)
	{
		if (j % 8 == 0)
		{
			ft_put_pixel(mem, color, j + 1, i);
			ft_put_pixel(mem, color, j, i);
		}
		j++;
	}
}

void		ft_draw_rectangle(t_mem *mem, t_color color, t_sqrvar pt)
{
	int		i;
	int		j;

	ft_verif_sqrvar(&pt);
	i = pt.y0;
	j = pt.x0;
	while (i <= pt.y1)
	{
		while (j <= pt.x1)
		{
			ft_put_pixel(mem, color, j, i);
			j++;
		}
		j = pt.x0;
		i++;
	}
}
