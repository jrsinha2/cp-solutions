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
#define MOD 1000000007
#define PI	3.141516
#define NIL -1 
ll n,k1,k2,zr;
ll a[1001],b[1001];
priority_queue<ll>pq;
 
int main(){
	cin>>n>>k1>>k2;
	for (ll i=0;i<n;i++) 
		cin>>a[i];
	for (ll i=0;i<n;i++) 
		cin>>b[i];
	for (ll j = 0; j < k1; j++)
	{
		ll temp = -1;
		ll index = -1;		
		for (ll i=0;i<n;i++) 
		{
			if (abs(a[i]-b[i]) < temp) 
				continue;
			temp = abs(a[i]-b[i]);
			index = i;
		}
		if (a[index] > b[index]) 
			a[index]--;
		else 
			a[index]++;
	}
 	for (ll j = 0; j < k2; j++){
		ll temp = -1;
		ll index = -1;		
		for (ll i=0;i<n;i++) {
			if (abs(a[i]-b[i]) < temp) 
				continue;
			temp = abs(a[i]-b[i]);
			index = i;
		}
		if (a[index] > b[index]) b[index]++;
		else b[index]--;
	}
 
	ll sum = 0;
	for (ll i=0;i<n;i++){
		sum += (a[i]-b[i]) * (a[i]-b[i]);
	}
	cout<<sum<<endl;
}
