/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:09:34 by mairivie          #+#    #+#             */
/*   Updated: 2024/11/25 19:39:12 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_hello(void *philo_name)
{
	static pthread_mutex_t print_mutex;

	//pthread_mutex_init(&print_mutex, NULL);
	pthread_mutex_lock(&print_mutex);
	ft_printf("Hello, World ! I'm philo %i.\n", philo_name);
	pthread_mutex_unlock(&print_mutex);
	//pthread_mutex_destroy(&print_mutex);
	return (NULL);
}

int	main(int ac, char **av)
{
	int	nb_philo;
	pthread_t *agora;
	int i;
	
	if(check_parsing(ac, av) == FAILURE)
		return (FAILURE);
	nb_philo = ft_atoi(av[1]);
	i = 0;
	agora  = malloc(sizeof(pthread_t) * nb_philo);
		if (agora == NULL)
			return (FAILURE);
	while (i < nb_philo)
	{
		pthread_create(&agora[i], NULL, ft_hello, &i);
		++i;
	}
	i = 0;
	while (i < nb_philo)
	{
		pthread_join(agora[i], NULL);
		++i;
	}
	free(agora);
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
// ft_printf("arg 1:%s 2:%s 3:%s 4:%s 5:%s 6:%s \n", av[1], av[2], av[3], av[4], av[5], av[6], av[7]);
// 	nb_philo = av[1];
// 	time_to_die = av[2];
// 	time_to_eat = av[3];
// 	time_to_sleep = av[4];
// 	if (ac == 6) //TODO y a ce cas a gerer. tsss clean code a faire
// 		nb_time_must_eat = av[5];


    // pthread_mutex_lock(&print_mutex); // Début de la section critique
    // printf("Hello, World! I'm philo %d.\n", philo_num);
    // pthread_mutex_unlock(&print_mutex); // Fin de la section critique