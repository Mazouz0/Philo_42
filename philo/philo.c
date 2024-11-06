/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:54:47 by mohmazou          #+#    #+#             */
/*   Updated: 2024/11/06 09:58:04 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_philo(int ac, char **av)
{
(void)ac;
(void)av;
	
	return (0);
}

int	main(int ac, char **av)
{
	if (ac < 5 || ac > 6 || !is_valid_input(ac, av))
		return (error_input());
	printf("good input\n");
	if (ft_philo(ac, av))
		return (error_philo());
	return (0);
}