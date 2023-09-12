/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:41:24 by afaqir            #+#    #+#             */
/*   Updated: 2023/09/12 18:57:19 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	_fill_structs(t_base *data, int ac, char **av)
{
	data->nb_of_philos = ft_atoi(av[1]);
	data->time_to_die = ft_atoi(av[2]);
	data->time_to_eat = ft_atoi(av[3]);
	data->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->nb_of_meals = ft_atoi(av[5]);
	else
		data->nb_of_meals = 0;
	data->is_dead = 1;
	data->philos = malloc(sizeof(t_philo) * data->nb_of_philos);
	if (!data->philos)
		return (1);
	data->tid_arr = malloc(sizeof(pthread_t) * data->nb_of_philos);
	if (!data->tid_arr)
	{
		free(data->philos);
		return (1);
	}
	pthread_mutex_init(&data->print, NULL);
	pthread_mutex_init(&data->m_death, NULL);
	data->start_time = get_time();
	return (_init_philos(data));
}

int	_init_philos(t_base *data)
{
	pthread_mutex_t		*mutex;
	int					i;

	i = 0;
	mutex_array = malloc(sizeof(pthread_mutex_t) * data->nb_of_philos);
	if (!mutex_array)
	{
		free(data->philos);
		free(data->tid_arr);
		return (1);
	}
	while (i < data->nb_of_philos)
	{
		pthread_mutex_init(&mutex_array[i], NULL);
		data->philos[i].id = i + 1;
		data->philos[i].last_meal = 0;
		data->philos[i].meals_count = 0;
		data->philos[i].mutex = mutex_array;
		data->philos[i].base = data;
		pthread_mutex_init(&data->philos[i].meal_prot, NULL);
		pthread_mutex_init(&data->philos[i].count_prot, NULL);
		i++;
	}
	return (0);
}
