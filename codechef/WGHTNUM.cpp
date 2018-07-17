/****************************
* AUTHOR:      b_506 				*
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
ll power(ll x, ll y, ll p)
{	ll res = 1;  
 	x = x % p;  
 	while (y > 0)
  {	if (y & 1)
    	res = (res*x) % p;
 		y = y>>1; // y = y/2
    x = (x*x) % p;  
  }
  return res;
}
int main()
{	ll t;
	cin>>t;
	while(t--)
	{	ll n,w;
		cin>>n>>w;
		if(abs(w)>9)
		{	cout<<"0\n";
			continue;
		}
		ll com=0;
		if(w<0)
		{	com=w+9;
			com++;
		}
		else
			com=9-w;
		ll rem=power(10,n-2,mod);
		rem=(rem*com)%mod;
		cout<<rem<<endl;
	}
  return 0;
}
