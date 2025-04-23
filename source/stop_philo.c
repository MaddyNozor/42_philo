/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stop_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:03:50 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/23 16:10:16 by mairivie         ###   ########.fr       */
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
			data->sim_is_over = true;
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
		pthread_mutex_lock(&data->agora[i].full_state_mtx);
		full = data->agora[i].full;
		pthread_mutex_unlock(&data->agora[i].full_state_mtx);
		if (full == false)
			return (false);
		i++;
	}
	data->sim_is_over = true;
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
	return ;
}
