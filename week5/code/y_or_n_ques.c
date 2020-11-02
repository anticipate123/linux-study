#include <stdio.h>
int y_or_n_ques(char s[])
{
	printf("%s",s);
	char c;
	scanf("%c",&c);
	if(c=='y'||c=='Y')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
