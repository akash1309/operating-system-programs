#include<unistd.h>
#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>

sem_t rw_mutex,mutex;
int data=0,rcount=0;

void *writer(void *arg)
{

    int *f= (int *)arg;
      sem_wait(&rw_mutex);
       printf("Data written by %d = %d\n",*f,++data);
       sleep(1);
      sem_post(&rw_mutex);

}

void *reader(void *arg)
{

      int *f=(int *)arg;
      sem_wait(&mutex);
      rcount++;
      if(rcount==1)
       {
          sem_wait(&rw_mutex);
       }
      sem_post(&mutex);
      printf("data read by %d : %d \n",*f,data);
      sleep(1);
      sem_wait(&mutex);
      rcount--;
      if(rcount==0)
      {
         sem_post(&rw_mutex);
      }
      sem_post(&mutex);

}
int main()
{
  sem_init(&rw_mutex,0,1);
  sem_init(&mutex,0,1);
  pthread_t w[5],r[5];
  for(int i=0;i<=3;i++)
  {
      pthread_create(&w[i],NULL,writer,&i);
      pthread_create(&r[i],NULL,reader,&i);
  }
  for(int i=0;i<5;i++)
  {
    pthread_join(w[i],NULL);
    pthread_join(r[i],NULL);
  }
}
