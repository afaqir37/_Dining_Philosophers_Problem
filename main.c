#include "philosopher.h"

void    free_all(t_base *s)
{
    // int i = 0;
    // while (i < s->nb_of_philos)
    // {
    //     pthread_mutex_destroy(&s->philos[0].mutex[i]);
    //     i++;
    // }
    // i = 0;
    // while (i < s->nb_of_philos)
    // {
    //     pthread_mutex_destroy(&s->philos[i].meal_prot);
    //     pthread_mutex_destroy(&s->philos[i].count_prot);
    //     i++;
    // }
    free(s->philos[0].mutex);
    free(s->philos);
    free(s->tid_arr);
    
    // pthread_mutex_destroy(&s->print);
    // pthread_mutex_destroy(&s->m_death);

    free(s);
}

void _single_philo(t_base *data)
{
    ft_print_status(&data->philos[0], "has taken a fork");
    ft_usleep(data->time_to_die);
    ft_print_status(&data->philos[0], "died");
}
int main(int ac, char **av)
{
    
    if (ac != 5 && ac != 6) {
        printf("Usage: ./philo [time_to_die] [time_to_eat] [time_to_sleep] [optional: nb_of_meals]\n");
        return (1);
    }

    t_base *data = malloc(sizeof(t_base));
   
    if (_check_input(ac, av))
    {
        free(data);
        return (1);
    }
    
    if (_fill_structs(data, ac, av))
    {
        free(data);
        return (1);
    }
    // if (data->nb_of_philos == 1)
    //     _single_philo(data);
    
    if (_launch_threads(data))
    {
        free(data);
        return (1);
    }
    //free_all(data);
}