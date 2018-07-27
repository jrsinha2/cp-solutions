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
	ll a[k];
	int h[101]={0};
	int count=0;
	for(int i=0;i<k;i++)
	{	cin>>a[i];
		if(h[a[i]]==0)
			count++;
		h[a[i]]++;
	}
	sort(h,h+101);
	int c=0;
	int ans=0;
	if(k<n)
		cout<<"0\n";
	else
	{	bool ok=false;
		int mx=k/n;
		while(ok==false && mx>=0)
		{	
			count=0;
			for(int i=100;i>=0 ;i--)
			{	count=count+(h[i]/mx);
			}
			if(count>=n)
			{	ans=mx;
				ok=true;
				break;
			}
			if(count<n)
			{	mx-=1;
			}
		}
		cout<<ans;
	}
	return 0;
}		
			
				
			
	
	
