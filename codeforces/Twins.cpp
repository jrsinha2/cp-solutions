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
void insertionSort(ll arr[], ll n)
{
   ll i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
int main()
{	ll n;
	cin>>n;
	ll a[n],sum=0;
	f(i,0,n)
	{	cin>>a[i];
		sum+=a[i];
	}
	insertionSort(a,n);
	sum=sum/2;
	ll c=0,temp=0;
	for(ll i=n-1;i>=0;i--)
	{	if(temp<=sum)
		{	temp+=a[i];
			c++;
		}
	}
	cout<<c;
	return 0;
}
