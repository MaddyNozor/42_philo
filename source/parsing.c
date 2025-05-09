/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:36:02 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/24 20:01:06 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

long	ft_atol(const char *str)
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

bool	is_negative(int nbr)
{
	if (nbr < 0)
		return (true);
	return (false);
}
//TODO mettre atol dans ma libft

bool	is_bigger_than_intmax(long long_to_check)
{
	if (long_to_check > INT_MAX)
		return (true);
	return (false);
}

int	looks_like_an_int(char *str)
{
	int	i;
	int	nb_len;

	i = 0;
	nb_len = 0;
	if (str[i] == '\'' || str[i] == '\"')
		i++;
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
			return (FAILURE);
	}
	return (SUCCESS);
}

int	check_parsing(int ac, char **av)
{
	int		i;
	long	long_to_check;

	if (ac < 5 || ac > 6)
		return (ft_error("Need between 4 and 5 numeric arguments."));
	i = 1;
	while (av[i])
	{
		{
			if (looks_like_an_int(av[i]) == FAILURE)
				return (ft_error("Arg must be true int !"));
			long_to_check = ft_atol(av[i]);
			if (long_to_check == 0)
				return (ft_error("Empty String is not a valid argument."));
			if (is_negative(long_to_check) == true)
				return (ft_error("Arguments must be positive."));
			if (is_bigger_than_intmax(long_to_check) == true)
				return (ft_error("Argument too big, limit is INT_MAX."));
		}
		++i;
	}
	return (SUCCESS);
}

		//TODO: deplacer le check arg vide et message d'erru\eur apres le atol
		// if (av[i] == NULL || av[i] == '\0')
		// 	return (ft_error("Empty String is not a valid argument."));
		// if (looks_like_an_int(av[i]) == FAILURE)
		// 	return (ft_error("Looks like some arg are not valid int."));
		// else
