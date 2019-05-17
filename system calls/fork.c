#include <sys/types.h>
#include <stdio.h>
int main(){
pid_t pid;
pid = fork();
printf("Fork call 1\n");
pid = fork();
printf("Fork call 2\n");
pid = fork();
printf("Fork call 3\n");
pid = fork();
printf("Fork call 4\n");

    return 0;
}
