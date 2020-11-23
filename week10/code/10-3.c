#include "./ch10.h"
int main()
{
	//char *argv[]={"./test","hello","world",NULL};
	int i;
	printf("10-2: pid=%d , ppid=%d\n",getpid(),getppid());
	//i=execve("./test",argv,NULL);
	i=execle("./test","hello","world",NULL,NULL);
	if(i==-1)
	{
		perror("execve failed!\n");
		exit(-1);
	}
	printf("after calling\n");
	return 0;
}
