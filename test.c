#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_fn(void *arg)
{
	long id = (long)arg;
	printf("Starting thread %ld\n",id );
	sleep(0);
	printf("Closing thread %ld\n",id );
	return NULL;
}

int main()
{
	pthread_t t1,t2;
	printf("%d %d\n",t1,t2 );
	pthread_create(&t1,NULL,thread_fn,(void *)1);
	pthread_create(&t2,NULL,thread_fn,(void *)2);
	printf("%d %d thread id created.\n",t1,t2 );
	pthread_join(t2,NULL);
	pthread_join(t1,NULL);
	printf("Exiting main\a\n");
	return(0);
}
