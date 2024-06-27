#include<stdio.h>
#include "gtthread.h"

gtthread_mutex_t m1, m2, m3, m4, m5;
gtthread_t t1, t2, t3, t4, t5;


void* philosopher(int n)
{
	printf("Philosopher %d begins\n",  n);
	
	while(1)
	{
		if(n == 1)
		{
			printf("Philosopher 1 is hungry\n");
			printf("Philosopher 1 tries to acquire fork 1\n");
			gtthread_mutex_lock(&m1);
			printf("Philosopher 1 tries to acquire fork 5\n");
			gtthread_mutex_lock(&m5);
			printf("Philosopher 1 is eating\n");
			gtthread_yield();
			sleep(2);
			gtthread_mutex_unlock(&m1);
			printf("Philosopher 1 releases fork 1\n");
			gtthread_mutex_unlock(&m5);
			printf("Philosopher 1 releases fork 5\n");
			printf("Philosopher 1 is resting\n");
			gtthread_yield();
			sleep(2);
		}
		if(n == 2)
		{
			printf("Philosopher 2 is hungry\n");
			printf("Philosopher 2 tries to acquire fork 2\n");
			gtthread_mutex_lock(&m2);
			printf("Philosopher 1 tries to acquire fork 1\n");
			gtthread_mutex_lock(&m1);
			printf("Philosopher 2 is eating\n");
			gtthread_yield();
			sleep(2);
			gtthread_mutex_unlock(&m2);
			printf("Philosopher 2 releases fork 2\n");
			gtthread_mutex_unlock(&m1);
			printf("Philosopher 2 releases fork 1\n");
			printf("Philosopher 2 is resting\n");
			gtthread_yield();
			sleep(2);
		}
		if(n == 3)
		{
			printf("Philosopher 3 is hungry\n");
			printf("Philosopher 3 tries to acquire fork 3\n");
			gtthread_mutex_lock(&m3);
			printf("Philosopher 3 tries to acquire fork 2\n");
			gtthread_mutex_lock(&m2);
			printf("Philosopher 3 is eating\n");
			gtthread_yield();
			sleep(2);
			gtthread_mutex_unlock(&m3);
			printf("Philosopher 3 releases fork 3\n");
			gtthread_mutex_unlock(&m2);
			printf("Philosopher 3 releases fork 2\n");
			printf("Philosopher 3 is resting\n");
			gtthread_yield();
			sleep(2);
		}
		if(n == 4)
		{
			printf("Philosopher 4 is hungry\n");
			printf("Philosopher 4 tries to acquire fork 4\n");
			gtthread_mutex_lock(&m4);
			printf("Philosopher 4 tries to acquire fork 3\n");
			gtthread_mutex_lock(&m3);
			printf("Philosopher 4 is eating\n");
			gtthread_yield();
			sleep(2);
			gtthread_mutex_unlock(&m4);
			printf("Philosopher 4 releases fork 4\n");
			gtthread_mutex_unlock(&m3);
			printf("Philosopher 4 releases fork 3\n");
			printf("Philosopher 4 is resting\n");
			gtthread_yield();
			sleep(2);
		}
		if(n == 5)
		{
			printf("Philosopher 5 is hungry\n");
			printf("Philosopher 5 tries to acquire fork 5\n");
			gtthread_mutex_lock(&m5);
			printf("Philosopher 5 tries to acquire fork 4\n");
			gtthread_mutex_lock(&m4);
			printf("Philosopher 5 is eating\n");
			gtthread_yield();
			sleep(2);
			gtthread_mutex_unlock(&m5);
			printf("Philosopher 5 releases fork 5\n");
			gtthread_mutex_unlock(&m4);
			printf("Philosopher 5 releases fork 4\n");
			printf("Philosopher 5 is resting\n");
			gtthread_yield();
			sleep(2);
		}
	}
	
	return (void *)0;
}


void main()
{
	gtthread_init(10);
	
	gtthread_mutex_init(&m1);
	gtthread_mutex_init(&m2);
	gtthread_mutex_init(&m3);
	gtthread_mutex_init(&m4);
	gtthread_mutex_init(&m5);
	
	gtthread_create(&t1, philosopher, (void *)1);
	gtthread_create(&t2, philosopher, (void *)2);
	gtthread_create(&t3, philosopher, (void *)3);
	gtthread_create(&t4, philosopher, (void *)4);
	gtthread_create(&t5, philosopher, (void *)5);
	
	while(1);
	gtthread_exit(NULL);
}
