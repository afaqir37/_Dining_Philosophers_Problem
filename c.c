#include <stdio.h>
#include <pthread.h>

void *routine(void *arg)
{
    printf("I entered!\n");
    sleep(4);
    return NULL;
}
int main()
{
    pthread_t t1;

    pthread_create(&t1, NULL, routine, NULL);
    pthread_detach(t1);

    printf("ok\n");
    return 0;
}