/****************************
* AUTHOR:      b_506			 	*
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
int main()
{	ll n;
	cin>>n;
	ll x;
	ll i;
	ll stack[100000];
	ll top=-1;
	ll lvl=0,lpos=0,chrs=0,chrpos=0,maxlvl=0,maxlpos=0,maxchrs=0,maxchrpos=0;
	for(i=1;i<=n;i++)
	{	cin>>x;
		if(i==0)
		{	stack[++top]=x;
			lvl=top+1;
			
			//lpos=i;
			lpos=i;
			chrpos=i;
			chrs++;
			if(lvl>maxlvl)
			{	maxlvl=lvl;
				maxlpos=lpos;
				//maxchrs=chrs;
				//maxchrpos=chrpos;
			}
			if(chrs>maxchrs && lvl==maxlvl)
			{	maxchrs=chrs;
				maxchrpos=chrpos;
			}
			//cout<<i<<" "<<lvl<<" "<<lpos<<" "<<chrs<<" "<<chrpos<<endl;
		}
		else
		{	if(x==1)
			{	if(top>-1 && stack[top]==1)
				{	stack[++top]=x;
					if(top+1>lvl)
						lvl=top+1;
					chrs++;
					lpos=i;
					if(lvl>maxlvl)
					{	maxlvl=lvl;
						maxlpos=lpos;
						//maxchrs=chrs;
						//maxchrpos=chrpos;
					}
					if(chrs>maxchrs && lvl==maxlvl)
					{	maxchrs=chrs;
						maxchrpos=chrpos;
					}
					//cout<<i<<" "<<lvl<<" "<<lpos<<" "<<chrs<<" "<<chrpos<<endl;
				}
				else if(top==-1)
				{	stack[++top]=x;
					lvl=top+1;
					chrpos=i;
					chrs++;
					lpos=i;
					if(lvl>maxlvl)
					{	maxlvl=lvl;
						maxlpos=lpos;
						//maxchrs=chrs;
						//maxchrpos=chrpos;
					}
					if(chrs>maxchrs && lvl==maxlvl)
					{	maxchrs=chrs;
						maxchrpos=chrpos;
					}
					//cout<<i<<" "<<lvl<<" "<<lpos<<" "<<chrs<<" "<<chrpos<<endl;
				}
			}
			else if(x==2 && stack[top]==1)
			{	top--;
				chrs++;
				if(chrs>maxchrs && lvl==maxlvl)
				{	maxchrs=chrs;
					maxchrpos=chrpos;
				}
				if(top==-1)
				{	//cout<<i<<" "<<lvl<<" "<<lpos<<" "<<chrs<<" "<<chrpos<<endl;
					lvl=0;
					chrs=0;
				}
				//else
					//cout<<i<<" "<<lvl<<" "<<lpos<<" "<<chrs<<" "<<chrpos<<endl;
			}
		}
	}
	cout<<maxlvl<<" "<<maxlpos<<" "<<maxchrs<<" "<<maxchrpos<<endl;
	return 0;
}

	
	
