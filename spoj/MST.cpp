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
		
		si=m[a[0]];
		sj=a[1]-'0';
		ei=m[b[0]];
		ej=b[1]-'0';
			
	return 0;
}
