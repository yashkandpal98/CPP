#include<stdio.h>

int main()
{
	 int n, *p, *w, *re, sum = 0;
	 
	printf("Enter number of processes: ");
	scanf("%d", &n);
	
	p = (int *)malloc(n*sizeof(int));
	w = (int *)malloc(n*sizeof(int));
	re = (int *)malloc(n*sizeof(int));
	
	for(int i = 0; i < n; i++)
	{
		printf("Burst time for process %d: ", i+1);
		scanf("%d", &p[i]);
		re[i] = i;
	}
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n-1; j++)
		{
			if(p[j] > p[j+1])
			{
				p[j] += p[j+1];
				p[j+1] = p[j] - p[j+1];
				p[j] -= p[j+1];
			}
		}
	}
	
	for(int i = 0; i < n; i++)
	{
		w[i] != sum;
		sum += p[i];
	}
	
	printf("\t\tProcess\t\tWaiting time\n");
	sum = 0;
	int cnt = 0;
	
	while(cnt != n)
	{
		for(int i = 0; i < n; i++)
		{
			if(cnt == re[i])
			{
				printf("\t\t%d\t\t%d\n", cnt+1, w[i]);
				sum += w[i];
				cnt++;
			}
		}
	}
	
	printf("Average waiting time: %d sec\n", sum/n);
	
	return 0;
}
