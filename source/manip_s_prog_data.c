/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_s_prog_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:16:57 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/01 17:58:57 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*

typedef struct s_prog_data {
	int		nb_philo;
	t_philo *agora;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
}		t_prog_data;
*/

// void	ft_init_philo(t_philo *philo)
// {
// 	philo->namber++;
// 	// philo.namber--;
// 	// return (SUCCESS);
// }

// int	ft_init_agora(t_data_table *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i <= data->nb_philo)
// 	{
// 		data->agora[i].start_time_philo = (long)get_time();
// 		data->agora[i].namber = i + 1;
// 		++i;
// 	}
// 	return (SUCCESS);
// }



// typedef struct s_data_table
// {
// 	t_philo			*agora;
// 	t_stick			*chopsticks;
// 	long			start_time;
// 	int				nb_philo;
// 	int				time_to_die;
// 	int				time_to_eat;
// 	int				time_to_sleep;
// 	int				nb_time_must_eat;
// 	bool			the_end; // this is the end, my friend
// }				t_data_table;

int	ft_init_prog_data(int ac, char **av, t_data_table *data)
{
	data->nb_philo = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	data->nb_time_must_eat = -1;
	data->the_end = false;
	data->start_time = (long)get_time(); //reel ?
	if (ac == 6)
		data->nb_time_must_eat = ft_atoi(av[5]);
	data->agora = malloc(sizeof(t_philo) * data->nb_philo);
	if (data->agora == NULL)
		return (ft_error("Malloc failure !"));
	return (SUCCESS);
}

// typedef struct s_data_table
// {
// 	t_philo			*agora;
//
// typedef struct s_philo
// {
// 	t_data_table	*data;
// 	t_mutex			right_stick;
// 	t_mutex			*left_stick;
// 	t_thread		id_thread;
// 	long			gap_last_meal;
// 	long			start_time_philo; // a voir
// 	int				namber; // name + number t'as capté ?
// 	int				nb_meals;
// 	bool			full;
// }				t_philo;

static void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	printf("Hello my namber is %i ", philo->namber);
	printf("and my thread_id=%lu \n", philo->id_thread);
	// while (1)
	// {
	// 	sleep(philo->namber);
	// 	printf("Hello my namber is %i ", philo->namber);
	// }
	return (NULL);
}

int	ft_init_philo(t_data_table *data)
{
	int i;

	i = 0;
	while (i < data->nb_philo)
	{
		pthread_create(&data->agora[i].id_thread, NULL, ft_routine,
			&data->agora[i]);
		printf("creation thread %i\n", i);
		i++;
	}
	return (SUCCESS);
}
