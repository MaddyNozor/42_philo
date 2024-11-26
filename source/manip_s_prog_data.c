/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_s_prog_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:16:57 by mairivie          #+#    #+#             */
/*   Updated: 2024/11/26 18:31:28 by mairivie         ###   ########.fr       */
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
}				t_prog_data; 
*/

void	ft_init_philo(t_philo *philo)
{
	philo->namber++;
	//philo.namber--;
	//return (SUCCESS);
}

int	ft_init_agora(t_prog_data *data)
{
	int	i;

	i = 1;
	while (i <= data->nb_philo)
	{
		//ft_init_philo(&data->agora[i]);
		data->agora[i].namber = i;
		printf("valeur i: %i - Philo ID: %i\n", i, data->agora[i].namber);
		++i;
	}
	return (SUCCESS);
}

int	ft_init_prog_data(int ac, char **av, t_prog_data *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_time_must_eat = ft_atoi(av[5]);
	data->agora = ft_calloc(sizeof(t_philo), data->nb_philo +1);
	if (data->agora == NULL)
		return (FAILURE);
	printf("Philo ID: %i\n", data->agora[2].namber);
	if (ft_init_agora(data) == FAILURE)
		return (FAILURE);
	printf("Philo ID 2: %i\n", data->agora[2].namber);
	return (SUCCESS);
}