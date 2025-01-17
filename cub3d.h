/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lissam <lissam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 08:03:12 by lissam            #+#    #+#             */
/*   Updated: 2024/11/11 13:25:23 by lissam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <mlx.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define SQUAR_SIZE 64
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define RADUIS 2
# define WIN_W 1280
# define WIN_H 800
# define TEX_H 17
# define TEX_W 17

typedef struct s_player
{
	double			i;
	double			j;
	double			rotationangle;
	double			movespeed;
	double			rotationspeed;
	int				raduis;
	int				to_walk;
	int				to_turn;
}					t_player;

typedef struct s_image_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				tex_heigth;
	int				tex_width;
}					t_image_data;

typedef struct s_to_draw
{
	double			wallheight;
	double			distanceprojplane;
	double			realdistance;
	double			distance;
	double			rayangle;
	int				col;
	double			start;
	int				wall_up_down;
}					t_data_to_draw;

typedef struct s_texture
{
	t_image_data	*no_texture;
	t_image_data	*so_texture;
	t_image_data	*we_texture;
	t_image_data	*ea_texture;
}					t_texture;

typedef struct s_data
{
	char			*identifier[6];
	char			***idf_data;
	char			**tmp_map;
	int				tmp_map_h;
	char			**map;
	int				map_h;
	int				map_w;
	int				f_color;
	int				c_color;
	char			*no_file;
	char			*so_file;
	char			*we_file;
	char			*ea_file;
	int				inter_is_vertical;
	float			inter_x;
	float			inter_y;
	int				texture_side;
	t_texture		*texture;
	void			*mlx;
	void			*win;
	t_image_data	*img;
	t_player		*player;
	double			fov;
}					t_data;

typedef struct s_raycastnorm
{
	bool			h_hit;
	bool			v_hit;
	double			x;
	double			y;
	double			h_wall_x;
	double			h_wall_y;
	double			v_wall_x;
	double			v_wall_y;
	double			h_step_x;
	double			h_step_y;
	double			v_step_x;
	double			v_step_y;
	double			distance_h;
	double			distance_v;
	double			first_x;
	double			first_y;
	double			next_x;
	double			next_y;
	double			rayangle;
}					t_raycast;

void				init_vars(t_raycast *vars);
double				normalizeray(double rayangle);
int					check_right(double rayangle);
int					check_down(double rayangle);
int					wall_hit(t_data *mydata, double x, double y);
double				distance(double x1, double y1, double x2, double y2);
void				horizontal_data_init(double x, double y, t_raycast *vars);
void				get_horiz_inter(t_data *mydata, double x, double y,
						t_raycast *vars);
void				vertical_data_init(double x, double y, t_raycast *vars);
void				get_vert_inter(t_data *mydata, double x, double y,
						t_raycast *vars);
void				calculate_distance(double x, double y, t_raycast *vars);
void				ft_putstr_fd(char *str);
void				cub3d(char **av);
void				check_map_file(char *map_file);
int					ft_strcmp(char *s1, char *s2);
size_t				ft_strlen(char *str);
char				*get_next_line(int fd);
char				*ft_strdup(char *src);
void				print_error(char *error_mssg);
char				**ft_split(char *str, char *charset);
int					ft_atoi(char *str);
int					ft_strlen2(char *str);
void				init_my_data(t_data *mydata);
void				init_tmp_map(t_data *mydata, int i);
void				check_map_file_content(char *map_file, t_data *mydata);
void				check_map_file(char *map_file);
void				check_identefiers(t_data *my_data);
void				checks(t_data *mydata);
void				identifiers_validation(t_data *mydata);
void				check_identifiers_types(t_data *mydata);
void				count_identifier_attr(t_data *mydata);
void				check_textures(t_data *mydata);
void				check_identifiers_dup(t_data *mydata);
int					is_color(char *str);
int					is_number(char *str);
void				check_textures_extension(t_data *mydata);
int					is_texture(char *str);
int					compare_identifiers(char *str);
void				check_colors(t_data *mydata);
void				check_end_color(t_data *mydata, char *str);
void				free_identefiers(t_data *my_data);
void				free_idf_data(t_data *mydata);
void				the_map(int fd, t_data *mydata, char *map_file);
void				free_tmp_map(t_data *mydata);
void				free_map(t_data *mydata);
void				ft_draw(t_data *mydata);
void				free_used_data(t_data *mydata);
void				init_player(t_player *player);
void				get_player(t_player *player, t_data *mydata);
int					close_w(t_data *mydata);
void				change_rotationangle(t_player *player, char p_char);
void				castrays(t_data *mydata, t_player *player);
void				my_mlx_pixel_put(t_image_data *data, int x, int y,
						int color);
int					wall_check(t_data *mydata, double x, double y);
void				draw3d(t_data *mydata, double distance, double rayangle,
						int col);
void				skip_identifiers(int fd);
void				fill(int fd, t_data *mydata);
void				fill_tmp_map(t_data *mydata, char *map_file);
int					have_forbidden_char(char c);
void				check_position_char(t_data *mydata);
void				check_characterrs(t_data *mydata);
void				map_error_separating(int countnewlines, int countlines,
						t_data *mydata);
void				check_separating(t_data *mydata);
void				check_line_up_down(t_data *mydata, int i, int j);
void				chack_is_valid_color(t_data *mydata, char **str, int *j);
int					ft_strlen3(char *str);
void				check_character_up_down(t_data *mydata, int i, int j);
void				make_map_square(t_data *mydata, int w, int h);
void				check_line_up_down(t_data *mydata, int i, int j);
void				check_arround(t_data *mydata, int i, int j);
void				chack_last_line(t_data *mydata, int *j);
void				check_walls(t_data *mydata, int i);
void				check_map_validating(t_data *mydata);
int					get_map_with(t_data *mydata);
void				fill_the_map(t_data *mydata, int s, int e);
void				get_the_map(t_data *mydata);
int					ft_rgb_to_int(int red, int green, int blue);
void				get_c_hex(t_data *mydata);
void				get_file_colors(t_data *mydata);
void				map_parsing(t_data *mydata);
void				the_map(int fd, t_data *mydata, char *map_file);
void				draw(t_image_data *img, t_data *mydata, t_player *player);
void				move_right(double *newx, double *newy, t_data *mydata);
void				move_left(double *newx, double *newy, t_data *mydata);
void				move_up(double *newx, double *newy, t_data *mydata);
void				move_down(double *newx, double *newy, t_data *mydata);
void				move_keys(int keycode, t_data *mydata);
void				move_rows(int keycode, t_data *mydata);
void				texture_allocat(t_texture **texture);
void				get_texture_img(t_data *data, t_texture *texture);
void				get_texture_data_addr(t_texture *texture);
void				texture_init(t_data *data);
int					key_press(int key, t_data *data);
int					key_release(int key, t_data *data);
int					render(t_data *mydata);
#endif