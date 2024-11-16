/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 06:19:38 by mohmazou          #+#    #+#             */
/*   Updated: 2024/11/16 17:06:13 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	error_philo(void)
{
	write(2, "Error: Malloc OR Mutix/Threads probleme\n", 37);
	return (1);
}

int	error_input(void)
{
	write(2, "Error: Invalide input\n", 23);
	return (1);
}
