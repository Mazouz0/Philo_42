/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohmazou <mohmazou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 13:45:50 by mohmazou          #+#    #+#             */
/*   Updated: 2024/11/16 17:05:53 by mohmazou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*free_all(void **ptrs_list, int *index)
{
	int	i;

	i = 0;
	if (!ptrs_list)
		return (NULL);
	while (i <= (*index))
	{
		if (ptrs_list[i])
			free(ptrs_list[i]);
		ptrs_list[i] = NULL;
		i ++;
	}
	return (*index = 0, NULL);
}

void	*ft_malloc(size_t size, int flag)
{
	static void	*ptrs_list[INT_MAX];
	static int	index;
	void		*ptr;

	if (flag)
		return (free_all(ptrs_list, &index));
	ptr = malloc(size);
	if (!ptr)
		return (NULL);
	ptrs_list[index ++] = ptr;
	ptrs_list[index] = NULL;
	return (ptr);
}

void	save_mutex(void *mtx, int flag)
{
	static void	*mutexs[100000];
	static int	index;
	int			i;

	i = 0;
	if (flag)
	{
		while (mutexs[i])
		{
			ft_mutex(mutexs[i], DESTROY);
			mutexs[i] = NULL;
			i++;
		}
		index = 0;
		return ;
	}
	mutexs[index++] = mtx;
	mutexs[index] = NULL;
}

int	cleanup(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
			i++;
		write(2, str, i);
	}
	save_mutex(NULL, 1);
	ft_malloc(0, 1);
	return (1);
}
