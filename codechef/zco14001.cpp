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
{	ll n,h;
	cin>>n>>h;
	ll a[n];
	ll i;
	for(i=0;i<n;i++)
	{	cin>>a[i];
	}
	ll x=NIL,j=0,ini=-1,fin=-1;
	while(x!=0)
	{	cin>>x;
		switch(x)
		{	case 1:	if(j>0)
								j--;
							break;
			case 2:	if(j<n-1)
								j++;
							break;
			case 3:	if(ini==-1 && a[j]>0)
							{	ini=j;
								a[ini]--;
							}
							break;
			case 4:	if(a[j]<h && ini!=-1)
							{	//a[ini]--;
								a[j]++;
								ini=-1;
							}
		}
	}
	for(i=0;i<n;i++)
	{	cout<<a[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
