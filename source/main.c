/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:09:34 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/22 22:34:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	ft_clean_exit(t_data_table *data)
{
	int	i;

	i = 1;
	while (i <= data->nb_philo)
	{
		pthread_join(data->agora[i].id_thread, NULL);
		i++;
	}
	i = 1;
	while (i <= data->nb_philo)
	{
		pthread_mutex_destroy(&data->agora[i].right_fork);
		i++;
	}
	return;
}	

int	main(int ac, char **av)
{
	t_data_table	data;

	memset(&data, 0, sizeof(t_data_table));
	if (check_parsing(ac, av) == FAILURE)
		return (FAILURE);
	if (ft_init_prog_data(ac, av, &data) == FAILURE)
		return (FAILURE);
	data.agora = malloc(sizeof(t_philo) * (data.nb_philo + 1));
	if (data.agora == NULL)
		return (ft_error("Malloc failure !"));
	if (ft_init_philo(&data) == FAILURE)
		return (FAILURE);
	while(1)
	{
		if (death_has_come(&data))
			break;
		if (no_more_pasta_needed(&data))
			break;
		usleep(500);
	}
	ft_clean_exit(&data);
	free(data.agora);
	return (SUCCESS);
}

// NOTES DIVERSES

// 	static char	*nb_philo;
// 	static char	*time_to_die;
// 	static char	*time_to_eat;
// 	static char	*time_to_sleep;
// 	static char	*nb_time_must_eat;

// 	ft_printf("ac = %i\n", ac);
// 	if (ac < 5 || ac > 6)
// 		return (ft_printf("nb arg error\n"), FAILURE);
// ft_printf("arg 1:%s 2:%s 3:%s 4:%s 5:%s 6:%s \n", av[1], av[2], av[3], av[4],
// av[5], av[6], av[7]);
// 	nb_philo = av[1];
// 	time_to_die = av[2];
// 	time_to_eat = av[3];
// 	time_to_sleep = av[4];
// 	if (ac == 6) //TODO y a ce cas a gerer. tsss clean code a faire
// 		nb_time_must_eat = av[5];

// pthread_mutex_lock(&print_mutex); // Début de la section critique
// printf("Hello, World! I'm philo %d.\n", philo_num);
// pthread_mutex_unlock(&print_mutex); // Fin de la section critique