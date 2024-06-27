#include<stdio.h>

int main()
{
	int n, *p, *w, qu, sum = 0;
	
	printf("Enter number of processes: ");
	scanf("%d", &n);
	
	p = (int *)malloc(n*sizeof(int));
	w = (int *)malloc(n*sizeof(int));
	
	for(int i = 0; i < n; i++)
	{
		printf("Burst time for process %d: ", i+1);
		scanf("%d", &p[i]);
	}
	
	printf("Enter time quantum: ");
	scanf("%d", &qu);
	
	sum = 0;
	int ptr = 0, cnt = 0, tmp;
	sum = 0;
	
	while(cnt != n)
	{
		if(p[ptr] == 0)
		{
			cnt++;
			ptr = (ptr+1)%n;
			continue;
		}
		
		if(p[ptr] < qu)
		{
			tmp = qu;
			p[ptr] -= qu;
		}
		else
		{
			tmp = p[ptr];
			p[ptr] = 0;
		}
		
		for(int i = 0; i < n; i++) if( i != ptr && p[i] != 0) w[i] += tmp;
		
		ptr = (ptr+1)%n;
	}
	
	printf("\t\tProcess\t\tWaiting time\n");
	for(int i = 0; i < n; i++)
	{
		printf("\t\t%d\t\t%d\n", i+1, w[i]);
		sum += w[i];
	}
	
	printf("Average waiting time: %d sec\n", sum/n);
	
	return 0;
}
