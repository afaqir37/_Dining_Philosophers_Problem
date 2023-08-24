#include "philosopher.h"

void    _check_death(t_philo    *philos)
{
        pthread_mutex_lock(&philos->meal_prot);
        //printf("time to die = %ld\n",get_time() - philos->last_meal);
        if (get_time() - philos->last_meal >= philos->base->time_to_die)
        {
           // printf("here\n");
            pthread_mutex_unlock(&philos->meal_prot);
            pthread_mutex_lock(&philos->base->m_death);
            philos->base->is_dead = 0;
            pthread_mutex_unlock(&philos->base->m_death);
            ft_print_status(philos, "died");
            
        }
        else
            pthread_mutex_unlock(&philos->meal_prot);
}

void    _check_meals(t_base *data)
{
    int i = 0;
    while (data->nb_of_meals)
    {
        pthread_mutex_lock(&data->philos[i].count_prot);
        if (data->philos[i].meals_count < data->nb_of_meals)
        {
            pthread_mutex_unlock(&data->philos[i].count_prot);
            break;
        }
        else
        {
            pthread_mutex_unlock(&data->philos[i].count_prot);
            i++;
        }
        if (i == data->nb_of_philos - 1)
        {
            pthread_mutex_lock(&data->m_death);
            data->is_dead = 0;
            pthread_mutex_unlock(&data->m_death);
        }
    }
}