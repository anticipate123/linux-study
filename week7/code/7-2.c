#include "ch05.h"

static void __attribute__ ((constructor)) before_main(void)
{
	printf("--------Before Main ---------------\n");
}
static void __attribute__ ((destructor)) after_main(void)
{
	printf("-------After Main--------\n");
}
int main()
{
	printf("---------Main Function is Running!----------\n");
	return  0;
}
