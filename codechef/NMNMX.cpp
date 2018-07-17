#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll long long
#define MAX 5003
ll triangle[MAX + 1][MAX + 1];
//ll fact[5003];
ll gcdExtended(ll a, ll b, ll *x, ll *y);

ll gcdExtended(ll a, ll b, ll *x, ll *y)
{	if (a == 0)
  {	*x = 0, *y = 1;
    return b;
  }
 	ll x1, y1;
  ll gcd = gcdExtended(b%a, a, &x1, &y1);
 	*x = y1 - (b/a) * x1;
  *y = x1;
	return gcd;
}
long long  expo(long long  x,long long  p)
{	long long  res=1;
	x=x%mod;
	while(p>0)
	{	if(p&1)
		{	res=(res%mod*x%mod);
			res%=mod;
			//res=mulmod(res,x)%mod;
		}
		p/=2;
		//x=mulmod(x,x)%mod;
		x=(x*x);
		x%=mod;
	}
	return res;
}
ll modInverse(ll b, ll m)
{	return expo(b,m-2);	
}
int main()
{	int tt;
	cin>>tt;
	int i, j;
	triangle[0][0]=0;
	for(i = 0; i < MAX; i++) 
	{	
		for(j = 0; j <= min(i,5003); j++) 
    { if(j==0 || i==0)
    	{	triangle[i][j]=1;
    	}
    	else
    	{	triangle[i][j] = ((triangle[i - 1][j - 1]%1000000006) + (triangle[i - 1][j]%1000000006))%1000000006;
    	}
  	}
  }
	while(tt--)
	{	unsigned int n,k;
		cin>>n>>k;
		long long a[n];
		long long p[n][3];
		for(int i=0;i<n;i++)
			cin>>a[i];
		long long ans=1;
		long long nume,deno1,deno2,po;
		ans=1;
		sort(a,a+n);
		for(int i=1;i<n-1;i++)
		{	p[i][0]=triangle[n-1][k-1];
			p[i][1]=triangle[n-i-1][k-1];
			p[i][2]=triangle[i][k-1];
			//cout<<a[i]<<" "<<p[i][0]<<" "<<p[i][1]<<" "<<p[i][2]<<endl;
		}
		
		for(int i=1;i<n-1;i++)
		{	nume=expo(a[i],p[i][0]);
			deno1=expo(a[i],p[i][1]);
			deno2=expo(a[i],p[i][2]);
			po=((nume*modInverse(deno1,1000000007)%mod)*modInverse(deno2,1000000007))%mod;
			ans=(ans*po)%mod;
			ans%=mod;	
		}
		cout<<ans<<endl;
	}
	return 0;
}	
