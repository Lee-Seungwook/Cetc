#include <stdio.h>
#include <stdlib.h>
#include <direct.h>

void main(void)
{
	char pathname[_MAX_PATH];
	printf("16-11-21 ÀÌ½Â¿í\n");
	_getcwd(pathname, _MAX_PATH);
	puts(pathname);
	system("pause");
}