/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:36:02 by mairivie          #+#    #+#             */
/*   Updated: 2024/11/19 18:52:20 by mairivie         ###   ########.fr       */
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
	// while (str[i] == ' ' || str[i] == '\t')
	// 	i++;
	if ((str[i] == '+') && (str[i + 1]))
		i++;
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
		return (ft_printf("%s t'es vide\n", str), false);
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
	
	ft_printf("ac = %i\n", ac);
	if (ac < 5 || ac > 6)
		return (ft_printf("nb arg error\n"), FAILURE);
ft_printf("arg 1:%s 2:%s 3:%s 4:%s 5:%s 6:%s \n", av[1], av[2], av[3], av[4], av[5], av[6], av[7]);
	nb_philo = av[1];
	time_to_die = av[2];
	time_to_eat = av[3];
	time_to_sleep = av[4];
	if (ac == 6) //TODO y a ce cas a gerer. tsss clean code a faire
		nb_time_must_eat = av[5];
	if (is_valid_int_number(nb_philo) == false)
		return(ft_printf("philo t'es vide\n"), FAILURE);
	if (is_valid_int_number(time_to_die) == false)
		return(ft_printf("die t'es vide\n"), FAILURE);
	if (is_valid_int_number(time_to_eat) == false)
		return(ft_printf("eat t'es vide\n"), FAILURE);
	if (is_valid_int_number(time_to_sleep) == false)
		return(ft_printf("sleep t'es vide\n"), FAILURE);
	if (is_valid_int_number(nb_time_must_eat) == false)
		return(ft_printf("must t'es vide\n"), FAILURE);
	return (SUCCESS);
}

		// ft_printf("MUST ?? %s \n", nb_time_must_eat);
