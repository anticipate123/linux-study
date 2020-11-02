#include "ch05.h"
//char test_env[]="test_env=test";
static void set_env_string(void)
{
	char test_env[]="test_env=test";
	if(putenv(test_env)!=0)
	{
		printf("Failed to put new env var!\n");
	}
	printf("1.The test_env string is %s\n",getenv("test_env"));
}
static void show_env_string(void)
{
	printf("2.The test_env string is %s\n",getenv("test_env"));
}
int main()
{
	set_env_string();
	show_env_string();
	return 0;
}
