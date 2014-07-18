#include <stdio.h>
#include <stdlib.h>

int main()
{
	system("git ls-files | xargs wc -l");
	return 0;
}

