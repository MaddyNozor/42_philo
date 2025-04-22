/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:21:18 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/22 11:51:07 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void bring_back_our_sticks(t_philo *philo)
{
	if (philo->number % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_fork);
		// printf("%ld %i put back the R%p fork\n",get_time() - philo->start_time_philo,
		// 		philo->number, philo->left_fork);	
		pthread_mutex_unlock(&philo->right_fork);
		// printf("%ld %i put back the L%p fork\n",get_time() - philo->start_time_philo,
		// 		philo->number, &philo->right_fork);
	}
	else if (philo->number % 2 != 0)
	{
		pthread_mutex_unlock(&philo->right_fork);
		// printf("%ld %i put back the L%p fork\n",get_time() - philo->start_time_philo,
		// 		philo->number, &philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
		// printf("%ld %i put back the R%p fork\n",get_time() - philo->start_time_philo,
		// 		philo->number, philo->left_fork);	
	}
}

int	good_night(void *arg)
{
	t_philo					*philo;
	long			sleep_length;

	philo = (t_philo *)arg;
	sleep_length = philo->data->time_to_sleep * 1000;
	
	printf("%ld %i is sleeping\n",get_time() - philo->start_time_philo,
		philo->number);
	usleep(sleep_length);
	return (SUCCESS);
}

int	bon_appetit(void *arg)
{
	t_philo			*philo;
	long			meal_length;

	philo = (t_philo *)arg;
	meal_length = philo->data->time_to_eat * 1000;
	printf("%ld %i is eating\n",get_time() - philo->start_time_philo,
		philo->number);
	philo->last_meal_time = get_time();
	usleep(meal_length);
	bring_back_our_sticks(philo);
	philo->nb_meals++;
	if (philo->nb_meals > 0 && philo->nb_meals == philo->data->nb_time_must_eat)
	{
		pthread_mutex_lock(philo->satiation_mtx);
		philo->full = true;
		pthread_mutex_unlock(philo->satiation_mtx);
		//printf("%ld %i is full !\n",get_time() - philo->start_time_philo,
		//	philo->number);
		//usleep(1);
		return (FAILURE);
	}
	
	return (SUCCESS);
}

int	deep_thought(void *arg)
{
	t_philo			*philo;
	
	philo = (t_philo *)arg;
	printf("%ld %i is thinking\n",get_time() - philo->start_time_philo,
		philo->number);
	if (philo->number % 2 != 0)
	{
		pthread_mutex_lock(philo->left_fork);
		printf("%ld %i has taken the L%p fork\n",get_time() - philo->start_time_philo,
			philo->number, &philo->right_fork);
		pthread_mutex_lock(&philo->right_fork);
		printf("%ld %i has taken the R%p fork\n",get_time() - philo->start_time_philo,
			philo->number, philo->left_fork);	
	}
	if (philo->number % 2 == 0)
	{
		usleep(1);
		pthread_mutex_lock(&philo->right_fork);
		printf("%ld %i has taken the RR%p fork\n",get_time() - philo->start_time_philo,
			philo->number, &philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		printf("%ld %i has taken the LL%p fork\n",get_time() - philo->start_time_philo,
			philo->number, philo->left_fork);	
	}
	return (SUCCESS);
}

