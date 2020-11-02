#include "ch05.h"
int main(int argc, char *argv[],char *env[])
{
	int i;
/*	if(argc!=3)
	{
		err_exit("argc!");
	}
	for(i=0;i<argc;i++)
	{
		printf("argv[%d]= %s\n",i,argv[i]);
	}
	int sum=atoi(argv[1])+atoi(argv[2]);
	printf("sum=%d\n",sum);*/
	for(i=0;i<argc;i++)
        {
                printf("argv[%d]= %s\n",i,argv[i]);
        }
	for(i=0;env[i];i++)
	{
		printf("env[%d]= %s\n",i,env[i]);	
	}	
	
	return 0;
}
