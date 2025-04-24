/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:03:50 by mairivie          #+#    #+#             */
/*   Updated: 2025/04/24 19:12:11 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

//check if char c is a whitespace and return true or false accordingly.
//  ‘ ‘ : Space
// ‘\t’ : Horizontal Tab
// ‘\n’ : Newline
// ‘\v’ : Vertical Tab
// ‘\f’ : Feed
// ‘\r’ : Carriage Return
bool	ft_is_whitespace(char c)
{
	if (c >= 9 && c <= 13)
		return (true);
	else if (c == ' ')
		return (true);
	else if (c == '\'' || c == '\"')
		return (true);
	return (false);
}

/* DESC: The atoi() function converts the initial portion of the string pointed
 * to by str to int representation. 
 * the string may begin with an arbitrary number of whitespaces as determinded
 *  by isspace(3).
 * After the whitespaces, there can be one single optional '+' or '-' sign.
 * The remainder of the string will be converted to an int,stopping at the 
 * first char wich is not a valid digit.
 *
 * RETURN VALUES: The int representation of the string.*/
int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	number;

	if (str == NULL || *str == '\0')
		return (0);
	i = 0;
	sign = 1;
	number = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + (str[i] - '0');
		i++;
	}
	return (sign * number);
}

long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

//return print the message then return FAILURE 
int	ft_error(char *str)
{
	printf("Error: %s\n", str);
	return (FAILURE);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
