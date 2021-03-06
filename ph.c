#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t philosopher[5];
pthread_mutex_t chopstick[5];

void *func(int n){
	printf("Philosopher %d is thinking\n",n);
	
	pthread_mutex_lock(&chopstick[n]);
	pthread_mutex_lock(&chopstick[(n+1)%5]);
	
	printf("Philosopher %d is eating\n",n);
	sleep(3);
	
	pthread_mutex_unlock(&chopstick[n]);
	pthread_mutex_unlock(&chopstick[(n+1)%5]);
	
	printf("Philosopher %d is finished eating\n",n);
	return (NULL);
}

int main(){
	system("clear");
	int i;
	for(i=0;i<5;i++)
		pthread_mutex_init(&chopstick[i],NULL);
	for(i=0;i<5;i++)
		pthread_create(&philosopher[i],NULL,(void *)func,(void *)i);
	for(i=0;i<5;i++)
		pthread_join(philosopher[i],NULL);
	for(i=0;i<5;i++)
		pthread_mutex_destroy(&chopstick[i]);
	return 0;
}
