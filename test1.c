#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_fn(void *arg)
{
	long id = (long)arg;
	printf("Starting thread %ld\n",id );
	sleep(5);
	printf("Closing thread %ld\n",id );
	return (void *)&id;
}

int main()
{
	pthread_t t1,t2;

	pthread_create(&t1,NULL,thread_fn,(void *)1);
	pthread_create(&t2,NULL,thread_fn,(void *)2);
	printf("%d %d thread id created.\n",t1,t2 );
	long* id1,id2;
	pthread_join(t1,(void **)&id1);
	pthread_join(t2,(void **)&id2);
	printf("Exiting main\n");
	return(0);
}
