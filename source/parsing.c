/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:36:02 by mairivie          #+#    #+#             */
/*   Updated: 2024/11/19 17:56:21 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

long	ft_atol(const char *str) //TODO mettre atol dans ma libft
{
	int		i;
	int		sign;
	long	number;

	if (str == NULL || *str == '\0')
		return (0);
	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (sign * number);
}

bool	detect_int_overflow(char *string)
{
	long	long_to_check;

	long_to_check = ft_atol(string);
	if (long_to_check > INT_MAX)
		return (true);
	if (long_to_check < INT_MIN)
		return (true);
	return (false);
}

bool	looks_like_a_number(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	// if ((str[i] == '+' || str[i] == '-') && (str[i + 1]))
	// 	i++;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_int_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (ft_printf("t'es vide\n"), false); //TODO 000 en premier arg rentre dans cette boucle. why ???
	if (looks_like_a_number(str) == false)
		return (ft_printf("looks not like an int\n"), false);
	if (detect_int_overflow(str) == true)
		return (ft_printf("overflow baby\n"), false);
	return (true);
}

int	check_parsing(int ac, char **av)
{
	static char	*nb_philo;
	static char	*time_to_die;
	static char	*time_to_eat;
	static char	*time_to_sleep;
	static char	*nb_time_must_eat;
	
	if (ac < 6 || ac > 7)
		return (ft_printf("nb arg error\n"), FAILURE);
	nb_philo = av[2];
	time_to_die = av[3];
	time_to_eat = av[4];
	time_to_sleep = av[5];
	if (ac == 6)
		nb_time_must_eat = av[6];
	if (is_valid_int_number(nb_philo) == false)
		return(FAILURE);
	if (is_valid_int_number(time_to_die) == false)
		return(FAILURE);
	if (is_valid_int_number(time_to_eat) == false)
		return(FAILURE);
	if (is_valid_int_number(time_to_sleep) == false)
		return(FAILURE);
	if (is_valid_int_number(nb_time_must_eat) == false)
		return(FAILURE);
	return (SUCCESS);
}

