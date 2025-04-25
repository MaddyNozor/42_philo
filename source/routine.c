/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:21:18 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/25 12:32:37 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	good_night(t_philo *philo)
{
	long	sleep_length;

	if (is_simulation_over(philo))
		return (FAILURE);
	sleep_length = philo->time_to_sleep * 1000;
	print_safe(philo, "is sleeping\n");
	usleep(sleep_length);
	return (SUCCESS);
}

int	bon_appetit(t_philo *philo)
{
	long	meal_length;

	meal_length = philo->time_to_eat * 1000;
	if (is_simulation_over(philo))
	{
		bring_back_our_forks(philo);
		return (FAILURE);
	}
	print_safe(philo, "is eating\n");
	pthread_mutex_lock(philo->last_meal_mtx);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(philo->last_meal_mtx);
	usleep(meal_length);
	bring_back_our_forks(philo);
	philo->nb_meals++;
	if (philo->nb_meals > 0 && philo->nb_meals == philo->nb_time_must_eat)
	{
		pthread_mutex_lock(philo->full_state_mtx);
		philo->full = true;
		pthread_mutex_unlock(philo->full_state_mtx);
		return (FAILURE);
	}
	return (SUCCESS);
}

bool	take_forks(t_philo *philo)
{
	if (is_simulation_over(philo))
		return (false);
	if (philo->number % 2 != 0)
	{
		pthread_mutex_lock(philo->left_fork);
		if (philo->nb_philo == 1 || is_simulation_over(philo))
			return (pthread_mutex_unlock(philo->left_fork), false);
		print_safe(philo, "has taken a fork\n");
		pthread_mutex_lock(&philo->right_fork);
		print_safe(philo, "has taken a fork\n");
	}
	else if (philo->number % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_fork);
		if (philo->nb_philo == 1 || is_simulation_over(philo))
			return (pthread_mutex_unlock(&philo->right_fork), false);
		print_safe(philo, "has taken a fork\n");
		pthread_mutex_lock(philo->left_fork);
		print_safe(philo, "has taken a fork\n");
	}
	return (true);
}

int	deep_thought(t_philo *philo)
{
	long	thinking_time;

	thinking_time = 0;
	if (is_simulation_over(philo))
		return (FAILURE);
	if (philo->nb_philo % 2 != 0
		&& philo->time_to_eat > philo->time_to_sleep)
		thinking_time = philo->time_to_eat - philo->time_to_sleep;
	print_safe(philo, "is thinking\n");
	if (philo->number % 2 != 0)
		ft_usleep(5 + thinking_time, philo);
	else
	{
		if (philo->first_turn)
		{
			philo->first_turn = false;
			ft_usleep((philo->time_to_eat), philo);
		}
	}
	if (!take_forks(philo))
		return (FAILURE);
	return (SUCCESS);
}

// int	deep_thought_odd(t_philo *philo)
// {
// 	if (is_simulation_over(philo))
// 		return (FAILURE);
// 	pthread_mutex_lock(philo->left_fork);
// 	if (is_simulation_over(philo))
// 	{
// 		pthread_mutex_unlock(philo->left_fork);
// 		return (FAILURE);
// 	}
// 	print_safe("%ld %i has taken a fork\n", get_time()
// 		- philo->start_time, philo->number);
// 	pthread_mutex_lock(&philo->right_fork);
// 	if (is_simulation_over(philo))
// 	{
// 		bring_back_our_forks(philo);
// 		return (FAILURE);
// 	}
// 	print_safe("%ld %i has taken a fork\n", get_time()
// 		- philo->start_time, philo->number);
// 	return (SUCCESS);
// }

// int	deep_thought_even(t_philo *philo)
// {
// 	usleep(10);
// 	if (is_simulation_over(philo))
// 		return (FAILURE);
// 	pthread_mutex_lock(&philo->right_fork);
// 	if (is_simulation_over(philo))
// 	{
// 		pthread_mutex_unlock(&philo->right_fork);
// 		return (FAILURE);
// 	}
// 	print_safe("%ld %i has taken a fork\n", get_time()
// 		- philo->start_time, philo->number);
// 	pthread_mutex_lock(philo->left_fork);
// 	if (is_simulation_over(philo))
// 	{
// 		bring_back_our_forks(philo);
// 		return (FAILURE);
// 	}
// 	print_safe("%ld %i has taken a fork\n", get_time()
// 		- philo->start_time, philo->number);
// 	return (SUCCESS);
// }

// int	deep_thought(t_philo *philo)
// {
// 	long	thinking_time;

// 	thinking_time = 0;
// 	if (is_simulation_over(philo))
// 		return (FAILURE);
// 	print_safe("%ld %i is thinking\n", get_time() - philo->start_time,
// 		philo->number);
// 	if (philo->number % 2 != 0)
// 	{
// 		if (deep_thought_odd(philo) == FAILURE)
// 			return (FAILURE);
// 	}
// 	if (philo->number % 2 == 0)
// 	{
// 		if (deep_thought_even(philo) == FAILURE)
// 			return (FAILURE);
// 	}
// 	return (SUCCESS);
// }
