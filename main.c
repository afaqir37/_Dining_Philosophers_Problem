/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:00:55 by afaqir            #+#    #+#             */
/*   Updated: 2023/09/12 19:10:52 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	free_all(t_base *s)
{
	if (s->philos[0].mutex)
		free(s->philos[0].mutex);
	if (s->philos)
		free(s->philos);
	if (s->tid_arr)
		free(s->tid_arr);
	if (s)
		free(s);
}

void	_single_philo(t_base *data)
{
	ft_print_status(&data->philos[0], "has taken a fork");
	ft_usleep(data->time_to_die);
	ft_print_status(&data->philos[0], "died");
}

int	_free_the_base(t_base *data)
{
	free(data);
	return (1);
}

int	main(int ac, char **av)
{
	t_base	*data;

	if (ac != 5 && ac != 6)
	{
		printf("Usage: ./philo [time_to_die] [time_to_eat] [time_to_sleep] \
		[optional: nb_of_meals]\n");
		return (1);
	}
	data = malloc(sizeof(t_base));
	if (_check_input(ac, av))
		return (_free_the_base(data));
	if (_fill_structs(data, ac, av))
	{
		free(data);
		return (1);
	}
	if (data->nb_of_philos == 1)
	{
		_single_philo(data);
		free_all(data);
	}
	else if (_launch_threads(data))
	{
		free_all(data);
		return (1);
	}
}
