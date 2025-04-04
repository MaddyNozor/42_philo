/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speak_to_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:21:18 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/04 17:35:36 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void bring_back_our_sticks(t_philo *philo)
{
	if (philo->namber % 2 == 0)
	{
		pthread_mutex_unlock(philo->left_stick);
		// printf("%ld %i put back the R%p fork\n",get_time() - philo->start_time_philo,
		// 		philo->namber, philo->left_stick);	
		pthread_mutex_unlock(&philo->right_stick);
		// printf("%ld %i put back the L%p fork\n",get_time() - philo->start_time_philo,
		// 		philo->namber, &philo->right_stick);
	}
	else if (philo->namber % 2 != 0)
	{
		pthread_mutex_unlock(&philo->right_stick);
		// printf("%ld %i put back the L%p fork\n",get_time() - philo->start_time_philo,
		// 		philo->namber, &philo->right_stick);
		pthread_mutex_unlock(philo->left_stick);
		// printf("%ld %i put back the R%p fork\n",get_time() - philo->start_time_philo,
		// 		philo->namber, philo->left_stick);	
	}
}

int	good_night(void *arg)
{
	t_philo					*philo;
	long			sleep_length;

	philo = (t_philo *)arg;
	sleep_length = philo->data->time_to_sleep * 1000;
	
	printf("%ld %i is sleeping\n",get_time() - philo->start_time_philo,
		philo->namber);
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
		philo->namber);
	usleep(meal_length);
	bring_back_our_sticks(philo);
	philo->nb_meals++;
	//mettre a jour le gap_last_meal
	if (philo->nb_meals > 0 && philo->nb_meals == philo->data->nb_time_must_eat)
	{
		philo->full = true;
		printf("%ld %i is full !\n",get_time() - philo->start_time_philo,
		philo->namber);
		return (FAILURE);
	}
	
	return (SUCCESS);
}

int	deep_thought(void *arg)
{
	t_philo			*philo;
	
	philo = (t_philo *)arg;
	printf("%ld %i is thinking\n",get_time() - philo->start_time_philo,
		philo->namber);
	if (philo->namber % 2 != 0)
	{
		pthread_mutex_lock(philo->left_stick);
		printf("%ld %i has taken the L%p fork\n",get_time() - philo->start_time_philo,
			philo->namber, &philo->right_stick);
		pthread_mutex_lock(&philo->right_stick);
		printf("%ld %i has taken the R%p fork\n",get_time() - philo->start_time_philo,
			philo->namber, philo->left_stick);	
	}
	if (philo->namber % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_stick);
		printf("%ld %i has taken the RR%p fork\n",get_time() - philo->start_time_philo,
			philo->namber, &philo->right_stick);
		pthread_mutex_lock(philo->left_stick);
		printf("%ld %i has taken the LL%p fork\n",get_time() - philo->start_time_philo,
			philo->namber, philo->left_stick);	
	}
	return (SUCCESS);
}
