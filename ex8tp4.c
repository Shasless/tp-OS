#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

void *runner(void *param){
	int nb;
	scanf("%d",&nb);
	printf("your number: %d \n",nb);
	nb +=1;
	printf("your number  +1 : %d",nb);
	pthread_exit(0);}

int main(){
	pthread_t thread;
	void *pte;
	pthread_create(&thread, NULL, runner, NULL);
	pthread_join(thread,pte);
	return 0;
}
