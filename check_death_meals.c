/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death_meals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 18:27:10 by afaqir            #+#    #+#             */
/*   Updated: 2023/09/12 18:41:01 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	_check_death(t_philo *philos)
{
	pthread_mutex_lock(&philos->meal_prot);
	if (get_time() - philos->last_meal >= philos->base->time_to_die)
	{
		pthread_mutex_unlock(&philos->meal_prot);
		pthread_mutex_lock(&philos->base->m_death);
		philos->base->is_dead = 0;
		pthread_mutex_unlock(&philos->base->m_death);
		ft_print_status(philos, "died");
	}
	else
		pthread_mutex_unlock(&philos->meal_prot);
}

void	_check_meals(t_base *data)
{
	int	i;

	i = 0;
	while (data->nb_of_meals)
	{
		pthread_mutex_lock(&data->philos[i].count_prot);
		if (data->philos[i].meals_count < data->nb_of_meals)
		{
			pthread_mutex_unlock(&data->philos[i].count_prot);
			break ;
		}
		else
		{
			pthread_mutex_unlock(&data->philos[i].count_prot);
			i++;
		}
		if (i == data->nb_of_philos)
		{
			pthread_mutex_lock(&data->m_death);
			data->is_dead = 0;
			pthread_mutex_unlock(&data->m_death);
			break ;
		}
	}
}
