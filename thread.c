#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int count = 0;
void *routine(void *arg)
{
	int i = 0;
	while(i < 10)
	{
		printf("this is thread number %ld\n", pthread_self());
		count++;
		printf("%d\n", count);
		//sleep(1);
		i++;
	}
	return NULL;

}

int main()
{
	pthread_t tid;
	pthread_t tid2;

	pthread_create(&tid, NULL, routine, NULL);
	pthread_create(&tid2, NULL, routine, NULL);
	
	pthread_join(tid, NULL);
	pthread_join(tid2, NULL);
	


}
