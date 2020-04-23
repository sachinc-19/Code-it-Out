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
    ll n,k,mid;
    cin>>n>>k;
    
    mid = ceil(n/2.0);
    
    if(k<=mid)
    {
        cout<<(ll)2*k-1<<endl;
        
    }
    else
        cout<<(ll)2*(k-mid)<<endl;
        
    return;    
    
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
     /* int t;
	  cin>>t;
     while(t--)
    {
     
	
	 }*/
	 solve();

	return 0;
}	
