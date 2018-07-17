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
bool isPrime(ll n)
{
    // Corner cases
    if (n <= 1)  return false;
    if (n <= 3)  return true;

    // This is checked so that we can skip 
    // middle five numbers in below loop
    if (n%2 == 0 || n%3 == 0) return false;

    for (ll i=5; i*i<=n; i=i+6)
        if (n%i == 0 || n%(i+2) == 0)
           return false;

    return true;
}
int main()
{	ll p,y;
	cin>>p>>y;
	ll i,j,flag=0;
	for(i=y;i>p;i--)
	{	flag=0;
		if(isPrime(i)==true)
		{	cout<<i<<endl;
			break;
		}
		else
		{	for(j=2;j<=p;j++)
			{	if(i%j==0)
				{	flag=1;
					break;
				}
			}
			if(flag==0)	
			{		cout<<i<<endl;
					break;
			}
		}
	}
	if(i<=p)
	{	cout<<"-1\n";
	}
	return 0;
}
