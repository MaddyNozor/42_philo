/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:29:11 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/24 22:03:07 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//--------------------- INCLUDES -----------------------------
# include <unistd.h> //
# include <stdlib.h> // malloc, free
# include <limits.h> // INTMAX
# include <stdbool.h> //booleens
# include <stdio.h> // printf 
# include <pthread.h> // toolbox for threads
# include <string.h> // memset
# include <sys/time.h> // what time is it please ?

//--------------------- DEFINES -----------------------------

# define FAILURE 1
# define SUCCESS 0
# define NO 1
# define YES 0

//--------------------- STRUCTURES -----------------------------

typedef pthread_mutex_t		t_mutex;
typedef pthread_t			t_thread;
typedef struct s_data_table	t_data_table;

typedef struct s_philo
{
	t_data_table	*data;
	t_mutex			right_fork;
	t_mutex			*left_fork;
	t_mutex			*last_meal_mtx;
	t_mutex			*nb_meals_mtx;
	t_mutex			*full_state_mtx;
	t_thread		id_thread;
	long			start_time;
	long			last_meal_time;
	long			time_to_eat;
	long			time_to_sleep;
	long			time_to_die;
	int				number;
	int				nb_meals;
	int				nb_time_must_eat;
	int				nb_philo;
	bool			first_turn;
	bool			full;
}				t_philo;

typedef struct s_data_table
{
	t_philo			*agora;
	t_mutex			sim_over_mtx;
	t_mutex			last_meal_mtx;
	t_mutex			nb_meals_mtx;
	t_mutex			full_state_mtx;
	t_mutex			print_mtx;
	long			start_time;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_must_eat;
	bool			sim_is_over;
}				t_data_table;

//--------------------- FONCTION -----------------------------

int		check_parsing(int ac, char **av);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);
int		ft_init_prog_data(int ac, char **av, t_data_table *data);
long	get_time(void);
bool	ft_is_whitespace(char c);
int		ft_error(char *str);
bool	is_negative(int nbr);
bool	is_bigger_than_intmax(long long_to_check);
int		ft_init_philo(t_data_table *data);
int		check_parsing(int ac, char **av);
int		ft_init_prog_data(int ac, char **av, t_data_table *data);
int		ft_init_philo(t_data_table *data);
int		ft_isdigit(int c);
bool	ft_usleep(long time, t_philo *philo);
int		good_night(t_philo *philo);
int		bon_appetit(t_philo *philo);
int		deep_thought(t_philo *philo);
int		death_has_come(t_data_table *data);
bool	no_more_pasta_needed(t_data_table *data);
void	bring_back_our_forks(t_philo *philo);
long	get_last_meal_time(t_philo *philo);
int		get_nb_meals(t_philo *philo);
bool	get_full_state(t_philo *philo);
bool	is_simulation_over(t_philo *philo);
void	ft_clean_exit(t_data_table *data);
void	print_safe(t_philo *philo, char *msg);

#endif

// 	static char	*time_to_die;
// 	static char	*time_to_eat;
// 	static char	*time_to_sleep;
// 	static char	*nb_time_must_eat;