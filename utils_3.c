/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 23:42:58 by mohmazou          #+#    #+#             */
/*   Updated: 2024/11/14 05:42:56 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	is_dead(t_philo *philo)
{
	ft_mutex(&philo->data->stop_mtx, LOCK);
	if (philo->data->end_simulation || philo->is_finish)
		return (ft_mutex(&philo->data->stop_mtx, UNLOCK), 1);
	return (ft_mutex(&philo->data->stop_mtx, UNLOCK), 0);
}

void	ft_write(t_philo *philo, char *action)
{
	long	time;
	
	if (is_dead(philo))
		return ;
	ft_mutex(&philo->data->print, LOCK);
	time = gettime() - philo->data->start_simulation;
	printf("%ld %d %s\n", time, philo->id, action);
	ft_mutex(&philo->data->print, UNLOCK);
}

int	hold_fork(t_philo *philo)
{
	if (ft_mutex(philo->l_fork, LOCK))
		return (1);
	ft_write(philo, TAKE_FORKS);
	if (philo->arg->nbr_philo == 1)
	{
		ft_mutex(philo->l_fork, UNLOCK);
		philo->is_finish = true;
		return (1);
	}
	if (ft_mutex(philo->r_fork, LOCK))
		return (1);
	ft_write(philo, TAKE_FORKS);
	return (0);
}

void	ft_eat(t_philo *philo)
{
	ft_write(philo, EAT);
	ft_sleep(philo->arg->eat_time, philo);
	ft_mutex(&philo->data->monitor_mtx, LOCK);
	philo->last_meal_t = gettime();
	ft_mutex(&philo->data->monitor_mtx, UNLOCK);
	ft_mutex(&philo->data->meals, LOCK);
	if (philo->arg->meals != -1)
	{
		philo->meals_conter += 1;
		if (philo->meals_conter == philo->arg->meals)
			philo->data->full_philos += 1;
	}
	ft_mutex(&philo->data->meals, UNLOCK);
}