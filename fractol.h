/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fractol.h                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: wgaetan <wgaetan@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/15 15:16:45 by wgaetan      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/12 16:26:54 by wgaetan     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <time.h>
# include <stdio.h>

typedef struct		s_color
{
	int				r;
	int				g;
	int				b;
	int				t;
}					t_color;

typedef struct		s_img
{
	void			*ptr;
	char			*data;
	int				sizeline;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_complex
{
	float	r;
	float	i;
}					t_complex;

typedef struct		s_sqrvar
{
	int		x0;
	int		y0;
	int		x1;
	int		y1;
}					t_sqrvar;

typedef struct		s_mvar
{
	float		x;
	float		y;
	int			a;
	float		r;
	float		i;
	int			lim;
	int			err;
	t_complex	c;
	t_complex	z;
	t_color		color;
}					t_mvar;

typedef struct		s_mem
{
	t_img	img;
	void	*win_ptr;
	void	*mlx_ptr;
	float	x1;
	float	x2;
	float	y1;
	float	y2;
	float	zoom;
	int		iter_max;
	float	img_x;
	float	img_y;
	float	x_offset;
	float	y_offset;
	float	x_inflim;
	float	x_suplim;
	float	y_inflim;
	float	y_suplim;
	int		menu_tgl;
	int		fract_selec;
	t_color	color;
	int		pt_x;
	int		pt_y;
	int		julia_dynam;
	int		color_dynam;
	int		jf_val;
	t_mvar	mvar;
}					t_mem;

# define LINE_SIZE_ERR 1
# define WRONG_ARGS 2
# define FDFMEM_MALLOC_ERR 3
# define INIT_ERR 4
# define WRONG_FILE 5
# define TOUCH_1 18
# define TOUCH_2 19
# define TOUCH_3 20
# define TOUCH_4 21
# define TOUCH_5 23
# define TOUCH_6 22
# define TOUCH_7 26
# define TOUCH_8 28
# define TOUCH_9 25
# define TOUCH_0 29
# define TOUCH_Q 12
# define TOUCH_W 13
# define TOUCH_E 14
# define TOUCH_R 15
# define TOUCH_T 17
# define TOUCH_Y 16
# define TOUCH_A 0
# define TOUCH_S 1
# define TOUCH_D 2
# define TOUCH_F 3
# define TOUCH_G 5
# define TOUCH_Z 6
# define TOUCH_X 7
# define TOUCH_C 8
# define TOUCH_V 9
# define TOUCH_B 11
# define TOUCH_ECHAP 53
# define TOUCH_ENTER 36
# define TOUCH_LEFT 123
# define TOUCH_RIGHT 124
# define TOUCH_DOWN 125
# define TOUCH_UP 126
# define TOUCH_NUMPAD_0 82
# define TOUCH_NUMPAD_1 83
# define TOUCH_NUMPAD_2 84
# define TOUCH_NUMPAD_3 85
# define TOUCH_NUMPAD_4 86
# define TOUCH_NUMPAD_5 87
# define TOUCH_NUMPAD_6 88
# define TOUCH_NUMPAD_7 89
# define TOUCH_NUMPAD_8 91
# define TOUCH_NUMPAD_9 92
# define TOUCH_NUMPAD_POINT 65
# define TOUCH_NUMPAD_ENTER 76
# define TOUCH_NUMPAD_PLUS 69
# define TOUCH_NUMPAD_MINUS 78
# define TOUCH_NUMPAD_TIMES 67
# define TOUCH_NUMPAD_DIVIDE 75
# define TOUCH_NUMPAD_NUM 71
# define TOUCH_NUMPAD_INSERT 114
# define TOUCH_NUMPAD_END 119
# define TOUCH_NUMPAD_DELL 117
# define TOUCH_NUMPAD_PAGEUP 116
# define TOUCH_NUMPAD_PAGEDOWN 121
# define TOUCH_NUMPAD_HOME 115

void				ft_create_img(t_mem *mem);
void				ft_put_pixel(t_mem *mem, t_color color, int x, int y);
void				ft_mandelbrot(t_mem *mem);
void				ft_display(t_mem *mem, t_mvar var);
void				ft_display_info_back(t_mem *mem);
void				ft_display_info_text(t_mem *mem);
void				ft_burningship(t_mem *mem);
int					ft_mouse_motion(int x, int y, t_mem *mem);
void				ft_julia(t_mem *mem);
void				ft_color_check(t_mem *mem);
t_sqrvar			ft_create_rectangle(int x0, int y0, int x1, int y1);
t_color				ft_create_color(int r, int g, int b, int t);
void				ft_draw_rectangle(t_mem *mem, t_color color, t_sqrvar pt);
void				ft_draw_jf_axis(t_mem *mem);
void				ft_draw_hptline(t_mem *mem, t_color color, t_sqrvar pt);
void				ft_draw_vptline(t_mem *mem, t_color color, t_sqrvar pt);
int					ft_mouse(int key, int x, int y, t_mem *mem);
int					ft_mouse_motion(int x, int y, t_mem *mem);
int					ft_key(int key, t_mem *mem);
void				ft_print_loop(t_mem *mem);
void				ft_disp_color_infos(t_mem *mem);
#endif
