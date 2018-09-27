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
#define mem(a,p) memset(a,p,sizeof a)
map<char,int> m;
bool isvalid(int i,int j)
{	if(i>=0 && i<8 && j>=0 && j<8)
		return true;
	return false;
}
int si,sj,ei,ej;
const int ro[8]={2,2,1,1,-2,-2,-1,-1};
const int co[8]={-1,1,-2,2,-1,1,-2,2};
int level[8][8];
bool vis[8][8];
void bfs()
{	queue<pair<int,int> > q;
	q.push(mp(si,sj));
	level[si][sj]=0;
	vis[si][sj]=true;
	while(!q.empty())
	{	int i=q.front().F;
		int j=q.front().S;
		q.pop();
		for(int l=0;l<8;l++)
		{	int r1=i+ro[l];
			int c1=j+co[l];
			if(isvalid(r1,c1))
			{	if(!vis[r1][c1])
				{	level[r1][c1]=level[i][j]+1;
					vis[r1][c1]=true;
					q.push(mp(r1,c1));
				}
			}
			if(r1==ei && c1==ej)
				return ;
		}
	}
}
int main()
{	int t;
	cin>>t;
	m['a']=0;
	m['b']=1;
	m['c']=2;
	m['d']=3;
	m['e']=4;
	m['f']=5;
	m['g']=6;
	m['h']=7;
	while(t--)
	{	string a,b;
		cin>>a>>b;
		mem(vis,0);
		mem(level,0);
		si=m[a[0]];
		sj=a[1]-'0';
		ei=m[b[0]];
		ej=b[1]-'0';
		sj--,ej--;
		bfs();
		cout<<level[ei][ej]<<endl;
	}	
	return 0;
}
