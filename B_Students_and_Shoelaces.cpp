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
#define memo(oo , zz) memset(oo , zz , sizeof(oo))
// =============================================
//1.integer overflow (1e5 * 1e5) (2e9 + 2e9)
 
void solve()
{
    int n , m;
    cin >> n >> m;
    vii adj[n+2];
    fon(i , m)
    {
        int u , v;
        cin >> u >> v;
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }
    bool f = true;
    int ans = 0;
    while(f)
    {
        f = false;
        vii tmp[n+1];
        for(int i = 1 ; i <= n; i++)
        {
            sort(all(adj[i]));
            if(adj[i].size() == 1)
            {
               int u = i;
               int v = adj[i].back();
               adj[i].pop_back();
               tmp[v].pb(u);
               f = true;
            }
        }
        for(int i = 1 ; i <= n; i++)
        {
            for(int j = 0 ; j < tmp[i].size() ; j++)
            {
                if(find(all(adj[i]) , tmp[i][j]) != adj[i].end())
                 adj[i].erase(find(all(adj[i]) , tmp[i][j]));
            }
        }
        if(f) ans++;
    }
    cout << ans << endl;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
      solve();
}