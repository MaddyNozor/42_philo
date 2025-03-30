/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:29:11 by mairivie          #+#    #+#             */
/*   Updated: 2025/03/29 10:51:14 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//--------------------- INCLUDES -----------------------------
# include "libft.h"
# include <limits.h> // INTMAX
# include <pthread.h> // toolbox for threads
# include <stdbool.h>
# include <stdio.h> // printf pour les tests
# include <stdlib.h> // malloc, free
# include <string.h>
# include <unistd.h>
# include <sys/time.h> //

//--------------------- DEFINES -----------------------------

# define FAILURE 1
# define SUCCESS 0

//--------------------- STRUCTURES -----------------------------

typedef	struct	s_chopstick
{
	pthread_mutex_t	mutex;
	int				number;	
}				t_chopstick;


typedef struct s_philo
{
	t_chopstick	*left_stick;
	t_chopstick *right_stick;
	pthread_t	thread;
	int			namber; // name + number t'as capté ?
	long		start_time_philo;
}				t_philo;

typedef struct s_prog_data
{
	t_philo		*agora;
	int			nb_philo;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_time_must_eat;
	long		start_time;
}				t_prog_data;

//--------------------- FONCTION -----------------------------

int				check_parsing(int ac, char **av);
long			ft_atol(const char *str);
void			*ft_hello(void *arg);
int				ft_init_prog_data(int ac, char **av, t_prog_data *data);
long			get_time(void);

#endif

// 	static char	*time_to_die;
// 	static char	*time_to_eat;
// 	static char	*time_to_sleep;
// 	static char	*nb_time_must_eat;