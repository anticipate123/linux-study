#include "./ch10.h"
int main()
{
	int r1,r2,r3,r21,r22;
	r1=fork();
	if(r1<0)
	{
		perror("Fork failed!\n");
                exit(-1);
	}
	else if(r1==0)
	{
		printf("child 1 :pid= %d,ppid =%d\n",getpid(),getppid());
		exit(0);
	}
	if(r1>0)
	{
		r2=fork();
		if(r2==0)
		{
			r21=fork();
			if(r21==0)
			{
				printf("child 21 :pid= %d,ppid =%d\n",getpid(),getppid());
		                exit(0);
			}
			else if(r21>0)
			{
				r22=fork();
				if(r22==0)
				{
					printf("child 22 :pid= %d,ppid =%d\n",getpid(),getppid());
	                                exit(0);
				}
				else if(r22>0)
				{
					wait(NULL);
					wait(NULL);
					printf("child 2 : pid=%d,ppid =%d,r21=%d,r22=%d\n",getpid(),getppid(),r21,r22);		
					exit(0);				
				}
			}
		}
		else if(r2>0)
		{
			r3=fork();	
			if(r3==0)
                	{
                       		 printf("child 3 : pid=%d,ppid =%d\n",getpid(),getppid());                       exit(0);
                	}
			else if(r3>0)
			{	
				wait(NULL);
				wait(NULL);
				wait(NULL);
				printf("parent : pid =%d ,r1=%d ,r2=%d,r3=%d\n",getpid(),r1,r2,r3);
			}
		}
		return 0;
	}
}
