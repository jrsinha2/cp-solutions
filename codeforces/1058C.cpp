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
	int a[n];
	char c;
	f(i,0,n)
	{	cin>>c;
		a[i]=c-'0';
	}
	//f(i,0,n)
	//	cout<<a[i]<<" ";
	vector<int> pre(n);
	pre[0]=a[0];
	f(i,1,n)
		pre[i]=pre[i-1]+a[i];
	vector<int> sum(n+1,-1);
	int tot=pre[n-1];
	
	sum[0]=sum[1]=-1;
	vector<pair<int,int> > pos;
	f(i,2,n+1)
	{	if(tot%i==0)
		{	sum[i]=tot/i;
			pos.pb({sum[i],i});
		}
	}
	/*f(i,0,n+1)
		cout<<sum[i]<<" ";
	cout<<"\n";
	
	f(i,0,n)
		cout<<pre[i]<<" ";
	cout<<"\n";
	
	*/
	int i=0;
	bool found=false;
	while(i<pos.size())
	{	int parts=pos[i].S;
		int req=pos[i].F;
		//cout<<parts<<" "<<req<<endl;
		auto in=lower_bound(pre.begin(),pre.end(),req);
		int ini=in-pre.begin();
		//cout<<ini<<endl;
		
		bool ok;
		int j;
		if(pre[ini]==req)
		{	//cout<<pre[ini]<<endl;
			int p=1;
			req=2*req;
			ok=true;
			while(p<parts)
			{	auto it=lower_bound(pre.begin(),pre.end(),req);
				j=it-pre.begin();
				if(pre[j]==req && pre[j]-pre[ini]==pos[i].F)
				{	req+=pos[i].F;
					p++;
					ini=j;
				}
				else
				{	ok=false;
					break;
				}
			}
		}
		if(!ok)
			i++;
		else
		{	found=true;
			break;
		}
	}	
	if(found)
		cout<<"YES\n";
	else
		cout<<"NO\n";	
	return 0;
}
