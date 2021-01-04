#include "ch14.h"
int main(int argc,char *argv[])
{
	int sockfd,recvbytes;
	char buf[MAXDATASIZE];
	struct hostent *host;
	struct sockaddr_in serv_addr;
	if(argc<2)
	{
		fprintf(stderr,"Please enter the server's hosname!\n");
		exit(1);
	}
	if((host=gethostbyname(argv[1]))==NULL){
	herror("gethostbyname error!");
	exit(1);
	}
	if((sockfd=socket(AF_INET,SOCK_STREAM,0))==-1)
	{
		perror("socket create error! ");
		exit(1);
	}
	printf("111111\n");
	serv_addr.sin_family=AF_INET;
	printf("22\n");
	serv_addr.sin_port=htons(SERVPORT);
	printf("33\n");
	serv_addr.sin_addr=*((struct in_addr *)host->h_addr);
	printf("44\n");
	bzero(&(serv_addr.sin_zero),8);
	printf("3334422\n");
	if(connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(struct sockaddr))==-1 )
	{
		perror("connect error!");
		exit(1);
	}	
	printf("333333\n");
	if((recvbytes=recv(sockfd,buf,MAXDATASIZE,0))==-1)
	{
		perror("connect 出错！");
		exit(1);
	}
	printf("连接成功了\n");
	buf[recvbytes]='\0';
	printf("收到：%s",buf);
	close(sockfd);
}
