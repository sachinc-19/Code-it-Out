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
#define memo(oo , cc) memset(oo , cc , sizeof(oo))
// =============================================
//1.integer overflow (1e5 * 1e5) (2e9 + 2e9)

const int MAXN = 400002;
vector<vii> adj_list(400002);
bool visited[MAXN];
int d[MAXN];
int ans = 0;
void dfs(int u)
{
    visited[u] = 1;
    ans = max(ans , d[u]);
    if(adj_list[u].size() > 0)
    {
        for(int i = 0 ; i < adj_list[u].size() ; i++ )
        {
            int v = adj_list[u][i];
            if(!visited[v])
            {
                d[v] = 1+d[u];
                dfs(v);
                ans = max(ans , d[v]);
            }
        }
    }
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
   
   int n;
   cin >> n;

   fon(i , n)
   {
       int u , v;
       cin >> u >> v;
       adj_list[u].pb(v);
       adj_list[v].pb(u);
   }

   // find the conected component
//    int ans = 0;
   for(int i = 1 ; i < 100 ; i++)
   {
       memo(d , 0);
       d[i] = 1;
       memo(visited , false);
       dfs(i);
    //    ans = max(ans , d);
   }
   cout << ans << endl;
}