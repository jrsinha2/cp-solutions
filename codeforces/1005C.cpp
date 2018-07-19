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
	int c=0;
	int mx=INT_MIN;
	unordered_map<int,int> m1,m;

	f(i,0,n)
	{	cin>>a[i];
		mx=max(a[i],mx);
		if(m.find(a[i])==m.end())
		{	m[a[i]]=0;
			m1[a[i]]=0;
		}
		m1[a[i]]++;
		m[a[i]]++;
	}
	sort(a,a+n);
	bool yes[n];
	memset(yes,0,sizeof(yes));
	if(n==0)
		cout<<n<<"\n";
	else if(n==1)
		cout<<n<<endl;
	else
	{	for(int i=0;i<n;i++)
		{	if(m[a[i]]!=0)
			{	int a1=a[i];
				//cout<<a[i]<<" ";
				int b=(int)log2(a[i]);
				//cout<<b<<" ";
				for(int i=b+1;i<=log2(2*mx)+1;i++)
				{	int sum=(int)pow(2,i);
					int a2=sum-a1;
					//cout<<a2<<" ";
					if(m.find(a2)!=m.end())
					{	if(a2!=a1)
						{	m1[a2]--;
							m1[a1]--;
							//cout<<a2<<"\n ";
							break;
						}
						else if(a2==a1 && m[a2]>=2)
						{	m1[a1]-=2;
							//cout<<a1<<"\n ";
							break;
						}
					}
				}
			}
		}
	
	f(i,0,n)
	{	if(m1[a[i]]>0)
			c++;
	}
	cout<<c<<endl;
	}
	return 0;
}
				
			
