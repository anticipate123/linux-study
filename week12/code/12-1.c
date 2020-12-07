#include "ch12.h"

int main(void)
{

	int fd1[2],i;
	int fd2[2];
	char buf[100];
	memset(buf,0,sizeof(buf));
	pid_t k;
	pipe(fd1);
	pipe(fd2);
	k=fork();
	if(k<0)
	{
		perror("fork error!\n");
		exit(-1);
	}
	else if(k==0)
	{
		close(fd1[1]);
		close(fd2[0]);
		sleep(1);
		i=read(fd1[0],buf,sizeof(buf));
		if(i==0)
		{
			printf("child read failed!\n");
			exit(0);
		}
		else
		{
			fprintf(stdout,"read from pipe : %s  strlen =%d,i=%d\n",buf,strlen(buf),i);
			sprintf(buf,"receive from parent %d byte!\n",strlen(buf));
	//		printf("%s\n",buf);
			/*if(write(fd2[1],buf,sizeof(buf))<=0)
			{
				perror("child write error!\n");
			}
			else
			{
				printf("child write success!\n");
			}*/
			exit(1);
		}
		
	}
	else
	{
		close(fd1[0]);		
		close(fd2[1]);
		sprintf(buf,"%d say hello to %d!\n",getpid(),k);
		i=write(fd1[1],buf,strlen(buf));
		if(i==0)
		{
			printf("parent write failed!\n");
		}
		else
		{
			printf("write to pipe : %s\n",buf);	
		}
		wait(NULL);
		exit(0);	
	}
}
