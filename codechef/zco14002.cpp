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
ll min(ll a ,ll b)
{	if(a<b)
		return a;
	return b;
}
int main()
{	ll n;
	cin>>n;
	ll a[n];
	//ll b[n]={0};
	ll i;
	for(i=0;i<n;i++)
	{	cin>>a[i];
		
	}
	//sort(a,a+n,comp);
	/*for(i=0;i<n;i++)
	{	cout<<a[i].k<<" ";
	}
	cout<<"\n";
	for(i=0;i<n;i++)
		cout<<a[i].i<<" ";
	cout<<"\n";
	*/
	ll dp[n];
	dp[0]=a[0];
	dp[1]=a[1];
	dp[2]=a[2];
	for(i=3;i<n;i++)
	{	dp[i]=a[i]+min(dp[i-1],min(dp[i-2],dp[i-3]));
	}
	cout<<min(dp[n-1],min(dp[n-2],dp[n-3]))<<endl;
	return 0;
}
		
	
	
	
