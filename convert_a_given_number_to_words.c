#include<stdio.h>
int main()
{
	int n,r,a[100],i=0,c=0;
	scanf("%d",&n);
	while(n>0)
	{
		r=n%10;
		a[i]=r;
		i++;
		n=n/10;
		c++;
	}
	
	for(i=c-1;i>=0;i--)
	{
	switch(a[i])
	{
		case 1: if(a[i]==1)
		        printf("one \t");
		        break;
		        case 2: if(a[i]==2)
		        printf("two \t");
		         break;
		        case 3: if(a[i]==3)
		        printf("three \t");
		         break;
				case 4: if(a[i]==4)
		        printf("four \t");
				 break;
				case 5: if(a[i]==5)
		        printf("five \t");
				 break;
				case 6: if(a[i]==6)
		        printf("six \t");
				 break;
				case 7: if(a[i]==7)
		        printf("seven \t");
				 break;
				case 8: if(a[i]==8)
		        printf("eight \t");
				 break;
				case 9: if(a[i]==9)
		        printf("nine \t");
				 break;
				case 0: if(a[i]==0)
		        printf("zero \t");
		         break;
	}
}
	
//	printf("%d %d %d",a[0],a[1],a[2]);
	
	
	
	return 0;
}
