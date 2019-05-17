#include<iostream>
#include<pthread.h>
#include<sys/types.h>
#include<unistd.h>
using namespace std;

void *myThreadFun(void *vargp)
{
    sleep(1);
    cout<<"This is thread\n";
    return NULL;
}

int value=0;

int main()
{
    pid_t pid;
    pid=fork();
    if(pid==0)
    {   fork();
        pthread_t thread_id;
        cout<<"Before Thread\n";
        pthread_create(&thread_id, NULL, myThreadFun, NULL);
        cout<<"After Thread\n";
        sleep(5);
    }
    fork();
    cout<<"process id : "<<getpid()<<"\n";
    sleep(5);
    return 0;
}
