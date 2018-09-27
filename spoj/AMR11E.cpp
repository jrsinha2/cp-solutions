#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define pb push_back
#define pp pop_back
#define mp make_pair
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
vector<int> p;
bool prime[3001];
void sieve()
{	memset(prime,true,sizeof(prime));
	for(ll i=2;i<=3001;i++)
	{	if(prime[i]==true)
		{	p.pb(i);
			//cout<<i<<endl;
			for(ll j=2;j*i<=3001;j++)
			{	prime[i*j]=false;
			}
		}
	}
}
vector<int> ans;
void func()
{	sieve();	
	for(int i=5;i<=3000;i++)
	{	int count=0;
		for(int j=0;j<p.size();j++)
		{	if(i%p[j]==0)
				count++;
			if(count>=3)
			{	ans.pb(i);
				//cout<<i<<endl;
				break;
			}
		}
		
	}
	//sort(ans.begin(),ans.end());
}
		
int main()
{	int t;
	cin>>t;
	ans.clear();
	func();
	//cout<<ans.size();
	//cout<<ans[0]<<ans[1]<<ans[2]<<ans[3]<<ans[4];
	while(t--)
	{	int n;
		cin>>n;
		cout<<ans[n-1]<<endl;
	}
	return 0;
}
