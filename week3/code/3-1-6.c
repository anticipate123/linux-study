#include "ch02.h"
int main(void)
{
	FILE *fp=fdopen(3,"w+");
	fprintf(fp,"%s\n","hello!");
	fclose(fp);
	return 0;
}
