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
			int i;
			for(i=0;i<9;i++)
			{
				printf("%d : Hello!\n",i);
			}
			exit(0);
		}
		else
		{
			int s1,r1,s2,r2;
		//	r1=waitpid(pid1,&s1,0);
		//	r2=waitpid(pid2,&s2,0);
			r1=wait(&s1);
			r2=wait(&s2);
			if(r1==pid1)
                        {
                                printf("child 1 %d is exited! exit code %d\n",r1,WEXITSTATUS(s1));
                        }
                        else if(r1==pid2)
                        {
                                printf("child 2 %d is exited! exit code %d\n",r1,WEXITSTATUS(s1));
                        }
			if(r2==pid1)
                        {
                                printf("child 1 %d is exited! exit code %d\n",r2,WEXITSTATUS(s2));
                        }
                        else if(r2==pid2)
                        {
                                printf("child 2 %d is exited! exit code %d\n",r2,WEXITSTATUS(s2));
                        }
/*
 	                if(WEXITSTATUS(s))
        	        {
                	        printf("exit code =%d,wait pid=%d\n",WEXITSTATUS(s),r);
               		}
	                else{
        	        	        //printf("child process stopped unnormaly!\n",);
                                        printf("child process stopped with signal %d\n!",WTERMSIG(s));
                        }
*/
                      	return 0;
		}
	}
}
