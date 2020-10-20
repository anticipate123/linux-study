#include "ch2.h"
int main()
{
	int fd,i;
	char buf[100];
	fd=open("./test.data",O_CREAT|O_WRONLY,0644);
	for(i=0;i<100;i++)
		buf[i]=i;
	printf("process %d:before writing i=%d\nfile description=%d\n",getpid(),i,fd);
	i=write(fd,buf,sizeof(buf));
	printf("after i=%d\n",i);
	sleep(5000);
	return 0;
}
