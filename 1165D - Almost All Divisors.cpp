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

void All_divisors(ll x,vl &v)
{

	for(ll i=2;i<=sqrt(x);i++)
	{
	   if(x%i==0)
	   {
	   	if(x/i==i)
	       v.pb(i);
	     else
	      {
	     	v.pb(i);
	       v.pb(x/i);
	      }
       }
    } 
}  
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
      test
    { 
       vl v;
       
	   ll n,flag=1;
	   cin>>n;
	   vl d;
	   
	   for(ll i=0;i<n;i++)
	   {
	   	ll z;
	   	cin>>z;
	   	d.pb(z);
	   }
	   
	   sort(d.begin(),d.end());
	   
	   ll x = d[0]*(ll)d[n-1];
	   
	     All_divisors(x,v);
	     
	    sort(v.begin(),v.end()); 
	    if(v.size()!=n)
	    { 
	      flag=0;
		}
	 /*  for(ll i=0;i<n;i++)
	   {
	   	  if(v[i]!=d[i])
	   	  {
			flag=0;
		  }
	   } */
	   if(v!=d)
	    flag=0;
	    
	   if(flag)
	   cout<<x<<endl;
	   else
	   cout<<"-1"<<endl;
	}
}	
