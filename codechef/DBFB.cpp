/****************************
* AUTHOR:      b_506				*
* INSTITUTION: MNIT JAIPUR  *
****************************/
 
#include<iostream>
#include<string>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<cctype>
#include<algorithm>
#include<climits>
#include<queue>
#include<list>
#include<map>
 
using namespace std;
 
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<string> vs;
#define f(i,a,n) for(ll i=a;i<n;i++)
#define fr(i,a,n)	for(i=n-1;i>=a;i--)
#define mod 1000000007
#define PI	3.141516
#define NIL -1
#define INF 1000000000000000000
ll mulmod(ll a, ll b)
{
    ll res = 0; 
    a = a % mod;
    while (b > 0)
    {
        // If b is odd, add 'a' to result
        if (b % 2 == 1)
            res = (res + a) % mod;
 
        // Multiply 'a' with 2
        a = (a * 2) % mod;
 
        // Divide b by 2
        b /= 2;
    }
 
    // Return result
    return res % mod;
}
 
int main()
{	ll t;
	cin>>t;
	while(t--)
	{	ll m,n,x;
		cin>>m>>n;
		ll a[m];
		ll i,j,bsum=0,k,asum=0;
		for(i=0;i<m;i++)
		{	cin>>a[i];
			a[i]=mulmod(a[i],m);
			asum+=a[i];
			asum%=mod;
		}
		for(i=0;i<m;i++)
		{	cin>>x;
			bsum+=x;
			bsum%=mod;
		}
		bsum=mulmod(bsum,m);
		//sort(a,a+m);
		ll size,acount=0;
		if(2>n)
			size=2;
		else
			size=n;
		ll f[size],ad=0,r=0;
		f[0]=asum;
		f[1]=bsum;
		for(k=2;k<n;k++)
		{	f[k]=f[k-1]+f[k-2];
			f[k]%=mod;
		}
		cout<<f[n-1]%mod<<endl;
	}
	return 0;
}
