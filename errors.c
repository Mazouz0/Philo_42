/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 06:19:38 by mohmazou          #+#    #+#             */
/*   Updated: 2024/11/20 13:56:04 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_philo(char *str)
{
	write(STDERR_FILENO, "ERROR: ",7);
	write(STDERR_FILENO, str, ft_strlen(str));
	write(STDERR_FILENO, " Probleme\n", 10);
	return (3);
}

int	error_input(void)
{
	write(STDERR_FILENO, "Error: Invalide input\n", 23);
	write(STDERR_FILENO, "Usage : 0 < nbr_philo < 200\t", 28);
	write(STDERR_FILENO, "60 <= t_die(ms) <= MAX_INT\t", 27);
	write(STDERR_FILENO, "60 <= t_eat(ms) <= MAX_INT\t", 27);
	write(STDERR_FILENO, "60 <= t_sleep(ms) <= MAX_INT\t", 29);
	write(STDERR_FILENO, "[ 1 <= nbr_meals <= MAX_INT ]", 29);
	return (2);
}
