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
    string s[n];
    fon(i , n)
     cin >> s[i];
    vpii v;
    for(int i = 0 ; i < n;i++)
    {
        for(int j = 0 ; j < n; j++)
        {
            if(s[i][j] == '*')
            {
                v.eb(i , j);
            }
        }
    }
    v.eb(v[0]);
    v.eb(v[1]);

    if(v[0].ff == v[1].ff) // row same
    {
        // find some new row corresponding to the previous one
        v[2].ff = (v[2].ff+1) % n;
        v[3].ff = (v[3].ff+1) % n;
    }
    else if(v[0].ss == v[1].ss) // same column
    {
        // find some next column
        v[2].ss = (v[2].ss + 1) % n;
        v[3].ss = (v[3].ss + 1) % n;
    }
    else 
    {
        swap(v[2].ff , v[3].ff);
    }
    
    s[v[2].ff][v[2].ss] = '*';
    s[v[3].ff][v[3].ss] = '*';
    
    fon(i , n)
    {
        fon(j , n)
            cout << s[i][j] ;
        cout << endl;
    }
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   test
   {
      solve();
   }
}