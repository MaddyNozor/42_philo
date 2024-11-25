/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speak_to_me.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 16:21:18 by mairivie          #+#    #+#             */
/*   Updated: 2024/11/25 18:51:39 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philosophers.h"

void	*ft_hello(void *philo_name)
{
	ft_printf("Hello, World ! I'm philo %i.\n", philo_name);
	return (NULL);
}