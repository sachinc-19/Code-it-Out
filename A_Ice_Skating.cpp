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
 
int a[1001][1001];
void solve()
{
    int n;
    cin >> n;
    // cout << n << endl;
    memo(a , -1);
    fon(i , n)
    {
        int x , y;
        cin >> x >> y;
        a[x][y] = -1;
        for(int j = 0 ; j < 1001 ; j++){
            if(a[x][j] == -1) continue;
            a[x][j]++;
        }
        for(int k = 0 ; k < 1001 ; k++){
            if(a[k][y] == -1) continue;
            a[k][y]++;
        }
    }
    vector<bool>vis(1010 , false);
    int ans = 0;
    for(int i = 0 ; i < 1010 ; i++)
    {
        int mx = INT_MIN;
        int y = -1;
        for(int j = 0; j < 1010 ; j++)
        {
           if(vis[j] || a[i][j] == -1) continue;
           if(a[i][j] > mx)
           {
               mx = a[i][j];
               y =j;
           }
        }
        if(y != -1)
        {
            vis[y] = 1;
            ans++;
        }
    }
    cout << ans << endl;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
      solve();
    // cout << "2";
}