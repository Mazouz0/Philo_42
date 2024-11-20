/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:51:00 by mohmazou          #+#    #+#             */
/*   Updated: 2024/11/20 13:32:37 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_sim(t_philo philo)
{
	ft_mutex(&philo.data->stop_mtx, LOCK);
	philo.data->end_simulation = true;
	ft_mutex(&philo.data->stop_mtx, UNLOCK);
}

int	eat_all_meals(t_philo philo)
{
	if (philo.arg->meals != -1)
	{
		ft_mutex(&philo.data->meals, LOCK);
		if (philo.data->full_philos == philo.arg->nbr_philo)
		{
			ft_mutex(&philo.data->meals, UNLOCK);
			ft_mutex(&philo.data->stop_mtx, LOCK);
			philo.data->end_simulation = true;
			ft_mutex(&philo.data->stop_mtx, UNLOCK);
			return (1);
		}
		ft_mutex(&philo.data->meals, UNLOCK);
	}
	return (0);
}

void	*ft_monitor(void *arg)
{
	long	passetime;
	int		i;
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (true)
	{
		i = -1;
		passetime = 0;
		while (++i < philo[0].arg->nbr_philo)
		{
			ft_mutex(&philo[0].data->monitor_mtx, LOCK);
			passetime = gettime() - philo[i].last_meal_t;
			if (passetime >= philo[i].arg->die_time)
			{
				end_sim(philo[i]);
				printf("%ld %d %s\n", passetime, philo[i].id, DIED);
				return (ft_mutex(&philo[0].data->monitor_mtx, UNLOCK), NULL);
			}
			ft_mutex(&philo[0].data->monitor_mtx, UNLOCK);
			if (eat_all_meals(philo[i]))
				return (NULL);
		}
	}
	return (NULL);
}

void	*lifesycle(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_sleep(philo->arg->eat_time, philo);
	while (true)
	{
		if (is_dead(philo))
			break ;
		if (hold_fork(philo))
			break ;
		ft_eat(philo);
		if (ft_mutex(philo->l_fork, UNLOCK))
			break ;
		if (ft_mutex(philo->r_fork, UNLOCK))
			break ;
		ft_write(philo, SLEEP);
		ft_sleep(philo->arg->sleep_time, philo);
		ft_write(philo, THINK);
	}
	return (NULL);
}
