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
bool prime[1000001];
void sieve()
{	memset(prime,true,sizeof(prime));
	for(ll i=2;i<=1000000;i++)
	{	if(prime[i]==true)
		{	for(ll j=2;j*i<=1000000;j++)
			{	prime[i*j]=false;
			}
		}
	}
}

string g[1001];
bool vis[1001][1001]={0};
int dir[1001][1001];
const int ro[4]={0,1,-1,0};
const int co[4]={1,0,0,-1};
int r,c,si,sj,ei,ej;
bool isvalid(int u,int v)
{	if(u<r && u>=0 && v<c && v>=0)
	{	return true;
	}
	return false;
}
void bfs(int u,int v,char c)
{	vis[u][v]=true;
	queue<pair<int,int> > q;
	q.push(mp(u,v));
	dir[u][v]=-1;
	while(!q.empty())
	{	pair<int,int> pr=q.front();
		int I=pr.F;
		int J=pr.S;
		//cout<<pr.F<<" "<<pr.S<<" "<<c<<endl;
		int ini=dir[I][J]
		q.pop();
		//cout<<dir.F<<" "<<dir.S<<endl;
		for(int i=0;i<4;i++)
		{	int I2=I+ro[i];	
			int J2=J+co[i]; 
			while(isvalid(I2,J2) && grid[I2][J2]!='*' && !vis[I2][J2])
			{	vis[I2][J2]=true;	
				q.push(mp(I2,J2));
					
				}
			else if(vis[pr.F+dir.F][pr.S+dir.S]==vs)
			{	return;	
			}
			else 
			{	cou--;
				return;
			}
			
		}
			
	}
}
			
int main()
{	cin>>r>>c;
	f(i,0,r)
	{	cin>>g[i];
	}
	bool ok=false;
	memset(vis,0,sizeof vis);
	memset(dir,0x3f,sizeof dir);
	//int ctr=0;
	
	for(int i=0;i<r;i++)
	{	for(int j=0;j<c;j++)
		{	if(g[i][j]=='C')
			{	if(!ok)	
				{	si=i,sj=j;
					ok=true;
				}
				else
					ei=i,ej=j;
			}
		}
	}
	bfs();			
	return 0;
}
		
