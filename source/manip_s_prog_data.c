/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_s_prog_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:16:57 by mairivie          #+#    #+#             */
/*   Updated: 2025/03/31 16:51:54 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

/*

typedef struct s_prog_data {
	int		nb_philo;
	t_philo *agora;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
}		t_prog_data;
*/

void	ft_init_philo(t_philo *philo)
{
	philo->namber++;
	// philo.namber--;
	// return (SUCCESS);
}

int	ft_init_agora(t_data_table *data)
{
	int	i;

	i = 0;
	while (i <= data->nb_philo)
	{
		data->agora[i].start_time_philo = (long)get_time();
		data->agora[i].namber = i + 1;
		++i;
	}
	return (SUCCESS);
}

int	ft_init_prog_data(int ac, char **av, t_data_table *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->start_time = (long)get_time();
	if (ac == 6)
		data->nb_time_must_eat = ft_atoi(av[5]);
	data->agora = ft_calloc(sizeof(t_philo), data->nb_philo + 1);
	if (data->agora == NULL)
		return (FAILURE);
	if (ft_init_agora(data) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}