/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pasosa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 15:46:23 by pasosa-s          #+#    #+#             */
/*   Updated: 2019/08/01 17:28:44 by pasosa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include "../libft/libft.h"

# define WIDTH 1920
# define HEIGHT 1080

# define MENU_WIDTH 192
# define MENU_HEIGHT 54

# define ERR_USAGE "Usage: ./fdf <filename> [ case_size z_size ]"
# define ERR_MALLOC "Error when trying allocating mem"
# define ERR_LENGTH "Found wrong line length. Exiting."
# define ERR_EMPTY "No data found."

typedef struct	s_coord
{
	int		x;
	int		y;
}				t_coord;

typedef struct	s_lst
{
	int				z;
	t_coord			coord;
	int				color;
	struct s_lst	*next;
}				t_lst;

typedef struct	s_tab
{
	t_coord		coord;
	t_coord		zac;
}				t_tab;

typedef struct	s_map
{
	t_lst		*lst;
	t_coord		size;
}				t_map;

typedef struct	s_menu
{
	int			background;
	int			menu;
	int			color1;
	int			color2;
	int			color3;
	int			color4;
	int			color5;
	int			text1;
	int			text2;
	int			boo;
}				t_menu;

typedef struct	s_cam
{
	int			zoom;
	t_coord		start;
	t_coord		center;
	int			iso;
	float		z_mag;
	double		alpha;
	double		beta;
	double		gamma;
}				t_cam;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*data_addr;
	int			bpp;
	int			s_l;
	int			endian;
	t_tab		**tab;
	t_map		*map;
	t_cam		*cam;
	t_menu		*menu;
}				t_mlx;

t_map			*get_map(char *av, t_menu *menu);
t_menu			*get_menu();
int				open_file(char *av, t_coord *size, t_map *map, t_menu *menu);
int				get_next_line(const int fd, char **line);
void			split_to_list(t_map *map, char **a, t_coord *size,
				t_menu *menu);

t_cam			*get_cam(t_coord size);
t_mlx			*get_mlx(char *av, t_map *m, t_cam *camera, t_menu *menu);
void			draw(t_mlx *mlx, t_map *map, int index);
void			bresenham(t_mlx *mlx, t_tab a, t_tab b);
int				minimum(int	a, int b);

int				message(char *message, t_menu *menu, t_map *map);
void			end(char *message);
int				get_zoom(t_coord size);
int				gradient(t_coord cur, t_tab start, t_tab end, t_coord delta);

t_tab			**create_tab(t_mlx *mlx);
void			isometric(t_coord *coord, int z);

void			theme_dark(t_mlx *mlx, t_menu *menu);
void			theme_light(t_mlx *mlx, t_menu *menu);
void			change_color(t_tab *tab, t_menu *menu);

void			background(t_mlx *mlx);
void			text_menu_left(t_mlx *big_mlx);
void			text_menu_right(t_mlx *big_mlx);
int				key_press(int keycode, void *param);
int				mouse_press(int button, int x, int y, void *param);
void			reset_values(t_mlx *mlx);

void			rotate_x(int *y, int *z, double alpha);
void			rotate_y(int *x, int *z, double alpha);
void			rotate_z(int *x, int *y, double alpha);

void			free_mlx(t_mlx *mlx, t_coord size);
void			free_lst(t_lst *alst);

#endif
