#ifndef __GTTHREAD_H
#define __GTTHREAD_H

#include<ucontext.h>


typedef struct 
{
	int id;
	ucontext_t uc;
	void  *retval;
} gtthread_t;

typedef struct node
{
	struct node *next;
	gtthread_t *data;
} node;

typedef struct queue
{
	node *front;
	node *rear;
	int count;
} queue;

typedef struct
{
	int lock;
} gtthread_mutex_t;


void queue_init(queue *que);
int que_size(queue *que);
int enqueue(queue *que, gtthread_t *thread);
gtthread_t * dequeue(queue *que);
int remove_q_ele(queue *que, gtthread_t *thread);
gtthread_t get_element_from_queue(queue *que, int num);

void gtthread_init(long period);
int gtthread_create(gtthread_t *thread, void *(*start_routine)(void *), void *arg);
int gtthread_join(gtthread_t thread, void **status);
void gtthread_exit(void *retval);
int gtthread_yield(void);
int gtthread_equal(gtthread_t t1, gtthread_t t2);
int gtthread_cancel(gtthread_t thread);
gtthread_t gtthread_self(void);

int gtthread_mutex_init(gtthread_mutex_t *mutex);
int gtthread_mutex_lock(gtthread_mutex_t *mutex);
int gtthread_mutex_unlock(gtthread_mutex_t *mutex);


#endif
