#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define forn(n) for(int i=0;i<n;i++)
#define f(a,b) for(int i=a;i<=b;i++)
#define vi vctor<int>
#define vl vector<ll>
#define pb push_back
#define mp make_pair
#define mod (1000*1000*1000+7)
#define pi (22/7.0)
#define sq(x) x*x
#define test ll t; cin>>t; while(t--) 
vl v;
void LN_list(ll num, int four , int seven)
{
	if(four==seven)
	  v.pb(num);
	  
	if(num>(ll)1000000000)
	 return;
     LN_list(num*10+4,four+1,seven);
     LN_list( num*10+7, four , seven+1);
    
}

void solve()
{
  
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	LN_list(0, 0 ,0);
      
	  ll x;
	  cin >>x;
	  sort(v.begin(),v.end());
	  
	 std::vl::iterator it = lower_bound(v.begin(), v.end(),x);
	 // my = lower_bound(v.begin(), v.end(),x)-v.begin();
	 // cout<<my<<endl;
	 cout << *it<<endl;
	 
	   
}
