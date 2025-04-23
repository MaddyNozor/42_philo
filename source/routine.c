/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:21:18 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/23 15:35:40 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	good_night(t_philo *philo)
{
	long	sleep_length;

	if (is_simulation_over(philo))
		return (FAILURE);
	sleep_length = philo->data->time_to_sleep * 1000;
	printf("%ld %i is sleeping\n", get_time() - philo->data->start_time,
		philo->number);
	usleep(sleep_length);
	return (SUCCESS);
}

int	bon_appetit(t_philo *philo)
{
	long	meal_length;

	meal_length = philo->data->time_to_eat * 1000;
	if (is_simulation_over(philo))
	{
		bring_back_our_sticks(philo);
		return (FAILURE);
	}
	printf("%ld %i is eating\n", get_time() - philo->data->start_time,
		philo->number);
	philo->last_meal_time = get_time();
	usleep(meal_length);
	bring_back_our_sticks(philo);
	philo->nb_meals++;
	if (philo->nb_meals > 0 && philo->nb_meals == philo->data->nb_time_must_eat)
	{
		pthread_mutex_lock(&philo->full_state_mtx);
		philo->full = true;
		pthread_mutex_unlock(&philo->full_state_mtx);
		return (FAILURE);
	}
	return (SUCCESS);
}

int	deep_thought_odd(t_philo *philo)
{
	if (is_simulation_over(philo))
	{
		bring_back_our_sticks(philo);
		return (FAILURE);
	}
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %i has taken a fork\n", get_time()
		- philo->data->start_time, philo->number);
	if (is_simulation_over(philo))
	{
		bring_back_our_sticks(philo);
		return (FAILURE);
	}
	pthread_mutex_lock(&philo->right_fork);
	printf("%ld %i has taken a fork\n", get_time()
		- philo->data->start_time, philo->number);
	return (SUCCESS);
}

int	deep_thought_even(t_philo *philo)
{
	usleep(1);
	if (is_simulation_over(philo))
	{
		bring_back_our_sticks(philo);
		return (FAILURE);
	}
	pthread_mutex_lock(&philo->right_fork);
	printf("%ld %i has taken a fork\n", get_time()
		- philo->data->start_time, philo->number);
	if (is_simulation_over(philo))
	{
		bring_back_our_sticks(philo);
		return (FAILURE);
	}
	pthread_mutex_lock(philo->left_fork);
	printf("%ld %i has taken a fork\n", get_time()
		- philo->data->start_time, philo->number);
	return (SUCCESS);
}

int	deep_thought(t_philo *philo)
{
	if (is_simulation_over(philo))
		return (FAILURE);
	printf("%ld %i is thinking\n", get_time() - philo->data->start_time,
		philo->number);
	if (philo->number % 2 != 0)
	{
		if (deep_thought_odd(philo) == FAILURE)
			return (FAILURE);
	}
	if (philo->number % 2 == 0)
	{
		if (deep_thought_even(philo) == FAILURE)
			return (FAILURE);
	}
	return (SUCCESS);
}
