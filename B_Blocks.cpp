#include<bits/stdc++.h>
using namespace std;
//include <ext/pb_ds/assoc_container.hpp>
//include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define ll long long int
#define fon(i,n) for(int i=0;i<n;i++)
#define fo(i,n) for(int i=1;i<=n;i++)
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define pii pair<int,int>
#define pll pair<ll ,ll>
#define vii vector<int>
#define vll vector<ll>
#define vvll vector<vll>
#define vpii vector<pii>
#define vpll vector<pll>
#define bs binary_search
#define lb lower_bound
#define ub upper_bound
#define M (1000*1000*1000+7)
#define test ll T; cin>>T; while(T--)
#define all(z) z.begin() , z.end()
#define allr(z) z.rbegin() , z.rend()
#define memo(oo) memset(oo , -1 , sizeof(oo))
// =============================================
//1.integer overflow (1e5 * 1e5) (2e9 + 2e9)
 
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   int n;
   cin >> n;
   string s;
   cin >> s;
   
   vii v;
   int black = 0 , white = 0;
   char c;
   for(int i = 0 ; i< n; i++)
       if(s[i]=='B') black++;
       else white++;
   if(black == n || white == n)
   {
       cout << "0" << endl;
       return 0;
   }
   else if(black % 2==0) c = 'B';
   else if(white % 2==0) c = 'W';
   else 
   {
       cout << "-1" << endl;
       return 0;
   }
   for(int i = 0 ; i < n-1; i++)
      if(s[i]==c){
          if(s[i+1]==c)
              if(c=='B')
                  s[i] = s[i+1] = 'W';
              else
                  s[i] = s[i+1] = 'B';
          else
              swap(s[i] , s[i+1]);
          v.emplace_back(i+1);
      }
    cout << v.size() << endl;
    for(auto i : v) cout << i << " ";
    cout << endl;
   
}