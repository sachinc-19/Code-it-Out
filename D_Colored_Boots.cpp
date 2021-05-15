                               // CPP
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
#define eb emplace_back
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
#define memo(oo , zz) memset(oo , zz , sizeof(oo))
// =============================================
//1.integer overflow (1e5 * 1e5) (2e9 + 2e9)
 
void solve()
{
    int n;
    cin >> n;
    string s1 , s2;
    cin >> s1 >> s2;
    map<char , vii> m1 , m2;
    fon(i ,n)
    {
       m1[s1[i]].pb(i+1);
    }
    vpii ans;
    fon(i , n)
    {
        if(s2[i] == '?'){
            m2[s2[i]].pb(i+1);
            continue;
        }
        if(m1.find(s2[i]) != m1.end())
        {
            ans.eb(m1[s2[i]].back() , i+1);
            m1[s2[i]].pop_back();
            if(m1[s2[i]].size() == 0) {
                m1.erase(s2[i]);
            }
        }
        else{
            m2[s2[i]].pb(i+1);
        }
    }

    for(auto i : m2)
    {
        if(i.ff == '?') continue;
       while(i.ss.size() > 0 && m1['?'].size()> 0)
       {
          ans.eb(m1['?'].back() , i.ss.back());
          i.ss.pop_back();
          m1['?'].pop_back();
       }
      if(m1['?'].size() == 0) break;

    }
    for(auto i : m1)
    {
        if(i.ff == '?') continue;
       while(i.ss.size() > 0 && m2['?'].size() > 0)
       {
          ans.eb(i.ss.back() , m2['?'].back());
          i.ss.pop_back();
          m2['?'].pop_back();
       }
       if(m2['?'].size() == 0) break;
    }
    while(m1['?'].size() &&  m2['?'].size())
    {
        ans.eb(m1['?'].back() , m2['?'].back());
                  m1['?'].pop_back();
                            m2['?'].pop_back();
    }
    cout << ans.size() << endl;
    for(auto i : ans) cout << i.ff << " " << i.ss << endl;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
      solve();
}