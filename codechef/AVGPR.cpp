#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{	ll t;
	ll x;
	cin>>t;
	while(t--)
	{	ll n;	
		cin>>n;
		vector<ll> a;
		unordered_map<ll,ll> m;   //fast map (only map will result in TLE in sone TC)
		for(int i=0;i<n;i++)
		{	cin>>x;
			if(m.find(x)==m.end())
			{	m[x]=0;
				a.push_back(x);
			}
			m[x]++;
		}
		ll ans=0;
		for(int i=0;i<a.size();i++)
		{	ans+=((m[a[i]]*(m[a[i]]-1))/2);
			for(int j=i+1;j<a.size();j++)
			{	if(m.find((a[i]+a[j])/2)!=m.end() && (a[i]+a[j])%2==0)
				{	ans+=(m[a[i]]*m[a[j]]);
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
} 
