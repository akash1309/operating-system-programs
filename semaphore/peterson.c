#include<stdio.h>
#include<pthread.h>

int flag[2];
int turn;


void *peterson(void* x){
	int p=*((int*)&x);
	int q = 1-p;
	while(1){
		flag[p] = 1;
		turn = q;
		while(turn == q && flag[q] == 1){
			printf("process  %d  waiting \n",p);
		}
		
		{	
			printf("process %d executing in cs \n",p);
		}
		
		printf("process  %d  completed execution \n",p);
		flag[p] = 0;
		return NULL;
	}
}


int main()
{
	pthread_t p1, p2;
	pthread_create(&p1, NULL, peterson, (void*)0); 
	pthread_create(&p2, NULL, peterson, (void*)1); 
    pthread_join(p1, NULL); 
    pthread_join(p2, NULL); 
	return 0;
}
