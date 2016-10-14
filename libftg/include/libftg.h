/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: auverneu <auverneu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/03 15:41:49 by auverneu          #+#    #+#             */
/*   Updated: 2016/10/13 16:18:28 by auverneu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTG_H
# define LIBFTG_H

# include <mlx.h>
# include <string.h>

/*
** Structure replacing the mlx image structure
*/
typedef struct		s_mlx_img
{
	int				width;
	int				height;
	char			*buffer;
	float			vertexes[8];
	void			*next;
}					t_mlx_img;

/*
** Structure to store a point
*/
typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

/*
** Structure to store a segment
*/
typedef struct		s_seg
{
	t_point			p1;
	t_point			p2;
}					t_seg;

/*
** Structure to store a gradient
*/
typedef struct		s_grad
{
	unsigned int	color_p1;
	unsigned int	color_p2;
}					t_grad;

/*
** ANSI keycodes
*/
enum
{
	FT_KEY_ANSI_A = 0x00,
	FT_KEY_ANSI_S = 0x01,
	FT_KEY_ANSI_D = 0x02,
	FT_KEY_ANSI_F = 0x03,
	FT_KEY_ANSI_H = 0x04,
	FT_KEY_ANSI_G = 0x05,
	FT_KEY_ANSI_Z = 0x06,
	FT_KEY_ANSI_X = 0x07,
	FT_KEY_ANSI_C = 0x08,
	FT_KEY_ANSI_V = 0x09,
	FT_KEY_ANSI_B = 0x0B,
	FT_KEY_ANSI_Q = 0x0C,
	FT_KEY_ANSI_W = 0x0D,
	FT_KEY_ANSI_E = 0x0E,
	FT_KEY_ANSI_R = 0x0F,
	FT_KEY_ANSI_Y = 0x10,
	FT_KEY_ANSI_T = 0x11,
	FT_KEY_ANSI_1 = 0x12,
	FT_KEY_ANSI_2 = 0x13,
	FT_KEY_ANSI_3 = 0x14,
	FT_KEY_ANSI_4 = 0x15,
	FT_KEY_ANSI_6 = 0x16,
	FT_KEY_ANSI_5 = 0x17,
	FT_KEY_ANSI_EQU = 0x18,
	FT_KEY_ANSI_9 = 0x19,
	FT_KEY_ANSI_7 = 0x1A,
	FT_KEY_ANSI_MIN = 0x1B,
	FT_KEY_ANSI_8 = 0x1C,
	FT_KEY_ANSI_0 = 0x1D,
	FT_KEY_ANSI_RBRACK = 0x1E,
	FT_KEY_ANSI_O = 0x1F,
	FT_KEY_ANSI_U = 0x20,
	FT_KEY_ANSI_LBRACK = 0x21,
	FT_KEY_ANSI_I = 0x22,
	FT_KEY_ANSI_P = 0x23,
	FT_KEY_ANSI_L = 0x25,
	FT_KEY_ANSI_J = 0x26,
	FT_KEY_ANSI_QUOTE = 0x27,
	FT_KEY_ANSI_K = 0x28,
	FT_KEY_ANSI_SCOLON = 0x29,
	FT_KEY_ANSI_BSLASH = 0x2A,
	FT_KEY_ANSI_COMMA = 0x2B,
	FT_KEY_ANSI_SLASH = 0x2C,
	FT_KEY_ANSI_N = 0x2D,
	FT_KEY_ANSI_M = 0x2E,
	FT_KEY_ANSI_PERIOD = 0x2F,
	FT_KEY_ANSI_GRAVE = 0x32,
	FT_KEY_ANSI_KPDECIMAL = 0x41,
	FT_KEY_ANSI_KPMULT = 0x43,
	FT_KEY_ANSI_KPPLUS = 0x45,
	FT_KEY_ANSI_KPCLEAR = 0x47,
	FT_KEY_ANSI_KPDIV = 0x4B,
	FT_KEY_ANSI_KPENTER = 0x4C,
	FT_KEY_ANSI_KPMIN = 0x4E,
	FT_KEY_ANSI_KPEQU = 0x51,
	FT_KEY_ANSI_KP0 = 0x52,
	FT_KEY_ANSI_KP1 = 0x53,
	FT_KEY_ANSI_KP2 = 0x54,
	FT_KEY_ANSI_KP3 = 0x55,
	FT_KEY_ANSI_KP4 = 0x56,
	FT_KEY_ANSI_KP5 = 0x57,
	FT_KEY_ANSI_KP6 = 0x58,
	FT_KEY_ANSI_KP7 = 0x59,
	FT_KEY_ANSI_KP8 = 0x5B,
	FT_KEY_ANSI_KP9 = 0x5C
};

/*
** Standards Keycodes
*/
enum
{
	FT_KEY_RET = 0x24,
	FT_KEY_TAB = 0x30,
	FT_KEY_SP = 0x31,
	FT_KEY_DEL = 0x33,
	FT_KEY_ESC = 0x35,
	FT_KEY_COMMAND = 0x37,
	FT_KEY_SHIFT = 0x38,
	FT_KEY_CLOCK = 0x39,
	FT_KEY_OPT = 0x3A,
	FT_KEY_CTRL = 0x3B,
	FT_KEY_RSHIFT = 0x3C,
	FT_KEY_ROPT = 0x3D,
	FT_KEY_RCTRL = 0x3E,
	FT_KEY_FCT = 0x3F,
	FT_KEY_F17 = 0x40,
	FT_KEY_VUP = 0x48,
	FT_KEY_VDOWN = 0x49,
	FT_KEY_VMUTE = 0x4A,
	FT_KEY_F18 = 0x4F,
	FT_KEY_F19 = 0x50,
	FT_KEY_F20 = 0x5A,
	FT_KEY_F5 = 0x60,
	FT_KEY_F6 = 0x61,
	FT_KEY_F7 = 0x62,
	FT_KEY_F3 = 0x63,
	FT_KEY_F8 = 0x64,
	FT_KEY_F9 = 0x65,
	FT_KEY_F11 = 0x67,
	FT_KEY_F13 = 0x69,
	FT_KEY_F16 = 0x6A,
	FT_KEY_F14 = 0x6B,
	FT_KEY_F10 = 0x6D,
	FT_KEY_F12 = 0x6F,
	FT_KEY_F15 = 0x71,
	FT_KEY_HLP = 0x72,
	FT_KEY_HOME = 0x73,
	FT_KEY_PUP = 0x74,
	FT_KEY_FDEL = 0x75,
	FT_KEY_F4 = 0x76,
	FT_KEY_END = 0x77,
	FT_KEY_F2 = 0x78,
	FT_KEY_PDOWN = 0x79,
	FT_KEY_F1 = 0x7A,
	FT_KEY_LARROW = 0x7B,
	FT_KEY_RARROW = 0x7C,
	FT_KEY_DARROW = 0x7D,
	FT_KEY_UARROW = 0x7E
};

int					ft_pixel_put_img(void *img, t_point pt, unsigned int color);
int					ft_seg_put_img(void *img, t_seg seg, t_grad gradient);
int					ft_set_bg_img(void *img, unsigned int color);


unsigned int		ft_col_from_argb(unsigned char a, unsigned char r,
					unsigned char g, unsigned char b);
unsigned int		ft_get_col_grad(t_grad grad, int pos, int end);

t_point				ft_get_iso_pt(t_point pt, t_point tile, t_point offset);

t_seg				ft_get_iso_seg(t_seg seg, t_point tile, t_point offset);

#endif
