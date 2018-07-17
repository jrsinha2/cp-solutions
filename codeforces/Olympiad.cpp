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
{	ll n;
	cin>>n;
	ll a[n];
	ll i=0;
	for(i=0;i<n;i++)
		cin>>a[i];
	sort(a,a+n);
	ll c=n;
	if(a[0]==0)
		c--;
	for(i=1;i<n;i++)
	{	if(a[i]==0)
			c--;
		else if(a[i]==a[i-1])
			c--;
	}
	cout<<c<<endl;
	return 0;
}
