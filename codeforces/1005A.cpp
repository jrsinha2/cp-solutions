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
	int hash[1001]={0};
	int a[n];
	int mx=INT_MIN;
	int mxi=0;
	f(i,0,n)
	{	cin>>a[i];
		hash[a[i]]++;
		mx=max(mx,hash[a[i]]);
		mxi=max(mxi,a[i]);
	}
	cout<<mx<<endl;
	int c=0;
	for(int i=0;i<n;i++)
	{	
		if(a[i]==1)
		{	if(i>0)
			{	cout<<c<<" ";
			}
			c=0;
		}
		c++;
	}
	if(c)
		cout<<c;
	return 0;
}
