#include "ch02.h"
int main(void)
{
	FILE * fp;
	fp=fopen("./test.txt","r");
	printf("fd = %d\n",fp->_fileno);
	return 0;
}
