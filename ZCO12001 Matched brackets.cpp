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
	int n ,ans=0; 
	int mx=0,pos=1;
	cin >> n;
	int a[n+1];
	a[0]=0;
	for( int i=1; i<=n ; i++)
	{
		cin>> a[i];
	}
	
	int nsd=0,firstpos=0,maxsq=0,maxpos;
	for(int i=1;i<=n; i++){
		
	/*	if(ans==0)
		{
			mx=0;
			pos =i;
		}*/
		if(a[i]==1){
			
		   ans++;
		   mx++;
		   if(nsd<ans)
		   {
		   	nsd = ans;
		   	firstpos = i;
		   }
    	}
    	else 
		{
    		ans-=1;
    		mx++;
	    	}
	    	
		 if(ans==0) 
		 {                 //second subtask
		    if(maxsq<mx){
			maxsq=mx;
			maxpos=pos;
	    	}
			mx=0;
			pos = i+1;
		}                 // completed
	
		 
	}
	cout << nsd <<" "<< firstpos  <<" "<< maxsq <<" "<< maxpos;
 } 
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    solve();

	return 0;
}	
