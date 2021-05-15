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
// ===================================================================

// *1500
// binary search and two pointers always come together in a problem
void solve()
{
    ll n , m;
    cin >> n >> m;
    vll a(n) , b(m); //1. data structure
    set<ll> s;
    fon(i , n) cin >> a[i];
    fon(i , m)
    {
        ll x;
        cin >> x;
        s.insert(x);
    }
    // if i have to delelte the same occurences and want to find the lower bound and 
    // Some element less than lower bound then use the set data structure cool...

    int i = 0 , j = 0; // 2. two pointer
    ll ans = 0 , dis;
    // 3. implementation

    fon(i , n)
    {
        // 4. binary search
        auto it = s.lb(a[i]);
        dis = 1e17;
        if(it != s.end()) // true means right tower exist for current city
          dis = abs(a[i] - *it);  // distance of nearest tower to right
        if(it != s.begin()){  // true means left tower exist for current city
            it--;
            dis = min(dis , abs(a[i] - *it)); // distance of nearest tower to left
        }
        ans = max(ans , dis);
    }
   cout << ans << endl;
}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
      solve();
}