#include "./ch09.h"
char *env_init[]={"USER=stu","PATH=/tmp",NULL};
int main(void)
{
	char *args[]={"./test","hello","world!\n",NULL};
	//if(execve("./test",args,NULL)==-1)
	//if(execve("./test",args,env_init)==-1)
	if(execle("./test","./test","hello","world!\n",NULL,env_init)==-1)
	//if(execlp("./test","./test","hello","world!\n",(char*)0)==-1)
	{
		perror("execve!\n");
		exit(EXIT_FAILURE);
	}
	puts("Never get here!\n");
	exit(EXIT_SUCCESS);
}
