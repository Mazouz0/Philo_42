/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:54:47 by mohmazou          #+#    #+#             */
/*   Updated: 2024/11/20 13:37:06 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_allocat(t_philo **philos, t_mtx **forks, t_share arg)
{
	*forks = (t_mtx *)ft_malloc((sizeof(t_mtx) * arg.nbr_philo), 0);
	if (!(*forks))
		return (1);
	*philos = (t_philo *)ft_malloc((sizeof(t_philo) * arg.nbr_philo), 0);
	if (!(*philos))
		return (1);
	return (0);
}

int	ft_init(t_data *data, t_share arg, t_philo *philo, t_mtx *forks)
{
	int	i;

	i = 0;
	if (ft_init_mutex(data, arg, forks))
		return (1);
	data->end_simulation = false;
	data->start_time = gettime();
	data->start_simulation = gettime();
	data->full_philos = 0;
	while (i < arg.nbr_philo)
	{
		philo[i].id = i + 1;
		philo[i].data = data;
		philo[i].arg = &arg;
		philo[i].is_dead = data;
		philo[i].last_meal_t = gettime();
		philo[i].meals_conter = 0;
		philo[i].l_fork = &forks[i];
		philo[i].r_fork = &forks[(i + 1) % arg.nbr_philo];
		philo[i].is_finish = false;
		i ++;
	}
	return (0);
}

void	start_philo(t_philo *philo, t_share *arg)
{
	int	i;

	i = -1;
	while (++i < arg->nbr_philo)
	{
		if (ft_thread(&philo[i].thread, lifesycle, &philo[i], CREATE))
			return ;
	}
	ft_monitor(philo);
	i = -1;
	while (++i < arg->nbr_philo)
	{
		if (ft_thread(&philo[i].thread, NULL, NULL, JOIN))
			return ;
	}
	cleanup(NULL);
}

int	main(int ac, char **av)
{
	t_share	arg;
	t_data	data;
	t_philo	*philo;
	t_mtx	*forks;

	if (ac < 5 || ac > 6 || !is_valid_input(ac, av, &arg))
		return (error_input());
	if (ac == 6 && to_int(av[5]) == 0)
		return (0);
	if (ft_allocat(&philo, &forks, arg))
		return (error_philo("Malloc"));
	if (ft_init(&data, arg, philo, forks))
		return (error_philo("Mutix/Threads"));
	start_philo(philo, &arg);
	return (0);
}
