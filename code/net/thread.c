#include <stdio.h>
#include <sched.h>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
pthread_mutex_t mutex;
void display(char *a)
{
	int i;
	for( i=0;i<10;i++)
	printf("%s\t%d\n",a,i);
}
int pp=90;
void *disp(char *et)
{
	int i=0;
	for( i=0;i<10;i++)
	{	
		pp--;
		if(pp%5==0);
		pthread_mutex_lock(&mutex);
		printf("%s\t%d\t%d\n",et,i,pp);
	       // usleep(1000000);
		pthread_mutex_unlock(&mutex);
	}
}
void *dispe(char *et)
{
	int i=0;
	for( i=0;i<10;i++)
	{
		pthread_mutex_lock(&mutex);
		printf("%s\t%d\t%d\n",et,i,pp);
		pthread_mutex_unlock(&mutex);
		//usleep(10000);
	}
}

int main()
{
	pid_t pid;
//	pid=fork();
	int t=90;
	pthread_t pt1,pt2;
	pthread_mutex_init(&mutex,NULL);    
	/*if(-1==pid){
		printf("fail\n");
		return -1;
	}else if(0==pid){
		//usleep(1000000);
		printf("son    \t%d\t%d\t%d\n\n",pid,getpid(),getppid());
		display("son");
		printf("t = %d\n",t);
		t=100;
		//exit(0);
	}
	else{
		//usleep(100000);
		printf("father \t%d\t%d\t%d\n\n",pid,getpid(),getppid());
		display("father");
		printf("t = %d\n",t);
		exit(0);
	}*/
//	printf("hellow\n");
//	display("gg");
	pthread_create(&pt1,NULL,(void*)disp,"tson");
	pthread_create(&pt2,NULL,(void*)dispe,"tfather");
	printf("hellow\n\n");
	printf("hellow\n\n");
	printf("hellow\n\n");
	printf("hellow\n\n");
	pthread_join(pt1,NULL);
	pthread_join(pt2,NULL);//the main process waiting until thread was completed ,so the program can not  return 0 too early
	pthread_mutex_destroy(&mutex);
	return 0;
}
