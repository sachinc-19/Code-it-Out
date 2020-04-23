#include<bits/stdc++.h>
using namespace std;
using std::cout;
using std::endl;
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
      int n1, n2 ,n3,a,count=0;
      std::map<int,int> fmp;
      cin>>n1 >>n2 >>n3;
      vector<int>v;
      forn(n1)
       { 
        cin>>a;
        fmp[a]++;
	   }
	   
       forn(n2)
       {
    	cin>>a;
        fmp[a]++;
    	}
    	
    	forn(n3)
    	{
		cin>>a;
		fmp[a]++;
     	}
     	for(std::map<int,int>::iterator it=fmp.begin(); it!=fmp.end(); ++it)
     	{
     		if(it->second>=2)
     		{
     			v.pb(it->first);
     			count++;
     		}
			 
		 }
		 cout<< count <<endl;
		 for(int i=0;i<v.size();++i)
		   cout<<v[i]<<endl;
	return 0;
}	
