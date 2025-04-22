/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:16:57 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/22 21:49:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

 long	get_last_meal_time(t_philo *philo)
 {
     long	last_meal;
 
     pthread_mutex_lock(&philo->last_meal_mtx);
     last_meal = philo->last_meal_time;
     pthread_mutex_unlock(&philo->last_meal_mtx);
     return (last_meal);
 }
 
 int	get_nb_meals(t_philo *philo)
 {
     int	meal_counter;
 
     pthread_mutex_lock(&philo->nb_meals_mtx);
     meal_counter = philo->nb_meals;
     pthread_mutex_unlock(&philo->nb_meals_mtx);
     return (meal_counter);
 }
 
 bool	get_full_state(t_philo *philo)
 {
     bool	full;
 
     pthread_mutex_lock(&philo->full_state_mtx);
     full = philo->full;
     pthread_mutex_unlock(&philo->full_state_mtx);
     return (full);
 }
 
 bool	is_simulation_over(t_philo *philo)
 {
     bool	result;
 
     //result = false;
     pthread_mutex_lock(&philo->data->sim_over_mtx);
     result = philo->data->sim_is_over;
     pthread_mutex_unlock(&philo->data->sim_over_mtx);
     return (result);
 }
