#include <stdio.h>

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
int main(void)
{
	unsigned long long int year = 0;
	unsigned char month = 0;
	unsigned char year_c[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	while (scanf(" %lld.%hhd", &year, &month) == 2) //这里有个小问题，在群里问过了，但是用VS编译运行正常
	{
		if (month == 2)
			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
			{
				printf("29\n");
				continue;
			}
		printf("%02d\n", year_c[month - 1]);
	}

	return 0;
}
