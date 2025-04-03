/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speak_to_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:21:18 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/03 19:07:25 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*ft_hello(void *arg)
{
	t_philo					*philo;

	philo = (t_philo *)arg;
	printf("Hello, World ! I'm philo %d. It's %ld, we start %ld ms ago \n",
		philo->namber, get_time(), get_time() - philo->start_time_philo);
	return (NULL);
}

void	*good_night(void *arg)
{
	t_philo					*philo;
	long			sleep_length;

	philo = (t_philo *)arg;
	sleep_length = philo->data->time_to_sleep * 1000;
	
	printf("%ld : %i is sleeping\n",get_time() - philo->start_time_philo,
		philo->namber);
	usleep(sleep_length);
	return (NULL);
}

int	bon_appetit(void *arg)
{
	t_philo			*philo;
	long			meal_length;

	philo = (t_philo *)arg;
	meal_length = philo->data->time_to_eat * 1000;
	printf("%ld : %i is eating\n",get_time() - philo->start_time_philo,
		philo->namber);
	usleep(meal_length);
	philo->nb_meals++;
	//mettre a jour le gap_last_meal
	if (philo->nb_meals > 0 && philo->nb_meals == philo->data->nb_time_must_eat)
	{
		philo->full = true;
		printf("%ld : %i is full !\n",get_time() - philo->start_time_philo,
		philo->namber);
		return (FAILURE);
	}
	return (SUCCESS);
}