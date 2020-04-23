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
 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
      int h , ps=0 , x;
      ll n;
      cin>>n>>h;
      ll a[n];
      vector<int>v ;
      forn(n)
      cin>>a[i];
      
      while(1)
      {
      	cin>>x;
      	if(x==0)
      	 break;
      	v.pb(x);
	  }
      int box=0;
      for(int i=0 ; i<v.size(); i++)
      {
      	if(v[i]==1&&ps!=0)
      	  ps--;
      	else if(v[i]==2&&ps!=n-1)
      	       ps++;
      	     else if(v[i]==3&&a[ps]!=0&&box==0)
      	          {
      	            a[ps]-=1;
      	            box = 1;
      	          }
      	       else if(v[i]==4&&a[ps]!=h&&box==1)
      	             {
      	             	a[ps]+=1;
      	             	box = 0;
					   }
					   else 
					   continue;
	  }
	  forn(n)
	   cout << a[i] << " ";
	return 0;
}	
