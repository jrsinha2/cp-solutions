#include<bits/stdc++.h>
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
#define H 0.000001
typedef struct car
{	double v;
	ll d;
	double p;
	double c;
}ob;
bool vicinity(double c,double p,double t,double v,ll d)
{	if(d==1)
	{	if(p+v*t<-H)
			return false;
		else if(p-c>H)
			return false;
	}
	else
	{	if(p-v*t>H)
			return false;
		else if(p+c<-H)
			return false;
	}
	return true;
}
		
int main()
{	ll t;
	cin>>t;
	while(t--)
	{	ll n,s,y;
		cin>>n>>s>>y;
		struct car a[n];
		ll i;
		for(i=0;i<n;i++)
		{	cin>>a[i].v;
		}
		for(i=0;i<n;i++)
		{	cin>>a[i].d;
		}
		for(i=0;i<n;i++)
		{	cin>>a[i].p;
		}
		for(i=0;i<n;i++)
		{	cin>>a[i].c;
		}
		double time=0.0;
		double chef=(double)y/(double)s;
		double timec=0.0;
		double timel=0.0;
		bool wait=false;
		for(i=0;i<n;i++)
		{	wait=false;
			if(a[i].d==1)
			{	a[i].p+=(a[i].v*time);
			}
			else
				a[i].p-=(a[i].v*time);
			//printf("position =%lf\n",a[i].p);
			if(a[i].d==1)
			{	
				timec=(H-(a[i].p-a[i].c))/a[i].v;
				//cout<<vicinity(a[i].c,a[i].p,chef,a[i].v,a[i].d)<<endl;
				if(vicinity(a[i].c,a[i].p,chef,a[i].v,a[i].d)==true)
				{	time+=timec;
					wait=true;
				}
				else
					time+=chef;
			}
			else if(a[i].d==0)
			{	timec=((a[i].p+a[i].c)+H)/a[i].v;
				//cout<<vicinity(a[i].c,a[i].p,chef,a[i].v,a[i].d)<<endl;
				if(vicinity(a[i].c,a[i].p,chef,a[i].v,a[i].d)==true)
				{	time+=timec;
					wait=true;
				}
				else
					time+=chef;
			}
			if(wait==true)
				time+=chef;
			//printf("%.6lf\n",time);
		}
		printf("%.6lf\n",time);
	}
	return 0;
}
			
