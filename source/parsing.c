/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:36:02 by mairivie          #+#    #+#             */
/*   Updated: 2024/11/25 12:32:15 by mairivie         ###   ########.fr       */
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

bool	is_bigger_than_zero_and_smaller_than_int_max(char *string)
{
	long	long_to_check;

	long_to_check = ft_atol(string);
	if (long_to_check < 1)
		return (false);
	if (long_to_check > INT_MAX)
		return (false);
	return (true);
}

bool	looks_like_a_number(char *str)
{
	int	i;

	i = 0;
	if ((str[i] == '+' || str[i] == '-') && (str[i + 1]))
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
		return (ft_printf("looks not like a long\n"), false);
	if (is_bigger_than_zero_and_smaller_than_int_max(str) == false)
		return (ft_printf("invalid range\n"), false);
	return (true);
}

int	check_parsing(int ac, char **av)
{
	int i;

	if (ac < 5 || ac > 6)
		return (ft_printf("nb arg error\n"), FAILURE);
	i = 1;
	while (av[i])
	{
		if (is_valid_int_number(av[i]) == false)
			return(ft_printf("bad argument\n"), FAILURE);
		++i;
	}
	return (SUCCESS);
}
