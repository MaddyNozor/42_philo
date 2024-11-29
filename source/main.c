/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:09:34 by mairivie          #+#    #+#             */
/*   Updated: 2024/11/27 14:42:40 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	int			i;
	t_prog_data	data;

	memset(&data, 0, sizeof(t_prog_data));
	if (check_parsing(ac, av) == FAILURE)
		return (FAILURE);
	data.agora = ft_calloc(data.nb_philo, sizeof(t_philo));
	if (data.agora == NULL)
		return (FAILURE);
	if (ft_init_prog_data(ac, av, &data) == FAILURE)
		return (FAILURE);
	i = 0;
	while (i < data.nb_philo)
	{
		//printf("Philo ID before therad: %i\n", data.agora[i].namber);
		pthread_create(&data.agora[i].thread, NULL, &ft_hello, &data.agora[i]);
		// TODO : proteger pthread_create
		++i;
	}
	i = 0;
	while (i < data.nb_philo)
	{
		//printf("philo namber %i my thread is %lu\n", data.agora[i].namber, data.agora[i].thread);
		pthread_join(data.agora[i].thread, NULL);
		++i;
	}
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