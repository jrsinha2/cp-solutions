#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define f(i,a,n) for(int i=a;i<n;i++)
#define mod 1000000007
int main()
{	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int ans=0;
	int a[26]={0};
	int mi=INT_MAX;
	int c=0;
	f(i,0,n)
	{	a[s[i]-'A']++;
	}
	f(i,0,k)
	{	mi=min(a[i],mi);
	}
	cout<<k*mi<<endl;
	return 0;
}
