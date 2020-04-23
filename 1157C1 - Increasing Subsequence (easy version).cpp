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
    //vector<int>v;
    int n;
    cin>>n;
    int a[n];
    string s;
    forn(n)
    {
        cin>>a[i];
    }
    int l=0,r=n-1,top=0;
    
    while(l<=r)
    {
        vector<pair<int , char>> pair;
        
        if(top < a[l]) pair.pb(mp(a[l],'L'));
    
        if(top < a[r]) pair.pb(mp(a[r],'R'));
        
        sort(pair.begin(), pair.end());
        
        if(pair.size()==2)
         pair.pop_back();
        
        if(pair.size()==1)
         {
             if(pair[0].second=='L')
             {
                s+='L';
                top = a[l];
                ++l;
             }
             else
             {
                s+='R';
                top = a[r];
                r--;
             }    
         }
         
        else
          break;
 
    }
    cout << s.length() << endl;

    cout << s << endl;
    
    return;    
    
}
int main()
{
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
       

	 solve();

	return 0;
}	
