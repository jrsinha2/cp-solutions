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

string g[101];
bool vis[101][101]={0};
const int ro[8]={0,1,-1,0,1,-1,-1,1};
const int co[8]={1,0,0,-1,1,1,-1,-1};
int r,c;
bool isvalid(int u,int v)
{	if(u<r && u>=0 && v<c && v>=0)
	{	if(!vis[u][v])
			return true;
	}
	return false;
}
char st[11]={'A','L','L','I','Z','Z','W','E','L','L'};
string dfs(int u,int v,int c)
{	vis[u][v]=true;
	string s;
	if(c==9)
	{	return "YES";
	}
	for(int i=0;i<8;i++)
	{	if(isvalid(u+ro[i],v+co[i]))
		{	if(g[u+ro[i]][v+co[i]]==st[c+1])
			{	s=dfs(u+ro[i],v+co[i],c+1);
				if(s=="YES")
				{	return s;
					//vis[u+ro[i]][v+co[i]]=false;
				}
			}
		}
	}
	vis[u][v]=false;
	return "NO";
}
			
int main()
{	int tt;
	cin>>tt;
	while(tt--)
	{	cin>>r>>c;
		f(i,0,r)
		{	cin>>g[i];
		}
		bool ok=false;
		memset(vis,0,sizeof vis);
		//int ctr=0;
		for(int i=0;i<r;i++)
		{	for(int j=0;j<c;j++)
			{	if(g[i][j]=='A' && dfs(i,j,0)=="YES")
				{	cout<<"YES\n";
					ok=true;
					break;
				}
			}
			if(ok)
				break;
		}
		if(!ok)
			cout<<"NO\n";
	}
	return 0;
}
		
