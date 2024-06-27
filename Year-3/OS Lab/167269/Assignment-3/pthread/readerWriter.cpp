#include<iostream>
#include<pthread.h>
#include<unistd.h>

using namespace std;


class monitor
{
	private:
		int rcnt, wcnt, waitr, waitw;
		
		pthread_cond_t canRead, canWrite;
		
		pthread_mutex_t condLock;
	
	public:
		monitor()
		{
			rcnt = 0;
			wcnt = 0;
			waitr = 0;
			waitw = 0;
			
			pthread_cond_init(&canRead, NULL);
			pthread_cond_init(&canWrite, NULL);
			
			pthread_mutex_init(&condLock, NULL);
		}
		
		void beginRead(int i)
		{
			pthread_mutex_lock(&condLock);
			
			if(wcnt == 1 || waitw > 0)
			{
				waitr++;
				pthread_cond_wait(&canRead, &condLock);
				waitr--;
			}
			
			rcnt++;
			
			cout<<"Reader "<<i<<" is reading\n";
			
			pthread_mutex_unlock(&condLock);
			pthread_cond_broadcast(&canRead);
		}
		
		void endRead(int i)
		{
			pthread_mutex_lock(&condLock);
			
			if(--rcnt == 0) pthread_cond_signal(&canWrite);
			
			pthread_mutex_unlock(&condLock);
		}
		
		void beginWrite(int i)
		{
			pthread_mutex_lock(&condLock);
			
			if(wcnt == 1|| rcnt > 0)
			{
				++waitw;
				pthread_cond_wait(&canWrite, &condLock);
				--waitw;
			}
			
			wcnt = 1;
			
			cout<<"Writer "<<i<<" is writing\n";
			
			pthread_mutex_unlock(&condLock);
		}
		
		void endWrite(int i)
		{
			pthread_mutex_lock(&condLock);
			
			wcnt = 0;
			
			cout<<"Writer "<<i<<" finished writing\n";
			
			if(waitr > 0) pthread_cond_signal(&canRead);
			else pthread_cond_signal(&canWrite);
			
			pthread_mutex_unlock(&condLock);
		}
} M;
	
void* reader(void* id)
{
	int c = 0;
	int i = *(int*)id;
	
	while(c < 5)
	{
		usleep(1);
		M.beginRead(i);
		M.endRead(i);
		c++;
	}
}

void* writer(void* id)
{
	int c = 0;
	int i = *(int*)id;
	
	while(c < 5)
	{
		usleep(1);
		M.beginWrite(i);
		M.endWrite(i);
		c++;
	}
}


int main()
{
	pthread_t r[5], w[5];
	
	int id[5];
	
	for(int i = 0; i < 5; i++)
	{
		id[i] = i;
		
		pthread_create(&r[i], NULL, &reader, &id[i]);
		pthread_create(&w[i], NULL, &writer, &id[i]);
	}
	
	for(int i = 0; i < 5; i++) pthread_join(r[i], NULL);
	
	for(int i = 0; i < 5; i++) pthread_join(w[i], NULL);
}
