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
