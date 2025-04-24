/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:03:50 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/24 16:16:42 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	death_has_come(t_data_table *data)
{
	int	i;

	i = 1;
	while (i <= data->nb_philo && !data->sim_is_over)
	{
		if (get_time() - data->agora[i].last_meal_time > data->time_to_die)
		{
			pthread_mutex_lock(&data->sim_over_mtx);
			data->sim_is_over = true;
			pthread_mutex_unlock(&data->sim_over_mtx);
			printf("%ld %i died \n", get_time() - data->start_time,
				data->agora[i].number);
			return (true);
		}
		i++;
	}
	return (false);
}

//check si tous les philos ont mangé leur nombre max de repas
// return true ou false
bool	no_more_pasta_needed(t_data_table *data)
{
	int		i;
	bool	full;

	i = 1;
	full = false;
	while (i <= data->nb_philo)
	{
		pthread_mutex_lock(data->agora[i].full_state_mtx);
		full = data->agora[i].full;
		pthread_mutex_unlock(data->agora[i].full_state_mtx);
		if (full == false)
			return (false);
		i++;
	}
	pthread_mutex_lock(&data->sim_over_mtx);
	data->sim_is_over = true;
	pthread_mutex_unlock(&data->sim_over_mtx);
	return (true);
}

void	ft_clean_exit(t_data_table *data)
{
	int	i;

	i = 1;
	while (i <= data->nb_philo)
	{
		pthread_join(data->agora[i].id_thread, NULL);
		i++;
	}
	i = 1;
	while (i <= data->nb_philo)
	{
		pthread_mutex_destroy(&data->agora[i].right_fork);
		i++;
	}
	pthread_mutex_destroy(&data->last_meal_mtx);
	pthread_mutex_destroy(&data->nb_meals_mtx);
	pthread_mutex_destroy(&data->full_state_mtx);
	pthread_mutex_destroy(&data->sim_over_mtx);
	return ;
}
