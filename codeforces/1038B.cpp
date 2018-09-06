#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define f(i,a,n) for(int i=a;i<n;i++)
#define mod 1000000007
int gcd(int a,int b)
{	if(b==0)
		return a;
	return gcd(b,a%b);
}
int main()
{	int n;
	cin>>n;
	if(n<=2)
		cout<<"No\n";
	else
	{	vector<int> a,b;
		int sum1=0,sum2=0;
		for(int i=1;i<=n;i+=2)
		{	a.pb(i);
			sum1+=i;
		}
		for(int i=2;i<=n;i+=2)
		{	b.pb(i);
			sum2+=i;
		}
		cout<<"Yes\n";
		cout<<a.size()<<" ";
		f(i,0,a.size())
			cout<<a[i]<<" ";
		cout<<"\n";
		cout<<b.size()<<" ";
		f(i,0,b.size())
			cout<<b[i]<<" ";
		cout<<"\n";
		//cout<<gcd(sum1,sum2)<<endl;
	}
	return 0;
}
