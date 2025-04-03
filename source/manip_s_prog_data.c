/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manip_s_prog_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:16:57 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/03 18:51:47 by mairivie         ###   ########.fr       */
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
	// data->agora = malloc(sizeof(t_philo) * data->nb_philo);
	// if (data->agora == NULL)
	// 	return (ft_error("Malloc failure !"));
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
	while (1)
	{
		good_night(arg);
		if (bon_appetit(arg) == FAILURE)
			break;
	}
	return (NULL);
}

void	ft_init_base_values_except_mutex(t_data_table *data, int i)
{
	
	data->agora[i].data = data;
	data->agora[i].gap_last_meal = 0;
	data->agora[i].full = false;
	data->agora[i].nb_meals = 0;
	data->agora[i].namber = i;
	data->agora[i].start_time_philo = get_time();
}

/*
	while (i < data->nb_of_philo)
	{
		init_philo(&data->philos[i], data, i, start_time);
		pthread_mutex_init(&data->philos[i].r_fork, NULL);
		if (i != 0)
			data->philos[i].l_fork = &data->philos[i - 1].r_fork;
		i++;
	}
	data->philos[0].l_fork = &data->philos[data->nb_of_philo - 1].r_fork;
*/
	
int	ft_init_philo(t_data_table *data)
{
	int i;

	i = 1;
	while (i <= data->nb_philo)
	{
		ft_init_base_values_except_mutex(data, i);
		pthread_mutex_init(&data->agora[i].right_stick, NULL);
		if (i > 1)
			data->agora[i].left_stick = &data->agora[i - 1].right_stick;
		i++;
	}
	data->agora[0].left_stick = &data->agora[i].right_stick;
	i = 1;
	while (i <= data->nb_philo)
	{
		pthread_create(&data->agora[i].id_thread, NULL, ft_routine,
			&data->agora[i]);
		i++;
	}
	return (SUCCESS);
}
