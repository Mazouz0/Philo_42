/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 06:24:42 by mohmazou          #+#    #+#             */
/*   Updated: 2024/11/16 17:04:53 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i ++;
	return (i);
}

long	to_int(char *str)
{
	int		i;
	int		j;
	long	res;

	i = 0;
	j = ft_strlen(str) - 1;
	res = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i ++;
	while (j >= i && (str[j] == ' ' || str[j] == '\t'))
		j --;
	if (str[i] == '+')
		i++;
	while (i <= j)
	{
		res = (res * 10) + (str[i] - '0');
		if (res > INT_MAX)
			return (res);
		i ++;
	}
	return (res);
}

int	is_digit(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str) - 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i ++;
	while (j >= i && (str[j] == ' ' || str[j] == '\t'))
		j --;
	if (str[i] == '+')
		i ++;
	while (i <= j)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		if (str[j] < '0' || str[j] > '9')
			return (0);
		i ++;
		j --;
	}
	return (1);
}

int	is_wrong_input(long nbr, int i, t_share *arg)
{
	if (i == 1)
	{
		if (nbr < 1 || nbr > 200)
			return (1);
		arg->nbr_philo = nbr;
		arg->meals = -1;
	}
	else if (i == 5)
	{
		if (nbr)
		{
			if (nbr < 1)
				return (1);
			arg->meals = nbr;
		}
	}
	else if (nbr < 60)
		return (1);
	if (i == 2)
		arg->die_time = nbr;
	if (i == 3)
		arg->eat_time = nbr;
	if (i == 4)
		arg->sleep_time = nbr;
	return (0);
}

int	is_valid_input(int ac, char **av, t_share *arg)
{
	long	nbr;
	int		i;

	i = 0;
	if (!ac || !av)
		return (1);
	while (++ i < ac)
	{
		if (!av[i][0])
			return (0);
		if (!is_digit(av[i]))
			return (0);
		nbr = to_int(av[i]);
		if (nbr > INT_MAX)
			return (0);
		if (is_wrong_input(nbr, i, arg))
			return (0);
	}
	return (1);
}
