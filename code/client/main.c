#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<unistd.h>
#include<arpa/inet.h>
int main()
{
	int ss;
	char buffer[]="hellow world\nnjgfgn";
	char pointer=0;
	struct sockaddr_in ser;
	ss=socket(AF_INET,SOCK_STREAM,0);
	if(ss<0){
		printf("socket error\n");
		return -1;
	}
	ser.sin_family=AF_INET;
	ser.sin_addr.s_addr=htonl(INADDR_ANY);
	ser.sin_port=htons(8000);
	connect(ss,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	
	while(1){
        	while((buffer[pointer++]=getchar())!='\n');
		//buffer[pointer++]='\n';
		write(ss,buffer,pointer);
		pointer=0;
	} 
}
