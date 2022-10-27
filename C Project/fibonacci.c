#include<stdio.h>
int Fibonacci(int);
int main()
{
	int m,i;
	printf("Enter a number you want to generate fibonacci series\n");
	scanf("%d",&m);
	printf("Fibonacci series\n");
	for(i=0;i<m;i++)
	{
		printf("%d\n",Fibonacci(i));
	}
	return 0;
}
int Fibonacci(int m)
{
	if(m == 0)
		return 0;
	else if(m == 1)
		return 1;
	else
		return(Fibonacci(m-1) + Fibonacci(m-2));
}


