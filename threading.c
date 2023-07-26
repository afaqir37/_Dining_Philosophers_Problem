#include "philosopher.h"
static int count = 0;
void *rountine(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;
    int i = 0;
    while (philo->base->is_dead && i < 5)
    {
        //pthread_mutex_lock(&philo->base->print);
        printf("still alive\n");
        //count++;
        //printf("%d\n", count);
        philo->base->is_dead++;
        //pthread_mutex_unlock(&philo->base->print);
        i++;
    }
   

    return NULL;
}


int    _launch_threads(t_base *data)
{

    int i = 0;
    while (i < data->nb_of_philos)
    {
        if (pthread_create(&data->tid_arr[i], NULL, rountine, &data->philos[i]))
            return (1);
       //pthread_join(data->tid_arr[i], NULL);
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