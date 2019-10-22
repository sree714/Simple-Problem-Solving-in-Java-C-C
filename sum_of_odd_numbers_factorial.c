#include<stdio.h>
int fun(int n)
{
	int f=1,i;
	for(i=n;i>=1;i--)
	{
		f=f*i;
		
		}
	return(f);
}
int main()
{

 int n,i,fact,s=0;
 scanf("%d",&n);
 
 for(i=1;i<2*n;i++)
 {
	 if(i%2!=0)
	 {
		//printf("%d  ",i); 
		fact=fun(i);
		//printf("%d ",fact);
		s=s+fact;
		
	 }
	 
 }	
 printf("%d ",s);
return 0;
}
