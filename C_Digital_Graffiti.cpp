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
 
int h , w;
string s[20];
void solve()
{
    cin >> h >> w;
    fon(i , h) cin >> s[i];
    int a[h][w];
    int ans = 0;
    for(int i = 0 ; i < h ; i++)
        for(int j = 0 ; j < w ; j++)
           a[i][j] = (s[i][j] == '#');

    for(int i = 0 ; i < h-1 ; i++)
    {
        for(int j = 0 ; j < w-1 ; j++)
        {
            int x = a[i][j] + a[i+1][j+1] + a[i+1][j] + a[i][j+1];
            if(x%2) ans++;
        }
    }
    cout << ans << endl;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
//    test
//    {
//    }
      solve();
}