/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speak_to_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:21:18 by mairivie          #+#    #+#             */
/*   Updated: 2024/11/26 18:39:10 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void	*ft_hello(void *arg)
{
	static pthread_mutex_t	print_mutex;
	t_philo					*philo;

	philo = (t_philo *)arg;
	pthread_mutex_lock(&print_mutex);
	printf("Hello, World ! I'm philo %i.\n", philo->namber);
	pthread_mutex_unlock(&print_mutex);
	return (NULL);
}
