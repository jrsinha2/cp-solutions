/****************************
* AUTHOR:      b_506			 	*
* INSTITUTION: MNIT JAIPUR  *
****************************/
 
#include<bits/stdc++.h>
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
ll max(ll x,ll y)
{	if(x<y)
		return y;
	return x;
}
ll count(ll a)
{	ll c=0;
	while(a>0)
	{	//cout<<a%2;
		if(a%2==1)
			c++;
		a/=2;
	}
	//cout<<"\n";
	return c;
}
int main()
{	ll t;
	cin>>t;
	while(t--)
	{	ll n,m;
		cin>>n>>m;
		if(n==m)
		{	cout<<"0\n";
			continue;
		}
		else if(count(m)==0)
		{	cout<<NIL<<endl;
			continue;
		}
		else
		{	
			ll start=count(n);
			ll dest=count(m-1);
			if(dest==0 && start>dest)
			{	cout<<NIL<<endl;
				continue;
			}
			//cout<<start<<endl;
			//cout<<dest<<endl;
			ll c=0;
			if(start>dest)
			{	c=2;
			}
			else
			{	c=abs(dest-start)+1;
			}	
			cout<<c<<endl;
		}
		
	}
	return 0;
}
