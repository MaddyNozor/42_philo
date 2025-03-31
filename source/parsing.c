/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:36:02 by mairivie          #+#    #+#             */
/*   Updated: 2025/03/31 17:54:24 by codespace        ###   ########.fr       */
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

int	looks_like_an_int(char *str)
{
	int	i;
	int	nb_len;

	i = 0;
	nb_len = 0;
	while (ft_is_whitespace(str[i]) == true)
		i++;
	if ((str[i] == '+' || str[i] == '-') && (str[i + 1]))
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == false)
			return (FAILURE);
		i++;
		nb_len++;
		if (nb_len > 10)
			return (ft_error("Argument too big, limit is INT_MAX."));
	}
	return (SUCCESS);
}

int	is_valid_int_number(char *str)
{
	if (str == NULL || *str == '\0')
		return (ft_error("Empty String"));
	if (looks_like_an_int(str) == FAILURE)
		return (ft_error("Looks like your argument is not a valid int."));
	if (is_bigger_than_zero_and_smaller_than_int_max(str) == false)
		return (ft_printf("invalid range\n"), false);
	return (true);
}

int	check_parsing(int ac, char **av)
{
	int i;

	if (ac < 5 || ac > 6)
		return (ft_error("Need between 4 and 5 numeric arguments."));
	i = 1;
	while (av[i])
	{
		if (is_valid_int_number(av[i]) == false)
			return(ft_error("nombre invalide"));
		++i;
	}
	return (SUCCESS);
}
