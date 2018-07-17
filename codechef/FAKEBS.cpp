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
 
struct item
{	ll key;
	ll index;
};
bool comp(item a,item b)
{	return a.key<b.key;
}
ll bs(item a[],ll n,ll x)
{	ll l,h,m;
	l=1;
	h=n;
	while(l<=h)
	{	m=(l+h)/2;
		if(a[m].key==x)
			break;
		else if(a[m].key<x)
		{	l=m+1;
		}
		else
			h=m-1;
	}
	return m;
}
ll func(ll a[],ll n,ll sm,ll bg,ll x,ll index)
{	ll bgc=0,smc=0,flag=0;
	ll l,h,m;
	l=1;
	h=n;
	
	while(l<=h)
	{	m=(l+h)/2;
		if(a[m]==x)
		{	break;
		}
		else if(a[m]>x && index>m)
		{	if(sm>0)
			{	l=m+1;
				smc++;
				sm--;
			}
			else
			{	flag=1;
				break;
			}
		}
		else if(a[m]>x && index<m)
		{	if(bg>0)
			{	h=m-1;
				bg--;
			}
			else
			{	flag=1;
				break;
			}		
		}
		else if(a[m]<x && index<m)
		{	if(bg>0)
			{	h=m-1;
				bgc++;
				bg--;
			}
			else
			{	flag=1;
				break;
			}
		}
		else if(a[m]<x && index>m)
		{	if(sm>0)
			{	l=m+1;
				sm--;
			}
			else
			{	flag=1;
				break;
			}		
		}
	}
	if(flag==1)
	{	return -1;
	}
	else
	{	if(bgc>smc)
		return bgc;
		else
		return smc;
	}
}
int main()
{	ll t;
	cin>>t;
	while(t--)
	{	ll n,q;
		cin>>n>>q;
		item a[n+1];
		ll b[n+1];
		ll i;
		for(i=1;i<=n;i++)
		{	cin>>a[i].key;
			a[i].index=i;
			b[i]=a[i].key;
		}
		sort(a+1,a+n+1,comp);
		ll x,sm=0,bg=0,ind=0,index=0;
		for(i=0;i<q;i++)
		{	cin>>x;
			ind=bs(a,n,x);
			//cout<<ind<<endl;
			sm=ind-1;
			bg=n-ind;
			index=a[ind].index;
			cout<<func(b,n,sm,bg,x,index)<<endl;
		}
	}
	return 0;
}
