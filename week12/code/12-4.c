#include "ch12.h"

int main(void)
{
	int k1,k2;
	int fd1[2],i,fd2[2];
	char buf[100];
        memset(buf,0,sizeof(buf));
	pipe(fd1);
        pipe(fd2);
	k1=fork();
        if(k1<0)
        {
                perror("fork1 error!\n");
                exit(-1);
        }
        else if(k1==0)
        {
		close(fd1[0]);
		close(fd2[1]);
		sprintf(buf,"k1 parent = %d : %d send message!\n",getppid(),getpid());
		write(fd1[1],buf,sizeof(buf));				
		read(fd2[0],buf,sizeof(buf));
		printf("k1 %d receive : %s\n",getpid(), buf);
		exit(0);
	}
	else 
	{
		k2=fork();
		if(k2<0)
		{
			perror("fork2 error!\n");
	                exit(-1);
		}
		else if(k2==0)
		{
			close(fd1[1]);		
			close(fd2[0]);
			//sprintf(buf,"%d say hello \n",getpid());		
			read(fd1[0],buf,sizeof(buf));
			printf("k2 %d receive : %s\n",getpid(),buf);
			sprintf(buf,"k2 parent = %d : %d send message!\n",getppid(),getpid());
			write(fd2[1],buf,sizeof(buf));				
			exit(0);
		}
		else
		{
			close(fd1[0]);
			close(fd1[1]);
			close(fd2[0]);
			close(fd2[1]);
			wait(NULL);
			wait(NULL);	
			exit(0);
		}			
	}
	

}
