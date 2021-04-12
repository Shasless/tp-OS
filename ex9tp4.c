#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void *runner(void *param){
	pid_t idProcess = getpid();
	printf("I live, and my id is %d \n",idProcess);
	pthread_exit(0);
}
int main(int argc, char *argv[]){
	int nbr_thread = atoi(argv[1]);

	pthread_t thread[nbr_thread];
	for(int i = 0; i< nbr_thread; i++){
		pthread_create(&thread[i], NULL, runner, NULL);
	
		pthread_join(thread[i],NULL);
	}

	return 0;
}
