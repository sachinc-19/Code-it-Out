#include<bits/stdc++.h>
using namespace std;
const int N=1010;
typedef long long int ll;
#define forn(n) for(int i=0;i<n;i++)
#define f(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
#define mp make_pair
#define sz(a) a.size()
#define mod (1000*1000*1000+7)
#define pi (22/7.0)
#define sq(x) x*x

void solve()
{
	int n , b ,a,j;
	cin >>n >> b>>a;
	
	int s[n];
	forn(n)
	 cin>>s[i];
	int x=a;
	for(j=0 ; j<n ; j++)
	{
		if(a==0&&b==0)
		{
			cout<<j;
			return;
		}
		if(s[j]==0)
		{
			if(a>0)
			 a--;
			else
			 b--;
			 
		}
		else
		{
			if(b>0&&a<x)
			  {
			  	a++;
			  	b--;
			  }
			else
			  a--;
		}
	}
	cout<<j;
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
     solve();
	

	return 0;
}	
