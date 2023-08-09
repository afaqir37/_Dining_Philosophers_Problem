#include "philosopher.h"
static int count = 0;
void *rountine(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        usleep(2000);
    
    
    int i = 0;
    while (1)
    {
        _eat(philo);
        _sleep_think(philo);
        pthread_mutex_lock(&philo->base->m_death);
        if (philo->base->is_dead == 0)
            break;
       pthread_mutex_unlock(&philo->base->m_death);
    }
   

    return NULL;
}


int    _launch_threads(t_base *data)
{
    int i = 0;
    data->start_time = get_time();
    while (i < data->nb_of_philos)
    {
        if (pthread_create(&data->tid_arr[i], NULL, rountine, &data->philos[i]))
            return (1);
        usleep(10);
        i++;
    }
    
    i = 0;
    while (data->is_dead) {
        pthread_mutex_lock(&data->philos[i].meal_prot);
        if (get_time() - data->philos[i].last_meal >= data->time_to_die)
        {
            pthread_mutex_unlock(&data->philos[i].meal_prot);
            pthread_mutex_lock(&data->m_death);
            data->is_dead = 0;
            pthread_mutex_unlock(&data->m_death);
            ft_print_status(&data->philos[i], "died");
            
        }
        else
            pthread_mutex_unlock(&data->philos[i].meal_prot);
        i = i % data->nb_of_philos;
    }
    return 0;
}

void ft_usleep(long int time)
{
    long int current_time;

    current_time = get_time();
    while (get_time() - current_time < time)
    {
        usleep(100);
    }
}