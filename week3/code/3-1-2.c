#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(void)
{
	FILE *fp=fopen("./ftest.txt","w");
//	printf("file descriptor = %d \n",fd);
	fclose(fp);
	return 0;
}
