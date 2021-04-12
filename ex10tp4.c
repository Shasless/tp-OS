#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

struct arg_nbr{
	int a;
	int b;
	int r;
};

void *runner(void *arguments){
	struct arg_nbr *args = arguments; Add files via upload 
	int a= args -> a;
	int b =args -> b;
	int c=0;
	for(int i = 0; a<b;i++)
	{
		c+=a+b;
		a++;
		b--;
	}
	if(a==b){
		c+=a;
	}
	args->r=c;
	pthread_exit(0);
}



int main(){
	int nbr;
	int nbr2;
	int d;
	int result =0;
	printf("???? :");
	scanf("%d",&nbr);

	printf("\n How many thread? :");
	scanf("%d",&nbr2);


	if(nbr2>nbr || nbr%nbr2 !=0){
		printf("ERROR you cant have more thread than the number and the number of thread must be a divider ");
		return 0;
	}
	
	d = nbr/nbr2;

	pthread_t thread;

	struct arg_nbr args[nbr2+2];

	for(int i =1 ; i<nbr2+1;i++){

		args[i].a =1+ d*(i-1);
		args[i].b =d*i;
		pthread_create(&thread, NULL, runner, (void*)&args[i]);
		pthread_join(thread, NULL);
		result+= args[i].r;	
	}

	printf("%d",result);
	return 0;
}
