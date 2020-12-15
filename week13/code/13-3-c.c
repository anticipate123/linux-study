#include "ch13.h"
int main(void)
{
	int server_fifo_fd,client_fifo_fd;
	struct data_to_pass my_request;
	char client_fifo_name[256];
	pid_t mypid;
	
	server_fifo_fd=open(SERVER_FIFO_NAME,O_WRONLY);
	if(server_fifo_fd==-1)
	{
		err_exit("Sorry, no server");
	}
	
	mypid=getpid();
	sprintf(client_fifo_name,CLIENT_FIFO_NAME,mypid);
	if(mkfifo(client_fifo_name,0777)==-1)
		err_exit(client_fifo_name);
	
	while(1)
	{
		printf("Enter yuur request:");
		fgets(my_request.data,BUFFER_SIZE,stdin);
		if(strcmp(my_request.data,"bye\n")==0
			||strcmp(my_request.data,"BYE\n")==0)
			break;
		my_request.client_pid=mypid;
		write(server_fifo_fd,&my_request,sizeof(my_request));

		client_fifo_fd=open(client_fifo_name,O_RDONLY);
		if(client_fifo_fd!=-1)
		{
			if(read(client_fifo_fd,&my_request,sizeof(my_request))>0)
			{	
				printf("----I get answer: %s\n",my_request.data);

			}	
			close(client_fifo_fd);
		}

	}
	close(server_fifo_fd);
//	unlink(CLIENT_FIFO_NAME);
	unlink(client_fifo_name);	
	exit(EXIT_SUCCESS);
}
