/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 06:24:42 by mohmazou          #+#    #+#             */
/*   Updated: 2024/11/06 09:24:18 by mohmazou         ###   ########.fr       */
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

int	is_all_digits(int ac, char **av)
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
	}
	return (1);
}
