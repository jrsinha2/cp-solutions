#include<iostream>
#include<string>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<climits>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
#define f(i,a,n) for(ll i=a;i<n;i++)
#define fr(i,a,n)	for(i=n-1;i>=a;i--)
#define MAX 1000000007
#define PI	3.141516
int main()
{	ll n,pos,l,r;
	cin>>n>>pos>>l>>r;
	ll c=0;
	if(pos>l && pos<r)
	{	if(l>1 && r<n)
		{	c+=min(pos-l,r-pos);
			c++;
			c+=r-l;
			c++;
		}
		else 
		{	if(l>1 && r==n)
			{	c+=pos-l;
				c++;
			}
			else if(l==1 && r<n)
			{	c+=r-pos;
				c++;
			}
		}
	}
	else if(pos>=l && pos>=r)
	{	if(r<n){
		c+=pos-r;
		c++;
		}
		if(l>1)
		{	c+=r-l;
			c++;
		}
	}
	else if(pos<=l && pos<=r)
	{	if(l>1){
		c+=l-pos;
		c++;
		}
		if(r<n)
		{	c+=r-l;
			c++;
		}
	}
	cout<<c;
	return 0;
}
