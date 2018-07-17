/****************************
* AUTHOR:      b_506			 	*
* INSTITUTION: MNIT JAIPUR  *
****************************/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define f(i,a,n) for(int i=a;i<n;i++)
#define mod 1000000007
int find(vector<int> &parent,vector<int> &rank,int i)					// DSU find
{	if(parent[i]!=i)
		parent[i]=find(parent,rank,parent[i]);
	return parent[i];
}


void join(vector<int> &parent,vector<int> &rank,int x,int y)			//DSU union
{	int xset=find(parent,rank,x);
	int yset=find(parent,rank,y);
	if(rank[xset]<rank[yset])
		parent[xset]=yset;
	else if(rank[xset]>rank[yset])
		parent[yset]=xset;
	else 
	{	parent[yset]=xset;
		rank[xset]++;
	}
	//cout<<parent[xset]<<endl;
	//cout<<"here in join f()\n";
}
int main()
{	int tt;
	cin>>tt;
	while(tt--)
	{	int n,c;
		cin>>n>>c;
		vector<int> parent(n+1);
		for(int i=1;i<=n;i++)
			parent[i]=i;
		vector<int> rank(n+1,0);
		vector<int> g[n+1];
		int u,v;
		f(i,0,c)
		{	cin>>u>>v;
			//g[u].pb(v);
			//g[v].pb(u);
			int px=find(parent,rank,u);
			int py=find(parent,rank,v);
			if(px!=py)
			{	join(parent,rank,u,v);
			}
		}
		int q;
		cin>>q;
		while(q--)
		{	cin>>u>>v;
			if(find(parent,rank,u)==find(parent,rank,v))
			{	cout<<"Yes\n";
			}
			else
				cout<<"No\n";
		}
	}
	return 0;
} 
