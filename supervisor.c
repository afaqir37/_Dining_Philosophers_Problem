#include "philosopher.h"

void    *supervisor(void *arg)
{
    t_philo *philo;

    philo = (t_philo *)arg;

    while(1)
    {
        pthread_mutex_lock(&philo->meal_prot);
        if (get_time() - philo->last_meal >= philo->base->time_to_die)
        {
            pthread_mutex_lock(&philo->base->m_death);
            philo->base->is_dead = 0;
            pthread_mutex_unlock(&philo->base->m_death);
            break;
        }
        pthread_mutex_unlock(&philo->meal_prot);
    }
}