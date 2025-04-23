/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:16:57 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/23 14:54:54 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	ft_init_prog_data(int ac, char **av, t_data_table *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->nb_time_must_eat = -1;
	data->sim_is_over = false;
	pthread_mutex_init(&data->sim_over_mtx, NULL);
	data->start_time = (long)get_time();
	if (ac == 6)
		data->nb_time_must_eat = ft_atoi(av[5]);
	return (SUCCESS);
}

static void	*ft_routine(void *arg)
{
	t_philo	*philo;
	bool	sim_is_over;

	philo = (t_philo *)arg;
	sim_is_over = is_simulation_over(philo);
	while (!sim_is_over)
	{
		if (deep_thought(philo) == FAILURE)
			break ;
		if (bon_appetit(philo) == FAILURE)
			break ;
		if (good_night(philo) == FAILURE)
			break ;
		sim_is_over = is_simulation_over(philo);
	}
	return (NULL);
}

void	ft_init_base_values_except_mutex(t_data_table *data, int i)
{
	data->agora[i].data = data;
	data->agora[i].last_meal_time = get_time();
	data->agora[i].full = false;
	data->agora[i].nb_meals = 0;
	data->agora[i].number = i;
}

int	ft_init_philo(t_data_table *data)
{
	int	i;

	i = 1;
	while (i <= data->nb_philo)
	{
		ft_init_base_values_except_mutex(data, i);
		pthread_mutex_init(&data->agora[i].right_fork, NULL);
		pthread_mutex_init(&data->agora[i].last_meal_mtx, NULL);
		pthread_mutex_init(&data->agora[i].full_state_mtx, NULL);
		pthread_mutex_init(&data->agora[i].nb_meals_mtx, NULL);
		if (i > 1)
			data->agora[i].left_fork = &data->agora[i - 1].right_fork;
		i++;
	}
	data->agora[1].left_fork = &data->agora[i - 1].right_fork;
	i = 1;
	while (i <= data->nb_philo)
	{
		pthread_create(&data->agora[i].id_thread, NULL, ft_routine,
			&data->agora[i]);
		i++;
	}
	return (SUCCESS);
}
