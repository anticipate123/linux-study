#include "ch05.h"
int main(void)
{
	int i;
	extern char **environ;
	printf("%s\n",getenv("PATH"));
	for(i=0;environ[i]!=NULL;i++)
	{
		printf("evn[%d]: %s\n",i,environ[i]);
	}
	return 0;
}
