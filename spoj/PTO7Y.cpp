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
bool ok=true;
vector<int> g[10001];
bool vis[10001];
int dis[10001];
int en[10001];
void dfs(int u)
{	vis[u]=true;
	static int time=0;
	dis[u]=++time;
	for(int i=0;i<g[u].size();i++)
	{	int v=g[u][i];
		if(!vis[v])
			dfs(v);
		else if(dis[v]>dis[u])
			ok=false;
		else if(u==v)
			ok=false;
	}
	en[u]=++time;
}

int main()
{	int n,m;
	cin>>n>>m;
	memset(vis,0,sizeof vis);
	memset(dis,-1,sizeof dis);
	memset(en,-1,sizeof en);
	int u,v;
	f(i,0,m)
	{	cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1);
	
	if(ok)
	{	bool all=true;
		for(int i=1;i<=n;i++)
			if(vis[i]==false)
				all=false;
		if(all)
		cout<<"YES\n";
		else
			cout<<"NO\n";
	}
	else
		cout<<"NO\n";
}
