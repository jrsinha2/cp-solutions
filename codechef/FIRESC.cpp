#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll p=1;
ll c=0,c1=0;
void ae(vector<ll> g[],ll u,ll v)
{	g[u].push_back(v);
	g[v].push_back(u);
}
void dfsv(ll u,vector<ll> g[],vector<bool> &visited)
{	visited[u]=true;
	ll i;
	//cout<<u<<" ";
	for(i=0;i<g[u].size();i++)
	{	if(visited[g[u][i]]==false)
		{	c1++;
			c1%=mod;
			dfsv(g[u][i],g,visited);
		}
	}
	//cout<<"\n";
}
void dfs(vector<ll> g[], ll V,vector<bool> &visited)
{	ll i;
	for(i=0;i<V;i++)
	{	c1=1;
		if(visited[i]==false)
		{	c1=1;
			c++;
			c%=mod;
			dfsv(i,g,visited);
			//cout<<"\n";
			p*=c1;
			p%=mod;
		}
	}
}		
int main()
{	ll t;
	cin>>t;
	while(t--)
	{	ll n,m;
		cin>>n>>m;
		c1=c=0;
		p=1;
		vector<ll> g[n+1];
		vector<bool> visited(n+1,false); 
		ll i,s,d;
		for(i=0;i<m;i++)
		{	cin>>s>>d;
			ae(g,s-1,d-1);
		}
		dfs(g,n,visited);
		cout<<c%mod<<" "<<p%mod<<endl;
	}
	return 0;
} 
