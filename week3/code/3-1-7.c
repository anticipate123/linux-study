#include "ch02.h"
#include <stdlib.h>
int main()
{
	FILE *fp;
	char buf[80];
	printf("open and create test_file.\n");
	if((fp=fopen("test_file","w"))==NULL)
	{
		perror("fopen failed!\n");
		exit(1);
	}
	printf("writing string to testfile.\n");
	fputs("test date",fp);
	if((fp=freopen("test_file","r",fp))==NULL)
		perror("freopen failed!\n");
	printf("read string from test_file:\t");
	fgets(buf,sizeof(buf),fp);
	printf("the string is   %s  \n",buf);
	fclose(fp);

	return 0;
}
