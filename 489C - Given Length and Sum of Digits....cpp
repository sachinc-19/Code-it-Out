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
     /* int t;
	  cin>>t;
     while(t--)
    {
     
	 }*/
	 
	 int m,sum;
	 cin >> m >> sum;
	 if(sum==0&&m==1)
	 {
	 	cout<<"0 "<<"0";
	 	return 0;
	 }
	 if(sum==0)
	 {
	 	cout<<"-1 "<<"-1";
	 	return 0;
	 }
	  if(sum>9*m)
	    {
	    	cout<<"-1 "<<"-1";
	    	return 0;
		}
	 int mx[m] = {0};
	 int mn[m] = {0};
	 
	 mn[0] = 1;
	 int s=sum;
	 for(int i=0 ; i<m; i++)
	 {
	 	
	 	if(s>=9)
	 	{
		 mx[i]=9 ;
		 s-=9;
		 }
		else
		  {
		  	mx[i]+=s;
		  	s=0;
		  	break;
		  }
	 }
	 s=sum-1;
	 for(int i=m-1; i>=0; i--)
	 { 
	    if(s>=9)
	    {
	    	mn[i]+=9; 
	    	s-=9;
		}
		else
		{
			mn[i]+=s;
			s=0;
			break;
		}
	 }
	 forn(m)
	 {
	 	cout<<mn[i];
	 }
	 cout<<" ";
	 forn(m)
	 cout<<mx[i];
	return 0;
}	
