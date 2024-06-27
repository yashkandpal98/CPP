#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *func(int n);

pthread_t arraySplit[4];


int arr[16] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16};
int sum[4] = {0};
int sum2 = 0;

int main()
{
	int x;
	void *msg;
	
	for(int i = 0; i < 4; i++)
	{
		x = pthread_create(&arraySplit[i], NULL ,func, (int *)i);
		
		
		if(x != 0)
		{
			printf("\nThread creation error\n");
			exit(1);
		}
	}
	
	for(int i = 0; i < 4; i++)
	{
		x = pthread_join(arraySplit[i], NULL);
		
		if(x != 0)
		{
			printf("\nThread join error\n");
			exit(1);
		}
	}
	
	for(int i = 0; i < 4; i++)
	{
		printf("Sum for partition %d: ", i+1);
		printf("%d\n", sum[i]);
	}
	
	printf("Total Sum: %d\n", sum2);
	
	return 0;
}


void *func(int n)
{
	int x = n;
	
	for(int i = (4*x); i < 4*(x+1); i++) sum[x] += arr[i];
	
	sum2 += sum[x];
}

