#include<stdio.h>
#include<math.h>
int main()
{	long int n,m;
	scanf("%ld",&n);
	scanf("%ld",&m);
	long int q=(long int)pow(2,n);
	printf("%ld",m%q);
	return 0;
}
