#include "philosopher.h"

void    _eat(t_philo *philo)
{
    pthread_mutex_lock(&philo->mutex[philo->id -1]);
    ft_print_status(philo, "has taken a fork");
    pthread_mutex_lock(&philo->mutex[philo->id % philo->base->nb_of_philos]);
    ft_print_status(philo, "has taken a fork");
    ft_print_status(philo, "is eating");
    pthread_mutex_lock(&philo->meal_prot);
    philo->last_meal = get_time();
    pthread_mutex_unlock(&philo->meal_prot);
    ft_usleep(philo->base->time_to_eat);
    pthread_mutex_unlock(&philo->mutex[philo->id % philo->base->nb_of_philos]);
    pthread_mutex_unlock(&philo->mutex[philo->id -1]);
    
}

void    _sleep_think(t_philo *philo)
{
    ft_print_status(philo, "is sleeping");
    ft_usleep(philo->base->time_to_sleep);
    ft_print_status(philo, "is thinking");    
}

void ft_print_status(t_philo *philo, char *str)
{
    pthread_mutex_lock(&philo->base->print);
    printf("%ld %d %s\n", get_time() - philo->base->start_time, philo->id, str);
    pthread_mutex_unlock(&philo->base->print);
}