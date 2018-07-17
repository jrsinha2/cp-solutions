#include<iostream>
#include<string>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<climits>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
#define f(i,a,n) for(ll i=a;i<n;i++)
#define fr(i,a,n)	for(i=n-1;i>=a;i--)
#define MAX 1000000007
#define PI	3.141516
int main()
{	ull y,bl;
	cin>>y>>bl;
	ull a,b,c;
	cin>>a>>b>>c;
	ull b1=a*2+b;
	ull b2=b+c*3;
	ull sum1=0,sum2=0;
	if(b1>y)
		sum1=b1-y;
	if(b2>=bl)
		sum2=b2-bl;
	cout<<sum1+sum2<<"\n";
	
	
}
