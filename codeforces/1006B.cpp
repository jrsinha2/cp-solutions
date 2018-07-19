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
	int k;
	cin>>k;
	int a[n],d[n];
	f(i,0,n)
	{	cin>>a[i];
		d[i]=a[i];
	}
	sort(d,d+n);
	ll sum=0;
	map<int,int> m;
	m.clear();
	for(int i=n-1;i>=n-k;i--)
	{	sum+=d[i];
		if(m.find(d[i])==m.end())
			m[d[i]]=0;
		m[d[i]]++;
	}
	ll c=0,count=0;
	cout<<sum<<endl;
	f(i,0,n)
	{	count++;
		if(c<k-1 && m[a[i]]!=0)
		{	cout<<count<<" ";
			count=0;
			c++;
			m[a[i]]--;
		}
	}
	if(count)
	cout<<count<<endl;
	return 0;
}
		
