/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:03:50 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/22 11:47:45 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	death_has_come(t_data_table *data)
{
	int	i;

	while (!data->the_end)
	{
		i = 1;
		while (i <= data->nb_philo && !data->the_end)
		{
			if (get_time() - data->agora[i].last_meal_time > data->time_to_die)
			{
				printf("%ld %ld %i \n", get_time() - data->agora[i].last_meal_time, data->agora[i].last_meal_time, data->time_to_die);
				data->the_end = true;
				printf("%ld %i died ---------------------------\n", get_time() - data->start_time, data->agora[i].number);
				return (true);
			}
			i++;
		}
		usleep(data->time_to_die);
	}
	return (false);
}

//check si tous les philos ont mangé leur nombre max de repas
// return true ou false
bool no_more_pasta_needed(t_data_table *data)
{
	int i;
	bool	full;
	
	i = 1;
	full = false;
	while (i <= data->nb_philo)
	{
		printf("Philo %d full ? %d\n", i, data->agora[i].full);
		pthread_mutex_lock(data->agora[i].satiation_mtx);
		full = data->agora[i].full;
		pthread_mutex_unlock(data->agora[i].satiation_mtx);
		if (full == false)
			return false;
		i++;
	}
	data->the_end = true;
	return (true);
}

/*
typedef struct s_philo
{
	t_data_table	*data;
	t_mutex			right_fork;
	t_mutex			*left_fork;
	t_mutex			last_meal_mtx;
	t_thread		id_thread;
	long			last_meal_time;
	long			start_time_philo; // a voir
	long			time_to_eat;
	long			time_to_sleep;
	int				number; // name + number t'as capté ?
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
*/