#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_philo
{
    int                 id;
    pthread_t           tid;
    long int            last_meal;
    int                 meals_count;
    pthread_mutex_t *   mutex;
    
    struct s_base *     base;      

}   t_philo;

typedef struct s_base 
{
    int                 nb_of_philos;
    int                 time_to_die;
    int                 time_to_eat;
    int                 time_to_sleep;
    int                 nb_of_meals;
    int                 is_dead;
    t_philo *           philos;
    pthread_t *         tid_arr;
    pthread_mutex_t     print;

}   t_base;


int     ft_atoi(const char *str);
int  _init_philos(t_base *data);
int _fill_structs(t_base *data, int ac, char **av);
int _check_input(int argc, char **argv);
int    _launch_threads(t_base *data);


# endif