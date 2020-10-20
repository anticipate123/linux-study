#include "ch03.h"
int main()
{
	int n,fd;
	char buf;
	fd = open("./file.test",O_CREAT|O_RDWR,0644);
	srand(time(0));
	n=rand()%26;
	buf=(char)('A'+n);
	printf("n=%c\n",buf);
	write(fd,&buf,1);
	sleep(50);
	lseek(fd,10,SEEK_SET);
	srand(time(0));
        n=rand()%26; 
        buf=(char)('A'+n);
	write(fd,&buf,1);
	printf("n=%c\n",buf);
	sleep(50);
	return 0;
}
