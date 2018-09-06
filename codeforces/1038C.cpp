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
	priority_queue<ll> m1,m2;
	ll a[n],b[n];
	f(i,0,n)
	{	cin>>a[i];
		m1.push(a[i]);
	}
	f(i,0,n)
	{	cin>>b[i];
		m2.push(b[i]);
	}
	ll ch=0;
	ll c1=0,c2=0;
	while(!m1.empty() || !m2.empty())
	{	if(ch==0)
		{	if(!m2.empty())
			{	if(!m1.empty())
				{	if(m1.top()>m2.top())
					{	c1+=m1.top();
						m1.pop();
					}
					else
					{	m2.pop();
					}
				}	
				else
				{	m2.pop();
				}
			}
			else
			{	c1+=m1.top();
				m1.pop();
			}
			ch=1-ch;
		}
		if(ch==1)
		{	if(!m1.empty())
			{	if(!m2.empty())
				{	if(m2.top()>m1.top())
					{	c2+=m2.top();
						m2.pop();
					}
					else
					{	m1.pop();
					}
				}
				else
				{	m1.pop();
				}
			}
			else
			{	c2+=m2.top();
				m2.pop();
			}
			ch=1-ch;
		}
	}
	cout<<c1-c2<<endl;
	return 0;
	
}
