/****************************
* AUTHOR:      b_506			 	*
* INSTITUTION: MNIT JAIPUR  *
****************************/

#include<iostream>
#include<string>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<climits>
#include<queue>
#include<list>
#include<map>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
#define f(i,a,n) for(ll i=a;i<n;i++)
#define fr(i,a,n)	for(i=n-1;i>=a;i--)
#define mod 1000000007
#define PI	3.141516
#define NIL -1
#define INF 1000000000000000000
ll min(ll x,ll y)
{	if(x<y)
		return x;
	return y;
}
int main()
{	ll n;
	cin>>n;
	ll a[n];
	ll i,j;
	for(i=0;i<n;i++)
	{	cin>>a[i];
	}
	ll cf[n],cb[n];
	cf[0]=a[0];
	cb[n-1]=a[n-1];
	if(n>1)
	{	cf[1]=min(0,cf[0])+a[1];
		cb[n-2]=min(0,cb[n-1])+a[n-2];
	}
	for(i=2,j=n-3;i<n && j>=0;i++,j--)
	{	cf[i]=a[i]+min(cf[i-1],cf[i-2]);
		cb[j]=a[j]+min(cb[j+1],cb[j+2]);
	}
	cout<<min(cb[0],cf[n-1])<<endl;
	return 0;
}
	
	
