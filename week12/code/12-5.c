#include "ch12.h"
/*
 * 父进程作为服务器server，记录子进程间的通信过程，
 * 子进程之间发送了88信号则停止通信，并退出
 * */
int main(void)
{
	int k1,k2;
	int fd11[2],fd12[2],fd21[2],fd22[2];
	char buf1[100],buf2[100];
        memset(buf1,0,sizeof(buf));
        memset(buf2,0,sizeof(buf));
	
	k1=fork();
	pipe(fd1);
        pipe(fd2);
        if(k1<0)
        {
                perror("fork1 error!\n");
                exit(-1);
        }
        else if(k1==0)
        {
		close(fd11[0]);
		close(fd12[1]);
		close(fd21[0]);
		close(fd21[1]);
		close(fd22[0]);
		close(fd22[1]);


		while(1)
		{
			read(fd12[0],buf1,sizeof(buf1));
			if(atoi(buf1)==88)
			{
				printf("会话结束\n");
				break;
			}
			scanf("%s",buf2);
			write(fd11[1],buf2,sizeof(buf2));				
		}
		exit(0);
	}
	else 
	{
		k2=fork();
		if(k2<0)
		{
			perror("fork2 error!\n");
	                exit(-1);
		}
		else if(k2==0)
		{
			close(fd11[0]);
	                close(fd11[1]);
        	        close(fd12[0]);
               		close(fd12[1]);
	                close(fd21[0]);
        	        close(fd22[1]);	

			
			while(1)
	                {
        	                read(fd22[0],buf1,sizeof(buf1));
                	        if(atoi(buf1)==88)
	                        {
        	                        printf("会话结束\n");
                	                break;
	                        }
        	                scanf("%s",buf2);
                	        write(fd21[1],buf2,sizeof(buf2));
	                }
			exit(0);
		}
		else
		{
			close(fd1[0]);
			close(fd1[1]);
			close(fd2[0]);
			close(fd2[1]);
			wait(NULL);
			wait(NULL);	
			exit(0);
		}			
	}
	

}
