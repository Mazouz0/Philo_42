/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 16:36:54 by mohmazou          #+#    #+#             */
/*   Updated: 2024/11/18 16:18:15 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	gettime(void)
{
	t_time	time;

	if (gettimeofday(&time, NULL))
		return (printf("gettimeofday : failed\n"), 0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	ft_thread(t_ptd *thread, void*(*routin)(void *), void *arg, int flag)
{
	int	st;

	st = 0;
	if (flag == CREATE)
		st = pthread_create(thread, NULL, routin, arg);
	if (flag == JOIN)
		st = pthread_join(*thread, NULL);
	if (flag == DETACH)
		st = pthread_detach(*thread);
	if (st != 0)
		return (cleanup("pthread error \n"));
	return (0);
}

int	ft_mutex(t_mtx *mutex, int flag)
{
	int	ret;

	ret = 0;
	if (flag == INIT)
	{
		ret = pthread_mutex_init(mutex, NULL);
		save_mutex(mutex, 0);
	}
	else if (flag == LOCK)
		ret = pthread_mutex_lock(mutex);
	else if (flag == UNLOCK)
		ret = pthread_mutex_unlock(mutex);
	else if (flag == DESTROY)
		ret = pthread_mutex_destroy(mutex);
	if (ret != 0)
		return (cleanup(NULL));
	return (0);
}

int	ft_init_mutex(t_data *data, t_share arg, t_mtx *forks)
{
	int	i;

	i = 0;
	while (i < arg.nbr_philo)
	{
		if (ft_mutex(forks + i, INIT))
			return (cleanup("MUTEX: Initialling failed"));
		i++;
	}
	if (ft_mutex(&data->stop_mtx, INIT)
		|| ft_mutex(&data->print, INIT)
		|| ft_mutex(&data->monitor_mtx, INIT)
		|| ft_mutex(&data->meals, INIT))
		return (cleanup("MUTEX: Initialling failed"));
	return (0);
}

void	ft_sleep(long to_sleep, t_philo *philo)
{
	long	start;

	start = gettime();
	while ((gettime() - start) < to_sleep)
	{
		ft_mutex(&philo->data->stop_mtx, LOCK);
		if (philo->data->end_simulation || philo->is_finish)
		{
			ft_mutex(&philo->data->stop_mtx, UNLOCK);
			return ;
		}
		ft_mutex(&philo->data->stop_mtx, UNLOCK);
		usleep(150);
	}
}
