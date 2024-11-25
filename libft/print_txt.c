/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_txt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 14:45:54 by mairivie          #+#    #+#             */
/*   Updated: 2024/11/25 13:59:56 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_print_string(char *str)
{
	int	len;

	len = 0;
	if (str == NULL)
	{
		ft_print_string("(null)");
		return (6);
	}
	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}
