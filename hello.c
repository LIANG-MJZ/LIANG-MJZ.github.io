#include "stdio.h"
#include "malloc.h"

void huan(int ***q)
{
	int i =152;
	 *q = &i;

}

int main(void)
{
	int a=111;
	int *p = &a;
	int **w = &p;
	int ***e = &w;

	printf("1 = %d\n",*p);
	huan(p);
	printf("2 = %d\n",*p);
}
