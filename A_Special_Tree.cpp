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
 
vector<vii> adj_list;
vector<bool> vis;
int mat[2010][2010];
void dfs(int u , int v ,int x)
{
    vis[v] = true;
    mat[u][v] = x;
    for(int i = 0 ; i < adj_list[v].size() ; i++)
    {
       int d = adj_list[v][i];
       if(vis[d])
       {
           continue;
       }
       dfs(u , d , x+1);
    }
}
void solve()
{
    int n , k , a;
    cin >> n >> k >> a;
    adj_list.clear();
    adj_list.resize(n+1);
    vis.resize(n+1);
    memo(mat , 0);
    vii special(k);
    int mx = INT_MIN , mn = INT_MAX;
    fon(i , k)
    {
      cin >> special[i];
      mx = max(mx , special[i]);
      mn = min(mn , special[i]);
    }
    int cnt = 0;
    fo(i ,n-1)
    {
        int u , v;
        cin >> u >> v;
        adj_list[u].pb(v);
        adj_list[v].pb(u);
        if(u==i && v==i+1) cnt++;
    }
    vector<pair<int ,int>> ans(n+1);
    if(cnt == n-1)
    {
      for(int b = 1 ; b <= n; b++)
      {
          if(b < a)
          {
              ans[b].ff = abs(a-mn) - abs(b-mn);
              ans[b].ss = mn;
          }
          else if(b > a)
          {
              ans[b].ff = abs(a-mx) - abs(b-mx);
              ans[b].ss = mx;
          }
          else 
          {
              ans[b].ff  = 0;
              ans[b].ss = mx;
          }
        //   for(int i = 0 ; i < k ;i++)
        //   {
        //       int u = special[i];
        //       int d = abs(a-u) - abs(b-u);
        //       if(d > ans[b].ff)
        //       {
        //           ans[b].ff = d;
        //           ans[b].ss = u;
        //       }
        //   }
      }
    }
    else
    {
       fo(i , n)
       {
          fill(all(vis) , false);
          dfs(i , i , 0);
       }
       for(int b = 1 ; b <= n ; b++)
       {
           ans[b].ff = INT_MIN;
           ans[b].ss = -1;
           for(int i = 0 ; i < k ;i++)
           {
               int u = special[i];
               int d = mat[a][u] - mat[b][u];
               if(d > ans[b].ff)
               {
                   ans[b].ff= d;
                   ans[b].ss = u;
               }
           }
       }
    }
    fo(i , n) {
        cout << ans[i].ff << " ";
    }
    cout << endl;
    fo(i ,n){
        cout << ans[i].ss << " ";
    }
    cout << endl;

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