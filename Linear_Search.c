#include<stdio.h>
int main()
{
 int a[]={2,8,3,1,6,7,9};
	int i,n,temp=1;	
	printf("\n enter the number to search:");
	scanf("%d",&n);
	for(i=0;i<7;i++)
	{
		if(a[i]==n)
		{
			temp=0;
			break;
		}
		
	}
	if(temp==0)
	{
		printf("%d is found at %d location",n,++i);
	}
	else
	printf("%d is not found",n);
	
return 0;
}
