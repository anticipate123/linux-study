#include "ch12.h"
int main(void)
{
	int pid,fd[2],len;
	char buffer[100];
	FILE *stream;
	if(pipe(fd)!=0)
	{
		err_exit("pipe");
	}
	if((pid=fork())==0)
	{
		close(fd[1]);
		dup2(fd[0],0);
		close(fd[0]);
		if(execl("/bin/cat","cat",NULL,NULL)==-1)
		{
			err_exit("Unable to run cat");
		}
	}
	else
	{
		close(fd[0]);			
		printf("you can type a line and the line will echoed:\n");
		dup2(fd[1],1);
		close(fd[1]);
		while(gets(buffer)!=NULL)
		{
			puts(buffer);
		}
	}
}
