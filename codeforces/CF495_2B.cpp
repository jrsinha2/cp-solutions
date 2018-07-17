#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i,a,n) for(int i=a;i<n;i++)
//map<ll,ll> m; 
bool comp(pair<int,int > p,pair<int,int > q){
	return (p.second-p.first+1)>(q.second-q.first+1);
}
int main() 
{
	int n,d;
	cin>>n>>d;
	int l,r;
	vector<pair<int,int> > a;
	f(i,0,d){
		cin>>l>>r;
	}
	f(i,0,n)
	{	if(i%2==0)
			cout<<"0";
		else
			cout<<"1";
	}	
	return 0;
}
