#include "philosopher.h"
int main(int ac, char **av)
{
    if (ac != 5 && ac != 6) {
        printf("Usage: ./philo [time_to_die] [time_to_eat] [time_to_sleep] [optional: nb_of_meals]\n");
        return (1);
    }

    t_base *data = malloc(sizeof(t_base));
   
    if (_check_input(ac, av))
        return (1);
    
    if (_fill_structs(data, ac, av))
        return (1);

    if (_launch_threads(data))
        return (1);
}