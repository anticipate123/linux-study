#include "ch05.h"
static void __attribute__ ((destructor)) After_Main()
{
	printf("------AfterMain-------\n");
}
void callback1()
{
	printf("------CallBack1-------\n");
}
void callback2()
{
	printf("------CallBack2-------\n");
}
void callback3()
{
        printf("------CallBack3-------\n");
}

int main(void)
{
	atexit(callback1);
	atexit(callback2);
	atexit(callback3);
	while(1)
	{
		printf("----run now------\n");
		sleep(1);
	}
	printf("---------Promgram finished----------\n");
	return 0;
}
