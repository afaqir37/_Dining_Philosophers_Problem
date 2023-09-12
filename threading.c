#include "philosopher.h"
static int count = 0;
void *rountine(void *arg)
{
    t_philo *philo;
    
    philo = (t_philo *)arg;
   // printf("id = %d\n", philo->id);
    // if (philo->id % 2 == 0)
    //     usleep(2000);
    pthread_mutex_lock(&philo->meal_prot);
    philo->last_meal = get_time();
    pthread_mutex_unlock(&philo->meal_prot);
    while (1)
    {
        if (philo->base->nb_of_meals && philo->meals_count == philo->base->nb_of_meals)
            return 0;
        _eat(philo);
        _sleep_think(philo);

    }
   

    return NULL;
}


int    _launch_threads(t_base *data)
{
    int i = 0;
    int token = 0;
    data->start_time = get_time();
    while (i < data->nb_of_philos)
    {
        if (pthread_create(&data->tid_arr[i], NULL, rountine, &data->philos[i]))
            return (1);
        pthread_detach(data->tid_arr[i]);
        usleep(99);
       i++;
    }
    
    i = 0;

    while (data->is_dead) {
        _check_meals(data);
        _check_death(&data->philos[i]);
        

        i++;
        i = i % data->nb_of_philos;
    }
    i = 0;
    // while (i < data->nb_of_philos)
    // {
    //     pthread_join(data->tid_arr[i], NULL);
    //     i++;
    // }
    return 0;
}

void ft_usleep(long int time)
{
    long int current_time;

    current_time = get_time();
    while (get_time() - current_time < time)
    {
        usleep(30);
    }
}
