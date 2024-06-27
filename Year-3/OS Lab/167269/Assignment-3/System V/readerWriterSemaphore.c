#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

int readCount = 0, writeCount = 0, shVar = 5, bsize[5];
sem_t x, y, z, rsem, wsem;
pthread_t r[3], w[2];


void *reader(void *i)
{
	printf("\n-----------------\n\nReader %d is reading", i);
	
	sem_wait(&z);
	sem_wait(&rsem);
	sem_wait(&x);
	
	readCount++;
	
	if(readCount == 1) sem_wait(&wsem);
	
	sem_post(&x);
	sem_post(&rsem);
	sem_post(&z);
	
	printf("\nUpdated value: %d", shVar);
	
	sem_wait(&x);
	
	readCount--;
	
	if(readCount == 0) sem_post(&wsem);
	
	sem_post(&x);
}

void *writer(void *i)
{
	printf("\n\nWriter %d is writing", i);
	
	sem_wait(&y);
	
	writeCount++;
	
	if(writeCount == 1) sem_wait(&rsem);
	
	sem_post(&y);
	sem_wait(&wsem);
	
	shVar += 5;
	
	sem_post(&wsem);
	sem_wait(&y);
	
	writeCount--;
	
	if(writeCount == 0) sem_post(&rsem);
	
	sem_post(&y);
}


int main()
{
	sem_init(&x, 0, 1);
	sem_init(&y, 0, 1);
	sem_init(&z, 0, 1);
	sem_init(&rsem, 0, 1);
	sem_init(&wsem, 0, 1);
	
	pthread_create(&r[0], NULL, (void *)reader, (void *)0);
	pthread_create(&w[0], NULL, (void *)writer, (void *)0);
	pthread_create(&r[1], NULL, (void *)reader, (void *)1);
	pthread_create(&r[2], NULL, (void *)reader, (void *)2);
	pthread_create(&r[3], NULL, (void *)reader, (void *)3);
	pthread_create(&w[1], NULL, (void *)writer, (void *)3);
	pthread_create(&r[4], NULL, (void *)reader, (void *)4);
	
	pthread_join(r[0], NULL);
	pthread_join(w[0], NULL);
	pthread_join(r[1], NULL);
	pthread_join(r[2], NULL);
	pthread_join(r[3], NULL);
	pthread_join(w[1], NULL);
	pthread_join(r[4], NULL);
}
