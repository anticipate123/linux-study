#include "ch05.h"
#include <dlfcn.h>
extern void dynamic_lib_call(void);
int main(void)
{
	void *handle;
	handle=dlopen("./libdlib.so",RTLD_LAZY);	
	if(!handle)
	{
		err_exit("dlopen!");
	}
	dynamic_lib_call();
	return 0;
}
