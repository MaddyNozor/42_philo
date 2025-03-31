/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:03:50 by mairivie          #+#    #+#             */
/*   Updated: 2025/03/31 17:35:32 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

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
		return (false);
}

long	get_time(void)
{
	struct timeval time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

//return print the message then return FAILURE 
int		ft_error(char *str)
{
	printf("Error: %s/n", str);
	return (FAILURE);
}