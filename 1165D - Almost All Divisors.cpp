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
	int n, lcm;
	cin >> n;
	int a[n];
	forn(n)
	{
		cin >> a[i];
	}
	if(n==1)
	{	
	cout << sq(a[0]) << endl;
	return;
    }
	int gcd = a[0];
	for(int i=1 ; i<n ; i++ )
	{
		gcd = __gcd(gcd,a[i]);
		lcm = a[i-1]*a[i]/gcd;
		//temp = gcd;
	}
	cout << gcd * lcm << endl;
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
      int t;
	  cin>>t;
     while(t--)
    {
     solve();
	
	 }

	return 0;
}	
