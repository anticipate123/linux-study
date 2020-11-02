#include "ch05.h"
int main(void)
{

//	setvbuf(stdout,NULL,_IONBF,0);
	printf("hello!");
/*	int i;
	for(i=0;i<1025;i++)
	{
		printf(" ");
	}*/
	fclose(stdout);
//	fflush(stdout);
	while(1);
	return 0;
}
