/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 05:55:44 by mohmazou          #+#    #+#             */
/*   Updated: 2024/11/14 03:37:25 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>
# include <limits.h>

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef pthread_mutex_t	t_mtx;
typedef pthread_t		t_ptd;
typedef struct s_data	t_data;
typedef struct timeval	t_time;

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING,
	THINKING,
	DEAD,
	FULL,
}	t_state;

typedef enum e_mutix_state
{
	INIT = 1,
	LOCK,
	UNLOCK,
	DESTROY,
}	t_mutix;

typedef enum e_pthread_state
{
	CREATE = 1,
	JOIN,
	DETACH,
}	t_pthread;

typedef struct s_share
{
	t_ptd	monitor_ptd;
	int		nbr_philo;
	int		eat_time;
	int		die_time;
	int		sleep_time;
	int		meals;
}	t_share;

typedef struct s_philo
{
	t_ptd	thread;
	int		id;
	long	meals_conter;
	long	last_meal_t;
	bool	is_dead;
	bool	is_finish;
	t_mtx	*l_fork;
	t_mtx	*r_fork;
	t_data	*data;
	t_share	*arg;
}	t_philo;

typedef	struct s_data
{
	int			ready_count;
	int			full_philos;
	long		start_simulation;
	bool		end_simulation;
	long long	start_time;
	t_mtx		monitor_mtx;
	t_mtx		print;
	t_mtx		meals;
	t_mtx		stop_mtx;
}	t_data;



void	*ft_malloc(size_t size, int flag);
int		is_valid_input(int ac, char **av, t_share *arg);
int		error_input(void);
int		error_philo(void);
int		ft_mutex(t_mtx *mutex, int flag);
void	save_mutex(void *mtx, int flag);
int		cleanup(char *str);
long	gettime(void);
int		ft_init_mutex(t_data *data, t_share arg, t_mtx *forks);
int		ft_thread(t_ptd *thread, void*(*routin)(void *), void *arg, int flag);
int		ft_mutex(t_mtx *mutex, int flag);
void	*ft_monitor(void *arg);
void	*lifesycle(void *arg);
void	ft_sleep(long to_sleep,t_philo *philo);
int		is_dead(t_philo *philo);
int		hold_fork(t_philo *philo);
void	ft_eat(t_philo *philo);
void	ft_write(t_philo *philo, char *flag);



#endif