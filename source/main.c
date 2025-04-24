/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:09:34 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/24 18:09:43 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int ac, char **av)
{
	t_data_table	data;

	memset(&data, 0, sizeof(t_data_table));
	if (check_parsing(ac, av) == FAILURE)
		return (FAILURE);
	if (ft_init_prog_data(ac, av, &data) == FAILURE)
		return (ft_error("Init Data_table failed !"));
	data.agora = malloc(sizeof(t_philo) * (data.nb_philo + 1));
	if (data.agora == NULL)
		return (ft_error("Malloc failure !"));
	if (ft_init_philo(&data) == FAILURE)
		return (ft_error("Init threads failed !"));
	while (1)
	{
		if (death_has_come(&data))
			break ;
		if (no_more_pasta_needed(&data))
			break ;
		usleep(500);
	}
	ft_clean_exit(&data);
	free(data.agora);
	return (SUCCESS);
}

// NOTES DIVERSES