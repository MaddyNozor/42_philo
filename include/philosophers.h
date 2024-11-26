/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:29:11 by mairivie          #+#    #+#             */
/*   Updated: 2024/11/26 16:40:09 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//--------------------- INCLUDES -----------------------------
# include "libft.h"
# include <limits.h>
# include <pthread.h> // toolbox for threads
# include <stdbool.h>
# include <string.h>
# include <stdio.h> // printf pour les tests
# include <stdlib.h>
# include <unistd.h> //

//--------------------- DEFINES -----------------------------

# define FAILURE 1
# define SUCCESS 0

//--------------------- STRUCTURES -----------------------------

typedef struct s_philo
{
	pthread_t	thread;
	int			namber;
}				t_philo;

typedef struct s_prog_data
{
	int			nb_philo;
	t_philo		*agora;
	int			time_to_die;
	int			time_to_eat;
	int			time_to_sleep;
	int			nb_time_must_eat;
}				t_prog_data;

//--------------------- FONCTION -----------------------------

int				check_parsing(int ac, char **av);
long			ft_atol(const char *str);
void			*ft_hello(void *arg);
int				ft_init_prog_data(int ac, char **av, t_prog_data *data);

#endif

// 	static char	*time_to_die;
// 	static char	*time_to_eat;
// 	static char	*time_to_sleep;
// 	static char	*nb_time_must_eat;