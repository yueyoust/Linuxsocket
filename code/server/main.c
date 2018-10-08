#include<stdio.h>
#include<stdlib.h>
#include<strings.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<netinet/in.h>
#include<pthread.h>

int end=0;
void *phend(void)//get the key word to stop program 
{
   printf("son program\n");
   char pp;
   while((pp=getchar())!='e')
   {	
//	printf("\nrsdf\n");
	printf("%c",pp);
   }	
	putchar('\n');
	putchar('\n');
	putchar('\n');
	putchar('\n');
   end=-1;
}
int main(int argc,char *argv[])
{
	if(argc==1){
		printf("parameter input is less than it needs\n");
		return 0;
	}
        int count=1;
	for(;count<4;count++){
		argv[count][0]-='0';
		printf("%d\t",argv[count][0]);
	}
	putchar('\n');
	int ss;
	struct sockaddr_in ser,client;
	ss=socket(AF_INET,SOCK_STREAM,0);
	if(ss<0){
		printf("socket error...\n");
		return 0;
	}else printf("socket initiate successfully...\n");
	ser.sin_family=AF_INET;
	ser.sin_addr.s_addr=htonl(INADDR_ANY);
	ser.sin_port=htons(8000);
	int err;
	err=bind(ss,(struct sockaddr*)&ser,sizeof(ser));
	if(err<0){
		printf("socket bind error...\n");
		return -1;
	}else printf("socket bind successfully...\n");
	err=listen(ss,5);
	if(err<0){
		printf("socket listen error...\n");
		return -1;
	}else printf("socket is listening...\n"); 
	int sc;
	char buffer[2];
	pthread_t pt;
	pthread_create(&pt,NULL,(void*)phend,NULL);
	for (;;){
		socklen_t addrlen=sizeof(struct sockaddr);
		sc=accept(ss,(struct sockaddr*)&client,&addrlen);
		if(sc<0){
			printf("no requirement was asking...\n");
		}
		else
                {
		while(1){
			while(1){
			 read(sc, buffer,1);
			 printf("%s",buffer);
			 if(*buffer=='\n')break;
                        }
                        if(end==-1)
			return 0;
		     }
		}
		
	}
	return 0;
}
