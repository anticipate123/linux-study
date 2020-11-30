#include "./ch11.h"
int main()
{
	pid_t pid1;
	pid1=fork();
	if(pid1<0)
	{
		perror("fork failed!\n");
		exit(-1);
	}
	else if(pid1==0)
	{
		char *argv[]={"./test","hello",NULL};
		printf("child1 : pid = %d ,ppid =%d ,re = %d\n",getpid(),getppid(),pid1);
		execve("./test",argv,NULL);
		exit(99);
	}
	else if(pid1>0)
	{
		pid_t pid2;
		pid2=fork();
		if(pid2<0)
		{
			perror("fork failed!\n");
	                exit(-1);
		}
		else if(pid2==0)
		{
			printf("child2 : pid = %d ,ppid =%d ,re = %d\n",getpid(),getppid(),pid2);
			int i=0;
			while(1);
			exit(0);
		}
		else
		{
			int s1,r1,s2,r2;
			r1=waitpid(pid1,&s1,0);
			r2=waitpid(pid2,&s2,WNOHANG);
/*			if(r1==pid1)
                        {
                                printf("child 1 %d is exited! exit code %d\n",r1,WEXITSTATUS(s1));
                        }
                        else
                        {
                                printf("child 1 %d is exited abnormally !  exit code %d\n",r1,WIFSIGNALED(s1));
                        }
			if(r2==pid2)
                        {
                                printf("child 2 %d is exited! exit code %d\n",r2,WEXITSTATUS(s2));
                        }
                        else if(r2==0)
                        {
                                printf("child 2 %d is exited abnormally ! exit code %d\n",r2,WIFSIGNALED(s2));
                        }
*/


 	                if(WIFEXITED(&s1))
        	        {
                	        printf("child 1 exit nomaly! exit code %d\n",WIFEXITED(&s1));
               		}
	                else{
				printf("child 1 exit abnomaly! exit with signal %d\n",WTERMSIG(&s1));
                        }
			if(WIFEXITED(&s2))
			{
				
                                printf("child 2 exit nomaly! exit code %d\n",WIFEXITED(&s2));
                        }
                        else{
                                printf("child 2 exit abnomaly! exit with signal %d\n",WTERMSIG(&s2));
                        }
			
			printf("parent ended!\n");
                      	return 0;
		}
	}
}
