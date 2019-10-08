#include <stdio.h> 
#include<stdlib.h>
int main()
{
	int b,n,i,f=1 ,*m,*temp;
	m=(int*)malloc(sizeof(int));
	temp=m;
	printf("\n enter the size of array: ");
	scanf("%d",&b);
	
	for(i=0;i<b;i++)
	{
		scanf("%d",m);
		m++;
	}
	
	printf("\n enter a number: ");
	scanf("%d",&n);
	
	
	for(i=0;i<b;i++)
	{
		if(n==*temp)
		{
			f=0;
			break;
		}
	temp++;
	}
	if(f==0)
	printf("\n element found");
	else
	printf("\n not found");
	return 0; 
} 
