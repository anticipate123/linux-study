#include "./ch10.h"
int main()
{
	pid_t pid;
	pid=fork();
	if(pid<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else if(pid==0)
	{
		char *argv[]={"./test","hello",NULL};
		printf("child : pid = %d ,ppid =%d ,re = %d\n",getpid(),getppid(),pid);
		execve("./test",argv,NULL);
		exit(99);
	}
	else if(pid>0)
	{
		int s,r;
		r=wait(&s);
		printf("exit code =%d,wait pid=%d\n",WEXITSTATUS(s),r);
		return 0;
	}
}
