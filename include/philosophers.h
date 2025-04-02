/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:29:11 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/01 17:48:38 by mairivie         ###   ########.fr       */
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
	t_mutex			right_stick;
	t_mutex			*left_stick;
	t_thread		id_thread;
	long			gap_last_meal;
	long			start_time_philo; // a voir
	int				namber; // name + number t'as capté ?
	int				nb_meals;
	bool			full;
}				t_philo;

typedef struct s_data_table
{
	t_philo			*agora;
	long			start_time;
	int				nb_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_time_must_eat;
	bool			the_end; // this is the end, my friend
}				t_data_table;

//--------------------- FONCTION -----------------------------

int				check_parsing(int ac, char **av);
long			ft_atol(const char *str);
int				ft_atoi(const char *str);
void			*ft_hello(void *arg);
int				ft_init_prog_data(int ac, char **av, t_data_table *data);
long			get_time(void);
bool			ft_is_whitespace(char c);
int				ft_error(char *str);
bool			is_negative(int nbr);
bool			is_bigger_than_intmax(long long_to_check);
int				ft_init_philo(t_data_table *data);
int	check_parsing(int ac, char **av);
int	ft_init_prog_data(int ac, char **av, t_data_table *data);
int	ft_init_philo(t_data_table *data);
int	ft_isdigit(int c);


#endif

// 	static char	*time_to_die;
// 	static char	*time_to_eat;
// 	static char	*time_to_sleep;
// 	static char	*nb_time_must_eat;