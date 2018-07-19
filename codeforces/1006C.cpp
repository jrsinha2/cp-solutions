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
	int a[n];
	f(i,0,n)
		cin>>a[i];
	ll sum1[n],sum3[n];
	sum1[0]=a[0];
	unordered_map<ll,int> m1,m2;
	m1[sum1[0]]=0;	
	sum3[n-1]=a[n-1];
	m2[sum3[n-1]]=n-1;

	f(i,1,n)
	{	sum1[i]=sum1[i-1]+a[i];
		m1[sum1[i]]=i;
	}
	for(int i=n-2;i>=0;i--)
	{	sum3[i]=sum3[i+1]+a[i];
		m2[sum3[i]]=i;
	}
	queue<int> index;
	ll ma=INT_MIN;
	for(int i=0;i<n;i++)
	{	if(m2.find(sum1[i])!=m2.end())
		{	int l=m1[sum1[i]];
			int r=m2[sum1[i]];
			if(l<r)
			{	 if(sum1[i]>ma)
					ma=sum1[i];
			}
		}
	}
	if(ma!=INT_MIN)
		cout<<ma<<endl;
	else
		cout<<"0\n";
	return 0;
}
