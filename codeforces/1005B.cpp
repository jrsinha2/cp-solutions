#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define f(i,a,n) for(int i=a;i<n;i++)
#define mod 1000000007
int main()
{	string a,b;
	cin>>a>>b;
	int n1=a.length();
	int n2=b.length();
	int c=0;
	bool ok=true;
	int i=n1-1,j=n2-1;
	for(;i>=0 && j>=0; )
	{	if(a[i]==b[j])
		{	//cout<<a[i];
			i--;
			j--;
			
		}
		else
		{	//ok=false;
			break;
		}
	}
	cout<<i+j+2<<endl;
	return 0;
}	
