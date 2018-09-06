#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define f(i,a,n) for(ll i=a;i<n;i++)
#define mod 1000000007
int main()
{	ll n;
	cin>>n;
	ll sum=0;
	ll a[n];
	f(i,0,n)
	{	cin>>a[i];
		sum+=abs(a[i]);
	}
	ll mx=LLONG_MIN;
	for(ll i=1;i<n;i++)
	{	ll dif=abs(a[i]-a[i-1]);
		if(sum-abs(a[i])-abs(a[i-1])+dif>mx)
			mx=sum-abs(a[i])-abs(a[i-1])+dif;
	}
	if(n>1)
	{	cout<<mx<<endl;
	}
	else
		cout<<a[0]<<endl;
	return 0;
}
