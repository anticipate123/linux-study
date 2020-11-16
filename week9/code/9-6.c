#include "./ch09.h"
int main(void)
{
	time_t timep;
//	time(&timep);
//	printf("%s\n",ctime(&timep));

	FILE *fp;
	if((fp=fopen("./out.txt","w+"))==NULL)
	{
		perror("open!");
		exit(1);
	}
	pid_t pid,pid2,pid3,pid4,pid5,pid6;
	pid=fork();
        if(pid<0)
        {
                perror("Fork failed!\n");
                exit(-1);
        }
	else if(pid==0)
	{
		wait(NULL);
		pid3=fork();
		if(pid3<0)
		{
			perror("Fork failed!\n");
	                exit(-1);
		}
		else if(pid3==0)
		{
			wait(NULL);
			time(&timep);
	                fprintf(fp,"1-1-1:    %d : %s\n",getpid(),ctime(&timep));
			exit(0);
		}
		else{
			wait(NULL);
			pid4=fork();	
			if(pid4<0)
			{
				 perror("Fork failed!\n");
		                exit(-1);
			}
			else if(pid4==0)
			{
				wait(NULL);
				time(&timep);
        	                fprintf(fp,"1-1-2:   %d : %s\n",getpid(),ctime(&timep));
	                        exit(0);

			}
			else
			{
				wait(NULL);
                	        time(&timep);
        	                fprintf(fp,"1-1:   %d : %s\n",getpid(),ctime(&timep));
	                        exit(0);
			}
		}
	}
	else
	{
		wait(NULL);
		pid2=fork();
		if(pid2<0)
	        {
        	        perror("Fork failed!\n");
               		exit(-1);
        	}
	        else if(pid2==0)
        	{
			wait(NULL);
			pid5=fork();
                	if(pid5<0)
                	{
                       		 perror("Fork failed!\n");
                       		 exit(-1);
	                }
        	        else if(pid5==0)
        	        {
				wait(NULL);
                	        time(&timep);
                        	fprintf(fp,"1-2-1:  %d : %s\n",getpid(),ctime(&timep));
	                        exit(0);
        	        }
               		 else{
				wait(NULL);
                       		pid6=fork();
	                        if(pid6<0)
        	                {
                	                 perror("Fork failed!\n");
                        	        exit(-1);
                       		 }
	                        else if(pid6==0)
        	                {
					wait(NULL);
                	                time(&timep);
                        	        fprintf(fp,"1-2-2:   %d : %s\n",getpid(),ctime(&timep));
                                	exit(0);

                        	}
	                        else
        	                {
                	                wait(NULL);
                        	        time(&timep);
	                               	fprintf(fp,"1-2:   %d : %s\n",getpid(),ctime(&timep));
                                	exit(0);
        	                }
               		 }
		}
		else
		{
			wait(NULL);
			time(&timep);
                        fprintf(fp,"1:   %d : %s\n",getpid(),ctime(&timep));
			exit(0);
		}
	}

}
