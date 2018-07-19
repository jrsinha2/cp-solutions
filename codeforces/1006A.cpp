#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define f(i,a,n) for(int i=a;i<n;i++)
#define mod 1000000007
int main()
{	int n;
	cin>>n;
	map<int,int> m;
	ll a[n];
	f(i,0,n)
	{	cin>>a[i];
		if(m.find(a[i])==m.end())
			m[a[i]]=0;
		m[a[i]]++;
	}
	f(i,0,n)
	{	if(a[i]%2!=0)
		{	a[i]=a[i];
		}
		else
			a[i]-=1;
	}
	f(i,0,n)
		cout<<a[i]<<" ";
	return 0;
}
