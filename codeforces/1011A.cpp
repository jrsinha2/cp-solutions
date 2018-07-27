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
	char s[n];
	scanf("%s",s);
	sort(s,s+n);
	char prev;
	int ans=0,c=0;
	for(int i=0;i<n;i++)
	{	if(i==0)
		{	prev=s[i];
			ans+=((s[i]-'a')+1);	
			c++;
		}
		else
		{	if(c<k)
			{	if(s[i]-prev>=2)
				{	prev=s[i];
					c++;
					ans+=((s[i]-'a')+1);
				}
			}
			else
				break;
		}
	}
	if(c<k)
		cout<<"-1\n";
	else
	cout<<ans;
	return 0;
}
			
			
		
