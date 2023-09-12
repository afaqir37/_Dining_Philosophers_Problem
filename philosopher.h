/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afaqir <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 19:11:04 by afaqir            #+#    #+#             */
/*   Updated: 2023/09/12 19:17:44 by afaqir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				id;
	pthread_t		tid;
	long int		last_meal;
	long int		kk;
	int				meals_count;
	pthread_mutex_t	*mutex;
	struct s_base	*base;
	pthread_mutex_t	meal_prot;
	pthread_mutex_t	count_prot;
}	t_philo;
typedef struct s_base
{
	int				nb_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				nb_of_meals;
	int				is_dead;
	long int		start_time;
	t_philo			*philos;
	pthread_t		*tid_arr;
	pthread_mutex_t	print;
	pthread_mutex_t	m_death;
}	t_base;
int			ft_atoi(const char *str);
int			_init_philos(t_base *data);
int			_fill_structs(t_base *data, int ac, char **av);
int			_check_input(int argc, char **argv);
int			_launch_threads(t_base *data);
void		_eat(t_philo *philo);
void		_sleep_think(t_philo *philo);
long int	get_time(void);
void		ft_usleep(long int time);
void		ft_print_status(t_philo *philo, char *str);
void		_check_meals(t_base *data);
void		_check_death(t_philo *philos);
#endif
