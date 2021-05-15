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
    long double h , k , r;
   //  cin >> h >> k >> r;
    scanf("%Lf%Lf%Lf" , &h , &k , &r);
    r += 1e-14;
    ll ans = 0;
    for(ll x = ceil(h-r) ; x <= floor(h+r) ; x++)
    {
       long double val = r*r - (x-h)*(x-h);
       long double ys = k - sqrt(val);
       long double ye = k + sqrt(val);
       ans += floor(ye)- ceil(ys) + 1;
    }
   //  cout << ans << endl;
   printf("%lld\n" , ans);
}
int main()
{
   // ios_base::sync_with_stdio(false);
   // cin.tie(NULL);
    solve();
}