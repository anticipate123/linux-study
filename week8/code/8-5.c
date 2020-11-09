#include "./ch08.h"
#include <iostream>
using namespace std;
static jmp_buf g_stack_env;
//static void func1(int *a,int *b,int *c);
class Test{
	public:
		Test(){
			cout<<"Constructor"<<endl;
		}
		~Test(){
                        cout<<"Destructor"<<endl;
                }
}
int main()
{
	int a=1;
	int b=2;
	int c=3;
	int ret=setjmp(g_stack_env);
	if(ret==0)
	{
		printf("Normal flow!\n");
		printf("Normal a= %d,b= %d,c= %d\n",a,b,c);
		func1(&a,&b,&c);
	}
	else
	{
		printf("Back From Longjump flow!\n");
		printf("Back From Longjump a= %d,b= %d,c= %d\n",a,b,c);
	}
	return 0;
}
static void func1(int *a,int *b,int *c)
{
	printf("Enter func1!\n");
	++(*a);
	++(*b);
	++(*c);
	printf("func1: a= %d,b= %d, c= %d\n",*a,*b,*c);
	longjmp(g_stack_env,1);
	printf("Leave func1!\n");
}

