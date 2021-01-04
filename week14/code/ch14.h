#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <setjmp.h>
#include <wait.h>
#include <errno.h>
#include <ctype.h>
#include <sys/ipc.h>
#include <sys/msg.h>

//  网络编程  socket
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/wait.h>

#define SERVPORT 3333  /*服务器监听端口号*/
#define BACKLOG 10     /*最大同时链接请求数 */
#define MAXDATASIZE 100
// 网络编程   socket




#define SERVER_FIFO_NAME "./server_fifo"
#define CLIENT_FIFO_NAME "./client_%d_fifo"
#define BUFFER_SIZE 132

#define PIPE_BUF 100
#define FIFO_FILE "./testfifo"
#define TEN_MEG 1000
#define INFILE "./in.txt"
#define OUTFILE "./out.txt"
#define MODE S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH
void err_exit(char *s)
{
	printf("Usage: %s is failed\n",s);
	exit(1);
}
struct data_to_pass{
	pid_t client_pid;
	char data[BUFFER_SIZE];
};
struct my_msg{
	long int my_msg_type;
	char text[BUFSIZ];
};
/*struct sockaddr_in{
	short int sin_family;
	unsigned short int sin_port;
	struct in_addr sin_addr;
	unsigned char sin_zero[8];
};*/
struct hostent
{
       char    *h_name;              
       char    **h_aliases;
       int     h_addrtype;
       int     h_length;
       char    **h_addr_list;
       #define h_addr h_addr_list[0]

};
