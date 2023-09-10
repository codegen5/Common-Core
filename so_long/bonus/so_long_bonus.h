/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msamilog <tahasamiloglu@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 09:46:13 by msamilog          #+#    #+#             */
/*   Updated: 2023/09/02 15:25:40 by msamilog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <time.h>
# include <unistd.h>

# define PL_R_XPM "./images/char_r.xpm"
# define PL_L_XPM "./images/char_l.xpm"
# define EX_XPM "./images/exit.xpm"
# define C_XPM "./images/coin.xpm"
# define WALL_XPM "./images/wall.xpm"
# define G_XPM "./images/ground.xpm"
# define FOE_XPM "./images/foe.xpm"


typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	void	*player_r;
	void	*player_l;
	void	*foe;
	void	*exit;
	void	*wall;
	void	*collectible;
	void	*background;
	int		map_x;
	int		map_y;
	char	**map;
	char	**c_map;
	int		collectible_count;
	int		collectible_count_copy;
	int		exit_valid;
	int		player_collected;
	int		p_right;
	int		p_count;
	int		e_count;
	int		f_count;
	int		player_x;
	int		player_y;
	int		foe_x;
	int		foe_y;
	int		exit_x;
	int		exit_y;
	int		player_step;
	int		map_y_control;
	char	*player_step_screen;
}			t_data;

void		image_to_screen(t_data *data);
int			handle_key_press(int keycode, t_data *data);
void		get_map(t_data *data, char *map_name, char *str);
char		*get_next_line(int fd);
void		step_counter(t_data *data);
int			ft_strlen(char *string);
char		*ft_strdup(char *s1);
char		**ft_split(const char *s, char c);
char		*ft_strjoin(char *s1, char *s2);
void		element_check(t_data *data);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			find_player(t_data *data, char find);
void		is_rectangular(t_data *data);
void		image_to_screen(t_data *data);
void		image_initialize(t_data *data);
void		ft_error(char *msg, t_data *data);
char		*ft_itoa(int n);
void		invalid_mapname(char *mapname, t_data *data);
void		wall_ok(t_data *data);
int			another_coin(t_data *data);
int			ft_close_window(t_data *data);
void		step_counter(t_data *data);
char		ft_coordinate(int x, int y, t_data *data);
void		ft_exit(char *msg);
void		ft_putstr(char *str);
int			game_update(t_data *data);

#endif
