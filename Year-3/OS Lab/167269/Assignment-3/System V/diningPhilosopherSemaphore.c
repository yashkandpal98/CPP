#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

#define n 5
#define thinking 2
#define hungry 1
#define eating 0
#define left (phnum+4)%n
#define right (phnum+1)%n

int state[n];
int phil[n] = {0, 1, 2, 3, 4};

sem_t mutex;
sem_t s[n];


void test(int phnum)
{
	if(state[phnum] == hungry && state[left] != eating && state[right] != eating)
	{
		state[phnum] = eating;
		sleep(2);
		
		printf("Philosopher %d is picking up forks\n", phnum+1);
		printf("Philosopher %d is eating\n", phnum+1);
		
		sem_post(&s[phnum]);
	}
}

void takeFork(int phnum)
{
	sem_wait(&mutex);
	
	state[phnum] = hungry;
	
	printf("Philosopher %d is hungry\n", phnum+1);
	
	test(phnum);
	
	sem_post(&mutex);
	
	sem_wait(&s[phnum]);
	
	sleep(1);
}

void putFork(int phnum)
{
	sem_wait(&mutex);
	
	state[phnum] = thinking;
	
	printf("Philosopher %d is putting down forks\n", phnum+1);
	printf("Philosopher %d is thinking\n", phnum+1);
	
	test(left);
	test(right);
	
	sem_post(&mutex);
}

void* philosopher(void*num)
{
	int x = 0;
	while(x++ != 2)
	{
		int* i = num;
		
		sleep(1);
		
		takeFork(*i);
		putFork(*i);
	}
}


int main()
{
	int i;
	pthread_t thread_id[n];
	
	sem_init(&mutex, 0, 1);
	
	for(i = 0; i < n; i++) sem_init(&s[i], 0, 0);
	
	for(i = 0; i < n; i++)
	{
		pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
		printf("Philosopher %d is thinking\n", i+1);
	}
	
	for(i = 0; i < n; i++) pthread_join(thread_id[i], NULL);
}
