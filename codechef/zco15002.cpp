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
int main()
{	ll n,k;
	cin>>n>>k;
	ll a[n+1];
	ll i,j;
	for(i=1;i<=n;i++)
	{	cin>>a[i];
	}
	sort(a+1,a+n+1);
	ll c=0;
	for(i=n;i>=2;i--)
	{	j=i-1;
		while(a[i]-a[j]<k && j>=1)
		{	j--;
		}
		c+=(j);
		//cout<<j<<endl;
	}
	cout<<c<<endl;
	return 0;
}
		
	
	
