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
#define MAX 100001
#define PI	3.141516
int main()
{	ll hh,m;
	cin>>hh>>m;
	ll h,d,c,n;
	cin>>h>>d>>c>>n;
	double part1=ceil((double)h/(double)n);
	part1*=c;
	ll t;
	if(hh<20)
	{	t=(19-hh)*60+60-m;
		t=t*d;
		h=h+t;
	}
	double part=ceil((double)h/(double)n);
	part=(part*c*80)/100;
	if(part1>part)
		printf("%lf",part);
	else
		printf("%lf",part1);
	return 0;
}
