#include "ch03.h"
int main(void)
{
	int fd;
	if((fd= open("myoutput",O_WRONLY|O_CREAT,0644)) == -1)
	{
		err_exit("myoutput");
	}
	fclose(stdout);
	int i=dup(fd);
	printf("hello world!");
	sleep(120);
	return 0;
}
