#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#define BUFFER_SIZE 10

sem_t empty,full;
sem_t mutex;
int data=0;
int size[BUFFER_SIZE];
int index=0;

void *produce(void *arg)
{   while(1)
   {
      sem_wait(&empty);
      sem_wait(&mutex);
       printf("Item Produced %d \n",data);
       size[index++]=data++ ;

       sleep(1);
      sem_post(&mutex);
      sem_post(&full);
   }
}

void *consume(void *arg)
{   while(1)
   {
    sem_wait(&full);
    sem_wait(&mutex);
     printf("Item consumed %d \n",size[--index]);
     sleep(1);
    sem_post(&mutex);
    sem_post(&empty);
    }
}
int main()
{
   sem_init(&mutex,0,1);
   sem_init(&empty,0,BUFFER_SIZE);
   sem_init(&full,0,0);
   pthread_t producer,consumer;
   int i=0;
   for(int j=0;j<5;j++)
   {
   pthread_create(&producer,NULL,produce,&i);
   pthread_create(&consumer,NULL,consume,&i);
   }
   pthread_join(producer,NULL);
   pthread_join(consumer,NULL);
}
