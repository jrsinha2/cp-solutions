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
{	double k,d,t;
	cin>>k>>d>>t;
	double time;
	ll stove=floor(t/k);
	ll still=t-(floor(t/k)*k);
	if(k>=d)
	{	if(k-(floor(k/d)*d)==0)
		{	time=stove*k;
			time+=still;
		}
		else
		{	ll quo=floor(k/d);
			double rem=((quo+1)*d)-k;
			double fac=k+rem/2;
			//printf("%lf\n",fac);
			ll quo1=t/fac;
			//cout<<quo1<<endl;
			time=(quo1*(k+rem));
			//printf("%.9lf\n",time);
			//ll rema=t/fac;
			//cout<<rema<<endl;
			t=(double)((double)t-(double)(fac*quo1));
			//printf("%lf",(double)t);
			if(t>k)
			{	time+=k;
				t-=k;
				if(t>0)
				{	time+=(2*t);
				}
			}
			else
				time+=(t);
		}
	}
	else
	{	double fac=k+(d-k)/2;
		//printf("%lf\n",fac);
		ll quo1=floor(t/fac);
		//cout<<quo1<<endl;
		time=(d*quo1);
		t=(t-(quo1*fac));
		if(t>k)
		{	time+=k;
			t-=k;
			if(t>0)
			{	time+=(2*t);
			}
		}
		else
			time+=(t);
	}
	printf("%.1lf\n",time);
}
