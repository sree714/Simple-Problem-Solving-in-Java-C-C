#include<stdio.h>
void swap(int *a,int *b)
{
	int c;
	c=*a;
	*a=*b;
	*b=c;
//printf("%d\t%d",*a,*b);	
}
int main()
{
	int a=5,b=10;
	swap(&a,&b);
	printf("%d\t",a);
	printf("%d\t",b);
	return 0;
}
