#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pb push_back
#define pp pop_back
#define F first
#define S second
#define f(i,a,n) for(ll i=a;i<n;i++)
#define mod 1000000007
#define pmx priority_queue<ll>
#define pmi priority_queue<ll,vector<ll>,greater<ll> >
bool isPrime(ll n) 
{	ll i = 0;	
	if (n == 1) 
		return 0;
	f(i, 2, n) 
	{
		if (i * i > n) 
			break;
		if (n % i == 0) 
			return 0;
	}
	return 1;
}
ll power(ll x, ull y, ll z = mod) 
{	ll res = 1;
  x = x%z;
  while (y > 0) 
  {	if (y & 1) 
  		res = (res * x)%z;
    y = y >> 1;
    x = (x * x)%z;  
  }
  return res;
}
ll gcd(ll a,ll b)
{	if(b==0)
		return a;
	return gcd(b,a%b);
}
bool prime[1000001];
void sieve()
{	memset(prime,true,sizeof(prime));
	for(ll i=2;i*i<=1000000;i++)
	{	if(prime[i]==true)
		{	for(ll j=2;j*i<=1000000;j++)
			{	prime[i*j]=false;
			}
		}
	}
}
int main()
{	int n;
	cin>>n;
	bool ok=false;
	f(i,0,n)
	{	int x;
		cin>>x;
		if(x)
			ok=true;
	}
	if(ok)
		cout<<"HARD\n";
	else
		cout<<"EASY\n";	
	return 0;
}
