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
    vii a(n) , b(n-1) , c(n-2);
    fon(i , n)
        cin >> a[i];
    fon(i , n-1){
        cin >> b[i];
    }
    fon(i , n-2){
        cin >> c[i];
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    int ans1 = -1  , ans2 = -1;
    fon(i , n-1)
    {
        if(a[i] != b[i]){
            ans1 = a[i];
            break;
        }
    }
    if(ans1 == -1) ans1 = a[n-1];
    fon(i , n-2)
    {
        if(c[i] != b[i]){
            ans2 = b[i];
            break;
        }
    }
    if(ans2 == -1) ans2 = b[n-2];
    cout << ans1 << endl;
    cout << ans2 << endl;   
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
      solve();
}