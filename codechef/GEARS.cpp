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

ll gcd(ll a ,ll b)
{	if(b==0)
		return a;
	return gcd(b,a%b);
}

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

void dfsvisit(int u,bool vis[],bool stop[],vector<int> g[])
{	vis[u]=true;
	stop[u]=true;
	for(int i=0;i<g[u].size();i++)
	{	int v=g[u][i];
		if(!vis[v] && !stop[v])
		{	dfsvisit(v,vis,stop,g);
		}
	}
}

void dfs(int u,int y,bool stop[],vector<int> g[])					//dfs 
{	bool vis[500001];
	memset(vis,0,sizeof vis);
	stop[u]=true;
	stop[y]=true;
	vis[u]=true;
	vis[y]=true;
	for(int i=0;i<g[u].size();i++)
	{	int v=g[u][i];
		if(!vis[v] && !stop[v])
		{	dfsvisit(v,vis,stop,g);
		}
	}
}

void findvelocity(int u,int y,vector<int> g[],int dir[],ll a[],ll speednum[],ll speedden[],ll &nu,ll &de,ll &di)
{	bool vis1[500001];
	memset(vis1,0,sizeof vis1);
	queue<int> q;
	q.push(u);
	dir[u]=0;
	int first;
	vis1[u]=true;
	while(!q.empty())
	{	
		first=q.front();
		q.pop();
		if(first==y)
			break;
		
		int now=1-dir[first];
		ll nume=speednum[first];
		ll deno=speedden[first];
		ll teeth=a[first];
		for(int i=0;i<g[first].size();i++)
		{	int v=g[first][i];
			if(!vis1[v])
			{	dir[v]=now;
				speednum[v]=nume*teeth;
				speedden[v]=deno*a[v];
				ll hcf=gcd(speednum[v],speedden[v]);
				speednum[v]/=hcf;
				speedden[v]/=hcf;
				vis1[v]=true;
				q.push(v);
			}
		}
	}
	nu=speednum[first];
	de=speedden[first];
	di=dir[first];
}

void bfs(int u,int y,vector<int> g[],ll level[])
{	bool vis1[500001];
	memset(vis1,0,sizeof vis1);
	queue<int> q;
	q.push(u);
	vis1[u]=true;
	vis1[y]=true;
	while(!q.empty())
	{	int v=q.front();
		q.pop();
		for(int i=0;i<g[v].size();i++)
		{	int w=g[v][i];
			if(!vis1[w] && (level[w]+level[v])%2==0)
			{	vis1[w]=true;
				level[w]=level[v]+1;
				q.push(w);
			}
		}	
	}
}

int main()
{	
	ll n,m;
	cin>>n>>m;
	
	ll a[n+1];
	vector<int> g[n+1];
	
	bool stop[n+1];				//locked condition
	memset(stop,0,sizeof stop);
	
	
	vector<int> parent(n+1,-1);
	vector<int> rank(n+1,0);
	for(int i=1;i<=n;i++)
	{	cin>>a[i];
		parent[i]=i;
	}
	
					
	//memset(parent,-1,sizeof parent);

	int dir[n+1];					//direction 0 clockwise   1 counterclockwise	-1 stopped
	memset(dir,-1,sizeof dir);
	
	ll speednum[n+1];
	ll speedden[n+1];					//speed function
	memset(speednum,0,sizeof speednum);
	memset(speedden,0,sizeof speedden);
	ll level[n+1];
	memset(level,-1,sizeof level);
	
	ll t;			//type
	
	for(int i=0;i<m;i++)
	{	cin>>t;
		if(t==1)
		{	ll x,c;
			cin>>x>>c;
			//change of teeth
			
			a[x]=c;
		}
		else if(t==2)
		{	int x,y;
			cin>>x>>y;
			int px=find(parent,rank,x);
			int py=find(parent,rank,y);
			
			if(px!=py || (level[x]+level[y])%2==1)
			{	join(parent,rank,px,py);
				g[x].pb(y);
				g[y].pb(x);
				if((stop[x]==true  && stop[y]!=true)|| (stop[x]!=true && stop[y]==true))
				{	if(stop[x]==true)
					{	dfs(y,x,stop,g);
						/*for(int ii=1;ii<=n;ii++)
							cout<<stop[ii]<<" ";
						cout<<"\n";	
						*/
					}
					else if(stop[y]==true)
					{	dfs(x,y,stop,g);
						/*for(int ii=1;ii<=n;ii++)
							cout<<stop[ii]<<" ";
						cout<<"\n";	
						*/
					}
				}
				if(level[x]==-1 && level[y]==-1)
				{	level[x]=1;
					level[y]=2;
				}
				else if(level[x]!=-1 && level[y]==-1)
				{	level[y]=level[x]+1;
					//bfs(y,x,g,level);
				}
				else if(level[y]!=-1 && level[x]==-1)
				{	level[x]=level[y]+1;
					//bfs(x,y,g,level);
				}
				else if((level[x]+level[y])%2==0)
				{	if(level[x]>level[y])
					{	level[y]=level[x]+1;
						bfs(y,x,g,level);
					}
					else
					{	level[x]=level[y]+1;
						bfs(x,y,g,level);
					}
				}
				
				//cout<<"now joined\n";
			}
			else
			{	//cout<<"already joined\n";
				dfs(x,y,stop,g);
				/*for(int ii=1;ii<=n;ii++)
					cout<<stop[ii]<<" ";
				cout<<"\n";
				*/	
			}
			/*for(int ii=1;ii<=n;ii++)
				{	cout<<level[ii]<<" ";
				}
				cout<<"\n";
				for(int ii=1;ii<=n;ii++)
				{	cout<<stop[ii]<<" ";
				}
				cout<<"\n";	
			*/
			//union of two nodes
		
		}
		else  if(t==3)
		{	int x,y,v;
			cin>>x>>y>>v;
			int px=find(parent,rank,x);
			int py=find(parent,rank,y);
			//cout<<parent[x]<<" "<<parent[y]<<endl;
			if(stop[x]==true || stop[y]==true || (px!=py))
				cout<<"0\n";
			else
			{	ll nu=0,de=0,di=0;
				//speednum[x]=v;
				//speedden[x]=1;
				//dir[x]=0;
				//findvelocity(x,y,g,dir,a,speednum,speedden,nu,de,di);	
				nu=v*a[x];
				de=a[y];
				ll hcf=gcd(nu,de);
				nu/=hcf;
				de/=hcf;
				if(abs(level[y]-level[x])%2==0)
				{	di=0;
				}
				else
					di=1;
				if(di==1)
				{	cout<<(-1*nu)<<"/"<<de<<endl;
				}
				else
				{	cout<<nu<<"/"<<de<<endl;
				}
				//cout<<px<<endl;
			}
			/*for(int ii=1;ii<=n;ii++)
			{	cout<<level[ii]<<" ";
			}
			cout<<"\n";
			for(int ii=1;ii<=n;ii++)
			{	cout<<stop[ii]<<" ";
			}
			cout<<"\n";
		 */
			//v is speed of x so spped of y is -v*(x/y)
		}
		
	}
	return 0;
}	
