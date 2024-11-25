/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mairivie <mairivie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:29:11 by mairivie          #+#    #+#             */
/*   Updated: 2024/11/25 17:25:27 by mairivie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

//--------------------- INCLUDES -----------------------------
# include "libft.h"
# include <unistd.h> //
# include <stdlib.h>
# include <stdbool.h>
# include <limits.h>
# include <stdio.h> // printf pour les tests
# include <pthread.h> // toolbox for threads

//--------------------- DEFINES -----------------------------

# define FAILURE 1
# define SUCCESS 0

//--------------------- STRUCTURES -----------------------------


//--------------------- FONCTION -----------------------------

int	check_parsing(int ac, char **av);

#endif
