#include<ucontext.h>
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include "gtthread.h"
#include<sys/time.h>
#include<malloc.h>
#include<signal.h>

ucontext_t maincontext;
int cancel_current = 0, total_thr_count = 0;
queue ready_q, finish_q;
gtthread_t main_t;
gtthread_t *current;
long period_t;

struct itimerval timer;


void start_time()
{
	setitimer(ITIMER_VIRTUAL, &timer, 0);
}

void stop_time()
{
	setitimer(ITIMER_VIRTUAL, 0, 0);
}

void queue_init(queue *que)
{
	que->front = que->rear = NULL;
	que->count = 0;
}

int enqueue(queue *que, gtthread_t *thread)
{
	node *temp = (node *) malloc(sizeof(node));
	
	if(temp == NULL) return 0;
	
	temp->data = thread;
	temp->next = NULL;
	
	if(que->rear)
	{
		que->rear->next = temp;
		que->rear = temp;
	}
	else
	{
		que->rear = temp;
		que->front = temp;
	}
	
	++(que->count);

	return 1;
}

gtthread_t * dequeue(queue *que)
{
	if(que->front == NULL) return 0;
	
	node *temp = (node *) malloc(sizeof(node));
	
	temp = que->front;
	que->front = que->front->next;
	
	gtthread_t *ret = NULL;
	
	ret = temp->data;
	free(temp);
	--(que->count);
	return ret;
}

int que_size(queue *que)
{
	return que->count;
}

int remove_q_ele(queue *que, gtthread_t *thread)
{
	node *curr = que->front;
	node *prev = NULL;
	
	if(curr == NULL) return 0;
	
	if(que->count <= 0) return 0;
	
	while(curr)
	{
		if(curr->data->id == thread->id)
		{
			if(prev == NULL) que->front = curr->next;
			else prev->next = curr->next;
			
			if(curr == que->rear) que->rear = prev;
		
			free(curr);
		
			--(que->count);
			return 1;
		}
		
		prev =  curr;
		curr = curr->next;
	}
	
	return 0;
}

gtthread_t *get_q_ele(queue *que, int num)
{
	node *temp = que->front;
	
	print_queue(que);
	
	if(que->count <= 0) return 0;
	
	int i = 0;
	gtthread_t *data = 0;
	
	while(temp)
	{
		if(i == num)
		{
			data = temp->data;
			return data;
		}
		temp = temp->next;
		++i;
	}
	
	return 0;
}

void print_queue(queue *que)
{
	node *temp = que->front;
	
	if(temp == NULL) return;
	
	while(temp) temp = temp->next;
}

void scheduler()
{
	gtthread_t *prev, *next = NULL;
	
	stop_time();
	
	if(getcontext(&maincontext) == -1)
	{
		printf("Error while getting context\n");
		exit(EXIT_FAILURE);
	}
	
	prev = current;
	
	if(!cancel_current)
	{
		enqueue(&ready_q, prev);
		print_queue(&ready_q);
	}
	else cancel_current = 0;
	
	next = dequeue(&ready_q);
	
	if(next == NULL)
	{
		printf("No thread present int ready queue\n");
		exit(EXIT_SUCCESS);
	}
	
	current = next;
	
	start_time();
	
	if(swapcontext(&(prev->uc), &(next->uc)) == -1) printf("Error while swapping context\n");
}

gtthread_t gtthread_self()
{
	return *current;
}

void thread_run(void *(*start_routine)(void *), void *arg)
{
	gtthread_exit(start_routine(arg));
	return;
}

int gtthread_create(gtthread_t *thread, void *(*start_routine)(void *), void *arg)
{
	thread->id = que_size(&ready_q);
	
	if(getcontext(&(thread->uc)) == -1)
	{
		printf("Error while getting context\n");
		exit(EXIT_FAILURE);
	}
	
	thread->uc.uc_link = &maincontext;
	thread->uc.uc_stack.ss_sp = malloc(SIGSTKSZ);
	thread->uc.uc_stack.ss_size = SIGSTKSZ;
	
	makecontext(&(thread->uc), (void (*) ()) thread_run, 2, start_routine, arg);
	enqueue(&ready_q, thread);
	
	return 0;
}

void gtthread_init(long period)
{
	queue_init(&ready_q);
	queue_init(&finish_q);
	
	timer.it_value.tv_sec = period/1000000;
	timer.it_value.tv_usec = period;
	timer.it_interval.tv_sec = period/1000000;
	timer.it_interval.tv_usec = period;
	
	start_time();
	
	signal(SIGVTALRM, scheduler);
	
	main_t.id = -1;
	
	if(getcontext(&(main_t.uc)) == -1)
	{
		printf("Error while getting context\n");
		exit(EXIT_FAILURE);
	}
	
	current = &main_t;
}

int gtthread_join(gtthread_t thread, void **status)
{
	int found = 0;
	gtthread_t *thr;
	int i;
	
	for(i = 0; i < que_size(&ready_q); i++)
	{
		thr = get_q_ele(&ready_q, i);
		
		if(gtthread_equal(*thr, thread))
		{
			if(!remove_q_ele(&ready_q, thr)) return 1;
			else
			{
				found = 1;
				break;
			}
		}
	}
	
	if(gtthread_equal(thread, gtthread_self()))
	{
		cancel_current = 1;
		scheduler();
		return 0;
	}
	
	if(!found) return 1;
	
	return 0;
}

int gtthread_cancel(gtthread_t thread)
{
	int found = 0;
	gtthread_t *thr;
	int i;
	
	for(i = 0; i < que_size(&ready_q); ++i)
	{
		thr = get_q_ele(&ready_q, i);
		if(gtthread_equal(*thr, thread))
		{
			if(!remove_q_ele(&ready_q, thr)) return 1;
			else
			{
				found = 1;
				return 0;
			}
		}
	}
	
	if(gtthread_equal(thread, gtthread_self()))
	{
		cancel_current = 1;
		scheduler();
		return 0;
	}
	
	if(!found) return 1;
	
	return 0;
}

void gtthread_exit(void *retval)
{
	current->retval = retval;
	enqueue(&finish_q, current);
	print_queue(&finish_q);
	gtthread_cancel(gtthread_self());
}

int gtthread_yield()
{
	stop_time();
	start_time();
	scheduler();
	return 0;
}

int gtthread_equal(gtthread_t t1, gtthread_t t2)
{
	return t1.id == t2.id;
}

int gtthread_mutex_init(gtthread_mutex_t *mutex)
{
	mutex->lock = 0;
	return 0;
}

int gtthread_mutex_lock(gtthread_mutex_t *mutex)
{
	stop_time();
	
	while(mutex->lock == 1)
	{
		start_time();
		gtthread_yield();
		stop_time();
	}
	
	mutex->lock = 1;
	
	start_time();
	
	return 0;
}

int gtthread_mutex_unlock(gtthread_mutex_t *mutex)
{
	mutex->lock = 0;
	return 0;
}
