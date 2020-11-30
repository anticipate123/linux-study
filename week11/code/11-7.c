#include "./ch11.h"

void prtinfo(pid_t pid,FILE * fp){
	time_t timep;
	time(&timep);
        printf("--pid: %d exited time: %s\n",pid,ctime(&timep));		
        fprintf(fp,"pid: %d exited time: %s\n",pid,ctime(&timep));		
}

int main()
{
	FILE *fp;
        if((fp=fopen("./log.dat","w+"))==NULL)
        {
                perror("open!");
                exit(1);
        }
	int r1,r2,r11,r21;
	r1=fork();
	
	if(r1<0)
	{
		perror("Fork failed!\n");
                exit(-1);
	}
	else if(r1==0)
	{
		r11=fork();
		if(r11<0)
		{
			perror("Fork failed!\n");
	                exit(-1);
		}
		else if(r11==0)
		{
			printf("child 11 :pid= %d,ppid =%d\n",getpid(),getppid());	
			exit(0);
		}
		else
		{
			int rr=wait(NULL);
			prtinfo(rr,fp);
			printf("child 1 :pid= %d,ppid =%d\n",getpid(),getppid());	
			exit(0);
		}
	}
	else
	{
		r2=fork();
		if(r2<0)
		{
			perror("Fork failed!\n");
	                exit(-1);
		}
		else if(r2==0)
		{	
			r21=fork();
			if(r21<0)
			{
				perror("Fork failed!\n");
	        	        exit(-1);
			}
			else if(r21==0)
			{
				printf("child 21 :pid= %d,ppid =%d\n",getpid(),getppid());			
				exit(0);
			}
			else
			{
				int rr=wait(NULL);
				prtinfo(rr,fp);
				printf("child 2 : pid=%d,ppid =%d\n",getpid(),getppid());
				exit(0);
			}	
		}
		else
		{
			int rr1=waitpid(r1,NULL,0);
			prtinfo(rr1,fp);			
			int rr2=waitpid(r2,NULL,0);
			prtinfo(rr2,fp);
			printf("parent : pid =%d ,r1=%d ,r2=%d\n",getpid(),r1,r2);
			fclose(fp);
			return 0;
		}
	}
}
