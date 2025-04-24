/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:21:18 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/24 17:17:44 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	bring_back_our_forks(t_philo *philo)
{
	if (philo->number % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(&philo->right_fork);
	}
	else if (philo->number % 2 != 0)
	{
		pthread_mutex_unlock(&philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
}

bool	ft_usleep(long time, t_philo *philo)
{
	long	start;

	start = get_time();
	while (get_time() - start < time)
	{
		if (is_simulation_over(philo))
			return (false);
		usleep(100);
	}
	return (true);
}

// int	deep_thought(t_philo *philo)
// {
// 	if (is_simulation_over(philo))
// 		return (FAILURE);
// 	printf("%ld %i is thinking\n", get_time() - philo->data->start_time,
// 		philo->number);
// 	if (philo->number % 2 != 0)
// 	{
// 		if (is_simulation_over(philo))
// 			return (FAILURE);
// 		pthread_mutex_lock(philo->left_fork);
// 		printf("%ld %i has taken a fork\n", get_time()
// 			- philo->data->start_time, philo->number);
// 		if (is_simulation_over(philo))
// 		{
// 			bring_back_our_forks(philo);
// 			return (FAILURE);
// 		}
// 		pthread_mutex_lock(&philo->right_fork);
// 		printf("%ld %i has taken a fork\n", get_time()
// 			- philo->data->start_time, philo->number);
// 	}
// 	if (philo->number % 2 == 0)
// 	{
// 		usleep(1);
// 		if (is_simulation_over(philo))
// 			return (FAILURE);
// 		pthread_mutex_lock(&philo->right_fork);
// 		printf("%ld %i has taken a fork\n", get_time()
// 			- philo->data->start_time, philo->number);
// 		if (is_simulation_over(philo))
// 		{
// 			bring_back_our_forks(philo);
// 			return (FAILURE);
// 		}
// 		pthread_mutex_lock(philo->left_fork);
// 		printf("%ld %i has taken a fork\n", get_time()
// 			- philo->data->start_time, philo->number);
// 	}
// 	return (SUCCESS);
// }