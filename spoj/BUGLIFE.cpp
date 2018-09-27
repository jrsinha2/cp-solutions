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

vector<int> g[10001];

int color[10001];
bool bfs(int u)
{	
	color[u]=1;
	queue<int> q;
	q.push(u);
	while(!q.empty())
	{	int v=q.front();
		q.pop();
		for(int i=0;i<g[v].size();i++)
		{	if(color[g[v][i]]==-1)
			{	
				color[g[v][i]]=1-color[v];
				q.push(g[v][i]);
			}
			else if(color[g[v][i]]==color[v])
				return false;
			if(g[v][i]==v)
				return false;	
		}
	}
	return true;
}

int main()
{	int t;
	cin>>t;
	for(int b=1;b<=t;b++)
	{	
		int n,m;
		cin>>n>>m;
		for(int i=0;i<10001;i++)
			g[i].clear();
		
		memset(color,-1,sizeof color);
	
		int u,v;
		f(i,0,m)
		{	cin>>u>>v;
			g[u].pb(v);
			g[v].pb(u);
		}
		cout<<"Scenario #"<<b<<":\n";
		bool ok=true;
		for(int i=1;i<=n;i++)
		{	if(color[i]==-1)
			{	if(!bfs(i))
				{	cout<<"Suspicious bugs found!\n";
					ok=false;
					break;
				}
			}
		}
		if(ok)
			cout<<"No suspicious bugs found!\n";
	}
	return 0;
}
