#include "philosopher.h"
static int count = 0;
void *rountine(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
    if (philo->id % 2 == 0)
        usleep(2000);
    pthread_create(&philo->tid, NULL, supervisor, (void *)philo);
    pthread_detach(philo->tid);
    //philo->kk = get_time();
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
        // pthread_join(data->tid_arr[i], NULL);
         //usleep(10);
        i++;
    }
    i = 0;
    while (i < data->nb_of_philos)
    {
        pthread_join(data->tid_arr[i], NULL);
        i++;
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