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
      int t;
	  cin>>t;
     while(t--)
    {
      map<string,int> mp;
      int n;
      cin>>n;
        string s;
      forn(n)
      {	
      
         cin>>s;
        std::map<string ,int >::iterator itr=mp.find(s);
         if(itr!=mp.end())
         {
         	cout<<s<<++itr->second<<endl;
		 }
         else 
        {
         cout<<"OK"<<endl;
         mp.insert({s,0});
        }
 }
         
	
	 }

	return 0;
}	
